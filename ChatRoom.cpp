#include "ChatRoom.h"
#include "User.h"

/**
 * @file ChatRoom.cpp
 * @brief It implements the ChatRoom class and its getter and setter functions, as well as constructor and destructor. It is an abstract class
 * @details It implements the Mediator role in the Mediator pattern. 
 * @author Hamdaan Mirza - u24631494
 * @date 30-09-2025
 */

ChatRoom::ChatRoom() {}

ChatRoom::~ChatRoom()
{
    for (int i = 0; i < chatHistory.size(); i++)
    {
        delete chatHistory[i];
    }
    chatHistory.clear();
    // users.clear();
}

Iterator<User *> *ChatRoom::createUserIterator()
{
    return new ChatRoomIterator<User *>(users);
}

Iterator<std::string *> *ChatRoom::createMessageIterator()
{
    return new ChatRoomIterator<std::string *>(chatHistory);
}

std::vector<std::string *> ChatRoom::getChatHistory() { return chatHistory; }

std::vector<User *> ChatRoom::getUsers() { return users; }

std::vector<User *> ChatRoom::setUsers(std::vector<User *> users)
{
    this->users = users;
    return this->users;
}

std::vector<std::string *> ChatRoom::setChatHistory(std::vector<std::string *> chatHistory)
{
    this->chatHistory = chatHistory;
    return this->chatHistory;
}
