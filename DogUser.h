#ifndef DOGUSER_H
#define DOGUSER_H

/**
 * @file DogUser.h
 * @brief It defines the DogUser class with its functions. 
 * @author Hamdaan Mirza - u24631494
 * @date 30-09-2025
 */

#include "User.h"

/**
 * @class DogUser
 * @brief Represents a dog user in the chat application.
 * @details Inherits from the User class and adds dog-specific functionality.
 */
class DogUser : public User {
    public:
/**
 * @brief Constructor for DogUser.
 * @param name The name of the dog user.
 */
        DogUser(std::string name);
/** * @brief Destructor for DogUser.
 */
        virtual ~DogUser() override;
/**
 * @brief send a message to a chat room.
 * @param message message to send.
 * @param chatRoom chat room to send the message to.
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
 * @brief Adds a command to the dog user's command queue.
 * @param command pointer to the command to add.
 * @return void
 */
        void addCommand(Command* command) override;
/**
 * @brief Executes all commands in the dog user's command queue.
 * @return void
 */
        void executeAll() override;
};

#endif