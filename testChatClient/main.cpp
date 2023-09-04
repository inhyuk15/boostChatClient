#include <iostream>
#include <boost/asio.hpp>
#include <cstdlib>
#include "ChatMessage.hpp"

using boost::asio::ip::tcp;

constexpr int BUFF_SIZE = 32;

class Client {
public:
	Client(boost::asio::io_context& io_context, tcp::resolver::results_type& endpoints,
				 std::string nickname): io_context_(io_context), socket_(io_context), nickname_(nickname) {
		connect(endpoints);
	}
	
	void close() {
		boost::asio::post(io_context_,  [this](){ socket_.close();});
	}
	
	void write(const ChatMessage& chatMessage) {
		auto sendBytes = chatMessage.encode();
		uint32_t dataSize = static_cast<uint32_t>(sendBytes.size());
		dataSize = htonl(dataSize);
		
		boost::asio::async_write(socket_, boost::asio::buffer(&dataSize, sizeof(dataSize)),
						 [this, sendBytes](boost::system::error_code ec, size_t) {
			if (!ec) {
				doWrite(sendBytes);
			}
			else {
				std::cerr << "error in writing header" << std::endl;
				socket_.close();
			}
		});
	}
	
	void doWrite(const std::string& sendBytes) {
		boost::asio::async_write(socket_, boost::asio::buffer(sendBytes), [this](boost::system::error_code ec, size_t byteTransferred) {
			if (!ec) {
				std::cout << "write sucesss, transferred : " << byteTransferred << "bytes" << std::endl;
			} else {
				std::cerr << "error in writing " << ec.message() << std::endl;
				socket_.close();
			}
		});
	}
	
	// read size (4 byte)
	void read() {
		uint32_t networkDataSize;
		boost::asio::async_read(socket_, boost::asio::buffer(&networkDataSize, sizeof(networkDataSize)),
														[this, networkDataSize](boost::system::error_code ec, std::size_t) {
			if (!ec) {
				doRead(ntohl(networkDataSize));
			}
			else {
				std::cerr << "error in reading header " << std::endl;
				socket_.close();
			}
		});
	}
	
	void doRead(uint32_t networkDataSize) {
			std::string binaryData(networkDataSize, '\0');
		boost::asio::async_read(socket_, boost::asio::buffer(binaryData),
																	[this, binaryData](boost::system::error_code ec, size_t bytesRead) {
			if (!ec) {
				ChatMessage chatMessage;
				chatMessage.decode(binaryData);
				std::cout << "Username: " << chatMessage.getUserName() << std::endl;
				std::cout << "Timestamp: " << chatMessage.getTimestamp()
									<< std::endl;
				if (chatMessage.getDataType() == chat::TEXT) {
						std::cout << "Message: " << chatMessage.getMessageText()
											<< std::endl;
				} else if (chatMessage.getDataType() == chat::IMAGE) {
						std::cout << " image" << std::endl;
				}

				read();
			}
			else {
				std::cerr << "error in reading" << std::endl;
				socket_.close();
			}
		});
	}
	
	void connect(tcp::resolver::results_type& endpoints) {
		boost::asio::async_connect(socket_, endpoints, [this](boost::system::error_code ec, tcp::endpoint) {
			if (!ec) {
				std::cout << "connection success! " << std::endl;
				connected_.store(true);
				read();
			} else {
				std::cerr << "error in connection: " << ec.message() << std::endl;
				socket_.close();
			}
		});
	}
	
	bool isConnected() const {
		return connected_.load();
	}
	
private:
	tcp::socket socket_;
	boost::asio::io_context& io_context_;
	std::atomic<bool> connected_{false};
};


int main(int argc, const char * argv[]) {
	try {
		std::string port = "4000";
		std::string host = "localhost";
		
		boost::asio::io_context io_context;
		tcp::resolver resolver(io_context);
		auto endpoints = resolver.resolve(host, port);
		
		
		std::cout << "Enter your nickname : ";
		std::string nickname;
		std::getline(std::cin, nickname);
		
		Client client(io_context, endpoints, nickname);
		
		std::thread t([&client]() {
			while(!client.isConnected()) {
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
			
			while(true) {
				std::string msg;
				std::cin >> msg;
				
				std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

			 auto duration = now.time_since_epoch();
			 uint32_t timestamp = std::chrono::duration_cast<std::chrono::seconds>(duration).count();

				ChatMessage chatMessage("para", timestamp, chat::DataType::TEXT);
				chatMessage.setTextMessage(msg);
				client.write(chatMessage);
			}
		});
		
		io_context.run();
		client.close();
		t.join();
		
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	
	
	return 0;
}
