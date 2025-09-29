#include "User.h"
#include "Command.h"

User::User(std::string name) : name(name), commandQueue(nullptr) {}

User::~User() {
    delete commandQueue;
    commandQueue = nullptr;
}

std::string User::getName() { return name; }

Command* User::getCommandQueue() { return commandQueue; }

std::vector<ChatRoom*> User::getChatRooms() { return chatRooms; }

void User::setChatRooms(std::vector<ChatRoom*> chatRooms) { this->chatRooms = chatRooms; }

void User::setCommandQueue(Command* commandQueue) { this->commandQueue = commandQueue; }