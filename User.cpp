#include "User.h"
#include "Command.h"

/**
 * @file User.cpp
 * @brief It implements the User class and its getter and setter functions, as well as constructor and destructor. It is an abstract class
 * @details It implements the Invoker role in the Command pattern.
 * @author Hamdaan Mirza - u24631494
 * @date 30-09-2025
 */

User::User(std::string name) : name(name) {}

User::~User() {
    for (Command* command : commandQueue) {
        delete command;
    }
}

std::string User::getName() { return name; }

std::vector<Command*> User::getCommandQueue() { return commandQueue; }

std::vector<ChatRoom*> User::getChatRooms() { return chatRooms; }

void User::setChatRooms(std::vector<ChatRoom*> chatRooms) { this->chatRooms = chatRooms; }

void User::setCommandQueue(std::vector<Command*> commandQueue) { this->commandQueue = commandQueue; }