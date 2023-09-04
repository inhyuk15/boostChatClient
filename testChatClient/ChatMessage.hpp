#ifndef ChatMessage_hpp
#define ChatMessage_hpp

#include "chat.pb.h"

class ChatMessage {
public:
	ChatMessage();
		ChatMessage(const std::string& userName, uint32_t timestamp, chat::DataType dataType);

		void setTextMessage(const std::string& messageText);
		void setImageMessage(const std::string& imageExtension, const std::vector<uint8_t>& imageData);

		std::string encode() const;
		void decode(const std::string& input);

		std::string getUserName() const;
		uint32_t getTimestamp() const;
		chat::DataType getDataType() const;

		std::string getMessageText() const;
		std::vector<uint8_t> getImageData() const;
		std::string getImageExtension() const;

private:
		chat::ChatMessage message_;
};

#endif /* ChatMessage_hpp */
