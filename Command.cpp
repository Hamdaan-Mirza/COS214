#include "Command.h"
#include "ChatRoom.h"
#include "User.h"

/**
 * @file Command.cpp
 * @brief It implements the Command class and its derived classes SendMessageCommand and LogMessageCommand.
 * @details It implements the Command role in the Command pattern. It is part of both chatrooms.
 * @author Hamdaan Mirza - u24631494
 * @date 30-09-2025
 */

Command::Command() : room(nullptr), fromUser(nullptr), message("") {}

Command::Command(ChatRoom* room, User* fromUser, std::string message)
/**
 * @brief 
 * @param room 
 * @return 
 */
    : room(room), fromUser(fromUser), message(message) {}

Command::~Command() {
    // delete room;
    // delete fromUser;
}

std::string Command::getMessage() { return message; }

User* Command::getFromUser() { return fromUser; }

ChatRoom* Command::getRoom() { return room; }

SendMessageCommand::SendMessageCommand(ChatRoom* room, User* fromUser, std::string message)
/**
 * @brief 
 * @param room 
 * @param fromUser 
 * @param message 
 * @return 
 */
    : Command(room, fromUser, message) {}

SendMessageCommand::~SendMessageCommand() {}

void SendMessageCommand::execute() {
    if(!room || !fromUser) return;
    room->sendMessage(message, fromUser);
}

LogMessageCommand::LogMessageCommand(ChatRoom* room, User* fromUser, std::string message)
/**
 * @brief 
 * @param room 
 * @param fromUser 
 * @param message 
 * @return 
 */
    : Command(room, fromUser, message) {}

LogMessageCommand::~LogMessageCommand() {}

void LogMessageCommand::execute() {
    if(!room || !fromUser) return;
    room->saveMessage(message, fromUser);
}