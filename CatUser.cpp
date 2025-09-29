#include "CatUser.h"
#include "ChatRoom.h"

CatUser::CatUser(std::string name) : User(name) {}

CatUser::~CatUser() {}

void CatUser::send(std::string message, ChatRoom* chatRoom) {
    if(!chatRoom) return;
    std::cout << "Cat " << name << " sends message: " << message << " to chat room." << std::endl;
    chatRoom->sendMessage(message, this);
}

void CatUser::receive(std::string message, User* fromUser, ChatRoom* chatRoom) {
    std::cout << "Cat " << name << " received message: " << message << " from " << fromUser->getName() << " in chat room." << std::endl;
}
