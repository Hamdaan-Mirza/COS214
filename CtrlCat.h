#ifndef CTRL_CAT_H
#define CTRL_CAT_H

/**
 * @file CtrlCat.h
 * @brief It defines the CtrlCat class with its attributes and functions.
 * @author Hamdaan Mirza - u24631494
 * @date 30-09-2025
 */

#include "ChatRoom.h"

/**
 * @class CtrlCat
 * @brief It represents the cat chat room.
 * @details It is a concrete implementation of the ChatRoom class for cat users.
 */
class CtrlCat : public ChatRoom {
    public:
/**
 * @brief Constructor for CtrlCat.
 */
        CtrlCat();
/** @brief Destructor for CtrlCat.
 */
        virtual ~CtrlCat() override;
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
        void sendMessage(std::string message, User *fromUser) override;
/**
 * @brief Saves a message to the chat room.
 * @param message The message to save.
 * @param fromUser The user who sent the message.
 * @return void
 */
        void saveMessage(std::string message, User *fromUser) override;
};

#endif

