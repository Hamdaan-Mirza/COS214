#ifndef CATUSER_H
#define CATUSER_H

/**
 * @file CatUser.h
 * @brief It defines the CatUser class with its functions. 
 * @author Hamdaan Mirza - u24631494
 * @date 30-09-2025
 */

#include "User.h"

/**
 * @class CatUser
 * @brief Represents a cat user in the chat application.
 * @details Inherits from the User class and adds cat-specific functionality.
 */
class CatUser : public User {
    public:
/**
 * @brief Constructor for CatUser.
 * @param name The name of the cat user.
 */
        CatUser(std::string name);
/**
 * @brief Destructor for CatUser.
 */
        virtual ~CatUser() override;
/**
 * @brief Sends a message to a chat room.
 * @param message The message to send.
 * @param chatRoom The chat room to send the message to.
 * @return void
 */
        void send(std::string message, ChatRoom* chatRoom) override;
/**
 * @brief Receives a message from a chat room.
 * @param message The message received.
 * @param fromUser The user who sent the message.
 * @param chatRoom The chat room the message was sent to.
 * @return void
 */
        void receive(std::string message, User* fromUser, ChatRoom* chatRoom) override;
/**
 * @brief Adds a command to the cat user's command queue.
 * @param command pointer to the command to add.
 * @return void
 */
        void addCommand(Command* command) override;
/**
 * @brief Executes all commands in the cat user's command queue.
 * @return void
 */
        void executeAll() override;
};

#endif