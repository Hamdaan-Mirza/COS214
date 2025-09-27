#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

class Command;
class ChatRoom; 

class User {
    protected:
        std::vector<ChatRoom*> chatRooms;
        std::string name;
        Command* commandQueue;
    public:
        User(std::string name);
        virtual ~User();
        virtual void send(std::string message, ChatRoom* chatRoom);
        virtual void receive(std::string message, User* fromUser, ChatRoom* chatRoom);
        virtual void addCommand(Command* command);
        virtual void executeAll();
        std::string getName() const;
};

#endif