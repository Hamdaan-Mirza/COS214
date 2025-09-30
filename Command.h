#ifndef COMMAND_H
#define COMMAND_H

/**
 * @file Command.h
 * @brief It defines the Command class with its attributes and functions and its derived classes SendMessageCommand and LogMessageCommand with its functions
 * @author Hamdaan Mirza - u24631494
 * @date 30-09-2025
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

/**
 * @class Command
 * @brief Abstract base class for all commands.
 * @details Defines the interface for executing commands in the command design pattern
 */

class ChatRoom;
class User;

class Command {
    protected:
    // * @brief The chat room where the command is executed.
        ChatRoom* room;
    // * @brief The message associated with the command.
        std::string message;
    // * @brief The user who initiated the command.
        User* fromUser;

    public:
/**
 * @brief Default constructor.
 */
        Command();
/**
 * @brief Parameterized constructor.
 * @param room The chat room where the command is executed.
 * @param fromUser The user who initiated the command.
 * @param message The message associated with the command.
 */
        Command(ChatRoom* room, User* fromUser, std::string message);
        virtual ~Command();
/**
 * @brief Executes the command. It is a pure virtual function that is implemented by derived classes.
 */
        virtual void execute() = 0;
/**
 * @brief Gets the message associated with the command.
 * @return The message associated with the command.
 */
        std::string getMessage();
/**
 * @brief Gets the user who initiated the command.
 * @return The user who initiated the command.
 */
        User* getFromUser();
/** @brief Gets the chat room where the command is executed.
 * @return The chat room where the command is executed.
 */
        ChatRoom* getRoom();
};

/**
 * @class SendMessageCommand
 * @brief Command to send a message in the chat room. Derived class from Command
 * @details This command is responsible for sending a message from a user to a chat room.
 */
class SendMessageCommand : public Command {
    public:
/**
 * @brief Constructor for SendMessageCommand.
 * @param room The chat room where the message is sent.
 * @param fromUser The user who is sending the message.
 * @param message The message to be sent.
 */
        SendMessageCommand(ChatRoom* room, User* fromUser, std::string message);
/**
 * @brief Destructor for SendMessageCommand.
*/
        virtual ~SendMessageCommand();
/**
 * @brief Executes the command to send a message.
 * @return void
 */
        void execute() override;
};

/**
 * @class LogMessageCommand
 * @brief Command to log a message in the chat room. Derived class from Command
 * @details This command is responsible for logging/saving a message from a user to a chat room.
 */
class LogMessageCommand : public Command {
    public:
/**
 * @brief Constructor for LogMessageCommand.
 * @param room The chat room where the message is logged.
 * @param fromUser The user who sent the message.
 * @param message The message to be logged.
 */
        LogMessageCommand(ChatRoom* room, User* fromUser, std::string message);
/** 
 * * @brief Destructor for LogMessageCommand.
*/
        virtual ~LogMessageCommand();
/**
 * @brief executes the command to log/save a message.
 * @return void
 */
        void execute() override;
};

#endif 