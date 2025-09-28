#include "ChatRoom.h"
#include "User.h"

ChatRoom::ChatRoom() {}

ChatRoom::~ChatRoom() {
    for(int i = 0; i < chatHistory.size(); i++) {
        delete chatHistory[i];
    }
    chatHistory.clear();
    users.clear();
}

std::vector<std::string*> ChatRoom::getChatHistory() { return chatHistory; }

std::vector<User*> ChatRoom::getUsers() { return users; }

std::vector<User*> ChatRoom::setUsers(std::vector<User*> users) {
    this->users = users;
    return this->users;
}

std::vector<std::string*> ChatRoom::setChatHistory(std::vector<std::string*> chatHistory) {
    this->chatHistory = chatHistory;
    return this->chatHistory;
}
