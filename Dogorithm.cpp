#include "Dogorithm.h"
#include "ChatRoom.h"
#include "User.h"

/**
 * @file Dogorithm.cpp
 * @brief It implements the Dogorithm class and its functions for registering users, removing users, sending messages and saving messages.
 * @details It implements the Concrete Mediator role in the Mediator pattern.
 * @author Hamdaan Mirza - u24631494
 * @date 30-09-2025
 */

Dogorithm::Dogorithm() {}

Dogorithm::~Dogorithm() {}

void Dogorithm::registerUser(User* user) {
    std::vector<User*> users = getUsers();
    users.push_back(user);
    setUsers(users);

    std::vector<ChatRoom*> chatRooms = user->getChatRooms();
    chatRooms.push_back(this);
    user->setChatRooms(chatRooms);

    notify("user_joined", this);
}

void Dogorithm::removeUser(User* user) {
    std::vector<User*> users = getUsers();
    for(int i = 0; i < users.size(); i++) {
        if(users[i] == user) {
            users.erase(users.begin() + i);
            notify("user_left", this);
            break;
        }
    }
    setUsers(users);
}

void Dogorithm::sendMessage(std::string message, User *fromUser) {
    std::vector<User*> users = getUsers();
    for (int i = 0; i < users.size(); i++) {
        if (users[i] != fromUser) users[i]->receive(message, fromUser, this);
    }
    notify("message_sent", this);
}

void Dogorithm::saveMessage(std::string message, User *fromUser) {
    std::vector<std::string*> chatHistory = getChatHistory();
    chatHistory.push_back(new std::string(fromUser->getName() + ": " + message));
    setChatHistory(chatHistory);
}
