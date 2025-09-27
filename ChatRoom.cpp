#include "ChatRoom.h"

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
