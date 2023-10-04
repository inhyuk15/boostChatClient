#include <iostream>
#include <boost/asio.hpp>
#include <cstdlib>
#include "ChatMessage.hpp"

using boost::asio::ip::tcp;

constexpr int BUFF_SIZE = 32;

uint32_t getCurrentTimeStamp() {
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	auto duration = now.time_since_epoch();
	return std::chrono::duration_cast<std::chrono::seconds>(duration).count();
}

class Client {
public:
	Client(boost::asio::io_context& io_context, tcp::resolver::results_type& endpoints,
				 std::string nickname)
					: io_context_(io_context), endpoints_(endpoints), socket_(io_context),
					timeoutTimer_(io_context_), reconnectTimer_(io_context_), connected_(false)
					,nickname_(nickname) {
						setTimer();
						connect();
						
	}
	
	void close() {
		boost::asio::post(io_context_,  [this](){ socket_.close();});
		connected_.store(false);
	}
	
	void setTimer() {
		timeoutTimer_.expires_from_now(TIMEOUT_INTERVAL);
		timeoutTimer_.async_wait([this](const boost::system::error_code& ec) {
				if (!ec) {
						if (connected_.load()) {
							uint32_t timeoutTime = getCurrentTimeStamp();
								ChatMessage timeoutMessage("timeout", timeoutTime, chat::DataType::SYSTEM);
							timeoutMessage.setSystemCode(chat::TIMEOUT);
								write(timeoutMessage, true);
								std::cerr << "Timeout occurred. Closing connection." << std::endl;
						}
				}
		});
	}
	
	void resetTimer() {
			timeoutTimer_.cancel();
			setTimer();
	}
	
	void write(const ChatMessage& chatMessage, bool closeAfterWrite = false) {
		if (!connected_.load()) {
			startReconnectTimer();
		}
		resetTimer();
		auto sendBytes = chatMessage.encode();
		auto dataSize = std::make_shared<uint32_t>(static_cast<uint32_t>(sendBytes.size()));
		*dataSize = htonl(*dataSize);
		
		boost::asio::async_write(socket_, boost::asio::buffer(dataSize.get(), sizeof(*dataSize)),
														 [this, sendBytes, closeAfterWrite](boost::system::error_code ec, size_t) {
			if (!ec) {
				doWrite(sendBytes);
				if (closeAfterWrite) {
					std::cout << "im about to close" << std::endl;
					timeoutTimer_.expires_from_now(std::chrono::seconds(3000));
					close();
				}
			}
			else {
					std::cerr << "error in writing " << ec.message() << std::endl;
				close();
			}
		});
	}
	
	void doWrite(const std::string& sendBytes) {
		boost::asio::async_write(socket_, boost::asio::buffer(sendBytes), [this](boost::system::error_code ec, size_t) {
			if (!ec) {
				std::cout << "send body" << std::endl;
			} else {
					std::cerr << "error in writing " << ec.message() << std::endl;
				close();
			}
		});
	}
	
	
	void read() {
		if (!connected_.load()) {
			startReconnectTimer();
		}
		resetTimer();
		
		auto networkDataSize = std::make_shared<uint32_t>();
		boost::asio::async_read(socket_, boost::asio::buffer(networkDataSize.get(), sizeof(*networkDataSize)),
														[this, networkDataSize] (boost::system::error_code ec, std::size_t) {
			if (!ec) {
				doRead(ntohl(*networkDataSize));
			} else {
				std::cerr << "error in reading header" << std::endl;
				close();
			}
		});
	}
	
	void doRead(uint32_t networkDataSize) {
		auto binaryData = std::make_shared<std::string>(networkDataSize, '\0');
		boost::asio::async_read(socket_, boost::asio::buffer(*binaryData),
														[this, binaryData] (boost::system::error_code ec, std::size_t) {
			if (!ec) {
				ChatMessage chatMessage;
				chatMessage.decode(*binaryData);
				std::cout << "Username: " << chatMessage.getUserName() << std::endl;
				std::cout << "TimeStamp: " << chatMessage.getTimestamp() << std::endl;
				if (chatMessage.getDataType() == chat::TEXT) {
						std::cout << "Msg: " << chatMessage.getMessageText() << std::endl;
				}
				else {
					std::cout << "something else" << std::endl;
				}
				read();
			} else {
				std::cerr << "error in reading body" << std::endl;
				close();
			}
		});
	}
	
	void connect() {
		boost::asio::async_connect(socket_, endpoints_, [this](boost::system::error_code ec, tcp::endpoint) {
			if (!ec) {
				std::cout << "connection success! " << std::endl;
				connected_.store(true);
				read();
			} else {
				std::cerr << "error in connection: " << ec.message() << std::endl;
				close();
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				startReconnectTimer();
			}
		});
	}
	
	void startReconnectTimer() {
				reconnectTimer_.expires_from_now(RECONNECT_INTERVAL);
				reconnectTimer_.async_wait([this](const boost::system::error_code& ec) {
						if (!ec) {
								connect();
						}
				});
		}
	
	bool isConnected() const {
		return connected_.load();
	}
	
private:
	tcp::socket socket_;
	boost::asio::io_context& io_context_;
	tcp::resolver::results_type& endpoints_;
	
	std::atomic<bool> connected_{false};
	boost::asio::steady_timer timeoutTimer_;
	boost::asio::steady_timer reconnectTimer_;
	static constexpr std::chrono::seconds TIMEOUT_INTERVAL = std::chrono::seconds(10); // timeout 간격
	static constexpr std::chrono::seconds RECONNECT_INTERVAL = std::chrono::seconds(3); // 재연결 시도 간격

	
	std::string nickname_;
};


int main(int argc, const char * argv[]) {
	try {
		std::string port = "4000";
		std::string host = "localhost";
		
		boost::asio::io_context io_context;
		boost::asio::executor_work_guard<boost::asio::io_context::executor_type> work_guard =
				boost::asio::make_work_guard(io_context);
		
		tcp::resolver resolver(io_context);
		auto endpoints = resolver.resolve(host, port);
		
		
		std::cout << "Enter your nickname : ";
		std::string nickname;
		std::getline(std::cin, nickname);
		
		Client client(io_context, endpoints, nickname);
		
		std::thread t([&client, nickname]() {
			while(true) {
				while(!client.isConnected()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}
				std::string msg;
				std::getline(std::cin, msg);
				
				
				uint32_t timestamp = getCurrentTimeStamp();
				
				ChatMessage chatMessage(nickname, timestamp, chat::DataType::TEXT);
				chatMessage.setTextMessage(msg);
				
				client.write(chatMessage);
				
			}
		});
		
		io_context.run();
		t.join();
		client.close();
		
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	
	
	return 0;
}
