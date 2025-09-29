#include "AdminUser.h"
#include "ChatRoom.h"

AdminUser::AdminUser(std::string name) : User(name) {}

AdminUser::~AdminUser() {}

void AdminUser::send(std::string message, ChatRoom* chatRoom) {
    if(!chatRoom) return;
    std::cout << "Admin " << name << " sends message: " << message << " to chat room." << std::endl;
    chatRoom->sendMessage(message, this);
}

void AdminUser::receive(std::string message, User* fromUser, ChatRoom* chatRoom) {
    std::cout << "Admin " << name << " received message: " << message << " from " << fromUser->getName() << " in chat room." << std::endl;
}

