#include "DogUser.h"
#include "ChatRoom.h"

DogUser::DogUser(std::string name) : User(name) {}

DogUser::~DogUser() {}

void DogUser::send(std::string message, ChatRoom* chatRoom) {
    if(!chatRoom) return;
    std::cout << "Dog " << name << " sends message: " << message << " to chat room." << std::endl;
    chatRoom->sendMessage(message, this);
}

void DogUser::receive(std::string message, User* fromUser, ChatRoom* chatRoom) {
    std::cout << "Dog " << name << " received message: " << message << " from " << fromUser->getName() << " in chat room." << std::endl;
}