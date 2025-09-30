#ifndef ADMINUSER_H
#define ADMINUSER_H

/**
 * @file AdminUser.h
 * @brief It defines the AdminUser class with its functions. 
 * @author Hamdaan Mirza - u24631494
 * @date 30-09-2025
 */

#include "User.h"

/**
 * @class AdminUser
 * @brief Represents an admin user in the chat application.
 * @details Inherits from the User class and adds admin-specific functionality.
 */
class AdminUser : public User {
    public:

/**
 * @brief Constructor for AdminUser.
 * @param name The name of the admin user.
 */
        AdminUser(std::string name);
/** 
* @brief Destructor for AdminUser.
*/
        virtual ~AdminUser() override;
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
 * @brief Adds a command to the admin user's command queue.
 * @param command pointer to the command to add.
 * @return void
 */
        void addCommand(Command* command) override;
/**
 * @brief Executes all commands in the admin user's command queue.
 * @return void
 */
        void executeAll() override;
};

#endif