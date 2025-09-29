#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

class ChatRoom;
class User;

class Command {
    protected:
        ChatRoom* room;
        std::string message;
        User* fromUser;

    public:
        Command();
        Command(ChatRoom* room, User* fromUser, std::string message);
        virtual ~Command();
        virtual void execute() = 0;
        std::string getMessage();
        User* getFromUser();
        ChatRoom* getRoom();
};

class SendMessageCommand : public Command {
    public:
        SendMessageCommand(ChatRoom* room, User* fromUser, std::string message);
        virtual ~SendMessageCommand();
        void execute() override;
};

class LogMessageCommand : public Command {
    public:
        LogMessageCommand(ChatRoom* room, User* fromUser, std::string message);
        virtual ~LogMessageCommand();
        void execute() override;
};

#endif 