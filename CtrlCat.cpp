#include "CtrlCat.h"
#include "ChatRoom.h"
#include "User.h"

CtrlCat::CtrlCat() {}

CtrlCat::~CtrlCat() {}

void CtrlCat::registerUser(User* user) {
    std::vector<User*> users = getUsers();
    users.push_back(user);
    setUsers(users);
}

void CtrlCat::removeUser(User* user) {
    std::vector<User*> users = getUsers();
    for(int i = 0; i < users.size(); i++) {
        if(users[i] == user) {
            users.erase(users.begin() + i);
            break;
        }
    }
    setUsers(users);
}

void CtrlCat::sendMessage(std::string message, User *fromUser) {
    std::vector<User*> users = getUsers();
    for(int i = 0; i < users.size(); i++) users[i]->receive(message, fromUser, this);
    saveMessage(message, fromUser);
}

void CtrlCat::saveMessage(std::string message, User *fromUser) {
    std::vector<std::string*> chatHistory = getChatHistory();
    chatHistory.push_back(new std::string(fromUser->getName() + ": " + message));
    setChatHistory(chatHistory);
}
