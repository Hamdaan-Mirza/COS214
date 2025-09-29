#ifndef CHATROOM_H
#define CHATROOM_H

#include "ChatRoomIterator.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

class User;

class ChatRoom
{
private:
    std::vector<User *> users;
    std::vector<std::string *> chatHistory;

public:
    ChatRoom();
    virtual ~ChatRoom();
    virtual void registerUser(User *user) = 0;
    virtual void removeUser(User *user) = 0;
    virtual void sendMessage(std::string message, User *fromUser) = 0;
    virtual void saveMessage(std::string message, User *fromUser) = 0;
    virtual Iterator<User *> *createUserIterator();
    virtual Iterator<std::string *> *createMessageIterator();
    std::vector<std::string *> getChatHistory();
    std::vector<User *> getUsers();
    std::vector<User *> setUsers(std::vector<User *> users);
    std::vector<std::string *> setChatHistory(std::vector<std::string *> chatHistory);
};

#endif