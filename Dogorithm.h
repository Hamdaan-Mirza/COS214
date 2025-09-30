#ifndef DOGORITHM_H
#define DOGORITHM_H

/**
 * @file Dogorithm.h
 * @brief It defines the Dogorithm class with its attributes and functions.
 * @author Hamdaan Mirza - u24631494
 * @date 30-09-2025
 */

#include "ChatRoom.h"

/**
 * @class Dogorithm
 * @brief A class that represents a dog-themed chat room. 
 * @details It is a concrete implementation for the ChatRoom class for dog users.
 */
class Dogorithm : public ChatRoom {
    public:
/**
 * @brief Constructor for Dogorithm.
 */
        Dogorithm();
/**
 * @brief Destructor for Dogorithm.
 */
        virtual ~Dogorithm() override;
/**
 * @brief Registers a user in the chat room.
 * @param user The user to register.
 * @return void
 */
        void registerUser(User* user) override;
/**
 * @brief Removes a user from the chat room.
 * @param user The user to remove.
 * @return void
 */
        void removeUser(User* user) override;
/**
 * @brief Sends a message to the chat room.
 * @param message The message to send.
 * @param fromUser The user who sent the message.
 * @return void
 */
        void sendMessage(std::string message, User  *fromUser) override;
/**
 * @brief Saves a message to the chat room.
 * @param message The message to save.
 * @param fromUser The user who sent the message.
 * @return void
 */
        void saveMessage(std::string message, User *fromUser) override;
};

#endif 