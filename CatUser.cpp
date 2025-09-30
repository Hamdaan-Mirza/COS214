#include "CatUser.h"
#include "ChatRoom.h"
#include "Command.h"

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
