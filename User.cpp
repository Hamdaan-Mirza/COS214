#include "User.h"
#include "Command.h"

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