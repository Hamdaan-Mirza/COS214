#include "Command.h"
#include "ChatRoom.h"
#include "User.h"

Command::Command() : room(nullptr), fromUser(nullptr), message("") {}

Command::Command(ChatRoom* room, User* fromUser, std::string message)
    : room(room), fromUser(fromUser), message(message) {}

Command::~Command() {
    delete room;
    delete fromUser;
}

std::string Command::getMessage() { return message; }

User* Command::getFromUser() { return fromUser; }

ChatRoom* Command::getRoom() { return room; }

SendMessageCommand::SendMessageCommand(ChatRoom* room, User* fromUser, std::string message)
    : Command(room, fromUser, message) {}

SendMessageCommand::~SendMessageCommand() {}

void SendMessageCommand::execute() {
    if(!room || !fromUser) return;
    room->sendMessage(message, fromUser);
}

LogMessageCommand::LogMessageCommand(ChatRoom* room, User* fromUser, std::string message)
    : Command(room, fromUser, message) {}

LogMessageCommand::~LogMessageCommand() {}

void LogMessageCommand::execute() {
    if(!room || !fromUser) return;
    room->saveMessage(message, fromUser);
}