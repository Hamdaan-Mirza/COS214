#include "CatUser.h"
#include "ChatRoom.h"
#include "Command.h"

/**
 * @file CatUser.cpp
 * @brief It implements the CatUser class and its functions for sending messages,receiving messages, adding commands and executing all.
 * @details It implements the Invoker role in the Command pattern. It is part of CtrlCat chatroom.
 * @author Hamdaan Mirza - u24631494
 * @date 29-09-2025
 */

CatUser::CatUser(std::string name) : User(name) {}

CatUser::~CatUser() {}

void CatUser::send(std::string message, ChatRoom* chatRoom) {
    if(!chatRoom) return;
    std::cout << "Cat " << name << " sends message:- " << message << " -to chat room." << std::endl;
    // chatRoom->sendMessage(message, this);
    
    addCommand(new SendMessageCommand(chatRoom, this, message));
    addCommand(new LogMessageCommand(chatRoom, this, message));
    executeAll();
}

void CatUser::receive(std::string message, User* fromUser, ChatRoom* chatRoom) {
    std::cout << "Cat " << name << " received message: " << message << " from " << fromUser->getName() << " in chat room." << std::endl;
}

void CatUser::addCommand(Command* command) {
    if(!command) return;
    commandQueue.push_back(command);
}

void CatUser::executeAll() {
    for(int i = 0; i < commandQueue.size(); i++) {
        Command* command = commandQueue[i];
        if(command) command->execute();
        delete command;
    }
    commandQueue.clear();
}
