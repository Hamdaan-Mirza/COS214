#include "DogUser.h"
#include "ChatRoom.h"
#include "Command.h"

/**
 * @file DogUser.cpp
 * @brief It implements the DogUser class and its functions for sending messages,receiving messages, adding commands and executing all.
 * @details It implements the Invoker role in the Command pattern. It is part of Dogorithm chatroom.
 * @author Hamdaan Mirza - u24631494
 * @date 29-09-2025
 */

DogUser::DogUser(std::string name) : User(name) {}

DogUser::~DogUser() {}

void DogUser::send(std::string message, ChatRoom* chatRoom) {
    if(!chatRoom) return;
    std::cout << "Dog " << name << " sends message: " << message << " to chat room." << std::endl;
    // chatRoom->sendMessage(message, this);

    addCommand(new SendMessageCommand(chatRoom, this, message));
    addCommand(new LogMessageCommand(chatRoom, this, message));
    executeAll();
}

void DogUser::receive(std::string message, User* fromUser, ChatRoom* chatRoom) {
    std::cout << "Dog " << name << " received message: " << message << " from " << fromUser->getName() << " in chat room." << std::endl;
}

void DogUser::addCommand(Command* command) {
    if(!command) return;
    commandQueue.push_back(command);
}

void DogUser::executeAll() {
    for(int i = 0; i < commandQueue.size(); i++) {
        Command* command = commandQueue[i];
        if(command) command->execute();
        delete command;
    }
    commandQueue.clear();
}