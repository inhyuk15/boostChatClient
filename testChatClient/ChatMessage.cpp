#include "ChatMessage.hpp"

ChatMessage::ChatMessage() {}

ChatMessage::ChatMessage(const std::string& userName, uint32_t timestamp,
												 chat::DataType dataType) {
		message_.set_user_name(userName);
		message_.set_timestamp(timestamp);
		message_.set_data_type(dataType);
}

void ChatMessage::setTextMessage(const std::string& messageText) {
		message_.set_message_text(messageText);
}

void ChatMessage::setImageMessage(const std::string& imageExtension,
																	const std::vector<uint8_t>& imageData) {
		message_.set_file_extension(imageExtension);
		message_.set_image_data(imageData.data(), imageData.size());
}

void ChatMessage::setDataType(chat::DataType dataType) {
	message_.set_data_type(dataType);
}

void ChatMessage::setSystemCode(chat::SystemCode systemCode) {
	message_.set_system_code(systemCode);
}

std::string ChatMessage::encode() const {
		std::string output;
		message_.SerializeToString(&output);
		return output;
}

void ChatMessage::decode(const std::string& input) {
		message_.ParseFromString(input);
}

std::string ChatMessage::getUserName() const { return message_.user_name(); }

uint32_t ChatMessage::getTimestamp() const { return message_.timestamp(); }

chat::DataType ChatMessage::getDataType() const { return message_.data_type(); }

chat::SystemCode ChatMessage::getSystemCode() const { return message_.system_code(); }

std::string ChatMessage::getMessageText() const {
		return message_.message_text();
}

std::vector<uint8_t> ChatMessage::getImageData() const {
		return std::vector<uint8_t>(message_.image_data().begin(),
																message_.image_data().end());
}

std::string ChatMessage::getFileExtension() const {
		return message_.file_extension();
}
