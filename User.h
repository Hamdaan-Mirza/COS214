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
        std::vector<Command*> commandQueue;
    public:
        User(std::string name);
        virtual ~User();
        virtual void send(std::string message, ChatRoom* chatRoom) = 0;
        virtual void receive(std::string message, User* fromUser, ChatRoom* chatRoom) = 0;
        virtual void addCommand(Command* command) = 0;
        virtual void executeAll() = 0;
        std::string getName();
        Command* getCommandQueue();
        std::vector<ChatRoom*> getChatRooms();
        void setChatRooms(std::vector<ChatRoom*> chatRooms);
        void setCommandQueue(Command* commandQueue);
};

#endif