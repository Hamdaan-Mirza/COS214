#include "AdminUser.h"
#include "ChatRoom.h"
#include "Command.h"

/**
 * @file AdminUser.cpp
 * @brief It implements the AdminUser class and its functions for sending messages,receiving messages, adding commands and executing all.
 * @details It implements the Invoker role in the Command pattern. It is part of both chatrooms.
 * @author Hamdaan Mirza - u24631494
 * @date 29-09-2025
 */

AdminUser::AdminUser(std::string name) : User(name) {}

AdminUser::~AdminUser() {}

void AdminUser::send(std::string message, ChatRoom* chatRoom) {
    if(!chatRoom) return;
    std::cout << "Admin " << name << " sends message:- " << message << " -to chat room." << std::endl;
    // chatRoom->sendMessage(message, this);

    addCommand(new SendMessageCommand(chatRoom, this, message));
    addCommand(new LogMessageCommand(chatRoom, this, message));
    executeAll();
}

void AdminUser::receive(std::string message, User* fromUser, ChatRoom* chatRoom) {
    std::cout << "Admin " << name << " received message: " << message << " from " << fromUser->getName() << " in chat room." << std::endl;
}

void AdminUser::addCommand(Command* command) {
    if(!command) return;
    commandQueue.push_back(command);
}

void AdminUser::executeAll() {
    for(int i = 0; i < commandQueue.size(); i++) {
        Command* command = commandQueue[i];
        if(command) command->execute();
        delete command;
    }
    commandQueue.clear();
}