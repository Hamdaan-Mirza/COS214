#include "User.h"

User::User(std::string name) : name(name), commandQueue(nullptr) {}

User::~User() {
    delete commandQueue;
    commandQueue = nullptr;
}

void User::send(std::string message, ChatRoom* chatRoom) {
    chatRoom->sendMessage(message, this);
}

void User::receive(std::string message, User* fromUser, ChatRoom* chatRoom) {
    std::cout << "[" << &chatRoom << "] " << fromUser->getName() << " to " << name << ": " << message << std::endl;
}

void User::addCommand(Command* command) {
    if (!commandQueue) {
        commandQueue = command;
    } else {
        Command* temp = commandQueue;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = command;
    }
}

void User::executeAll() {
    Command* temp = commandQueue;
    while (temp) {
        temp->execute();
        Command* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    commandQueue = nullptr;
}

std::string User::getName() { return name; }

Command* User::getCommandQueue() { return commandQueue; }

std::vector<ChatRoom*> User::getChatRooms() { return chatRooms; }

void User::setCommandQueue(Command* commandQueue) { this->commandQueue = commandQueue; }