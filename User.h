#ifndef USERS_H
#define USERS_H

/**
 * @file User.h
 * @brief It defines the User class with its attributes and functions.
 * @author Hamdaan Mirza - u24631494
 * @date 30-09-2025
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

/**
 * @brief Forward declaration of classes to avoid circular dependencies.
 */
class Command;
class ChatRoom; 

/**
 * @class User
 * @brief Abstract base class for all users.
 * @details This class provides the interface for user actions in the chat system.
 */
class User {
    protected:
/** 
 * @brief The chat rooms the user is part of.
*/
        std::vector<ChatRoom*> chatRooms;
/** 
* @brief The name of the user.
 */
        std::string name;
/**
* @brief The command queue for the user.
*/
        std::vector<Command*> commandQueue;
    public:
/**
 * @brief Constructor for User.
 * @param name The name of the user.
 */
        User(std::string name);
/**
 * @brief Destructor for User.
 */
        virtual ~User();
/**
 * @brief Sends a message to a chat room.
 * @details This is a pure virtual function that must be implemented by derived classes.
 * @param message The message to send.
 * @param chatRoom The chat room to send the message to.
 * @return void
 */
        virtual void send(std::string message, ChatRoom* chatRoom) = 0;
/**
 * @brief Receives a message from a chat room.
 * @details This is a pure virtual function that must be implemented by derived classes.
 * @param message The message received.
 * @param fromUser The user who sent the message.
 * @param chatRoom The chat room the message was sent to.
 * @return void
 */
        virtual void receive(std::string message, User* fromUser, ChatRoom* chatRoom) = 0;
/**
 * @brief Adds a command to the user's command queue.
 * @details This is a pure virtual function that must be implemented by derived classes.
 * @param command pointer to the command to add.
 * @return void
 */  
        virtual void addCommand(Command* command) = 0;
/**
 * @brief Executes all commands in the user's command queue.
 * @details This is a pure virtual function that must be implemented by derived classes.
 * @return void
 */
        virtual void executeAll() = 0;
/**
 * @brief Gets the name of the user.
 * @return The name of the user.
 */
        std::string getName();
/**
* @brief Gets the command queue of the user.
 * @return The command queue of the user.
 */
        std::vector<Command*> getCommandQueue();
/**
 * @brief Gets the chat rooms the user is part of.
 * @return The chat rooms the user is part of.
 */
        std::vector<ChatRoom*> getChatRooms();
/**
 * @brief Sets the chat rooms the user is part of.
 * @param chatRooms The chat rooms to set.
 * @return void
 */
        void setChatRooms(std::vector<ChatRoom*> chatRooms);
/**
 * @brief Sets the command queue of the user.
 * @param commandQueue The command queue to set.
 * @return void
 */
        void setCommandQueue(std::vector<Command*> commandQueue);
};

#endif