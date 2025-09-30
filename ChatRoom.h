#ifndef CHATROOM_H
#define CHATROOM_H

/**
 * @file ChatRoom.h
 * @brief It defines the ChatRoom class with its attributes and functions.
 * @author Hamdaan Mirza - u24631494
 * @date 30-09-2025
 */

#include "Iterator.h"
#include "ChatRoomIterator.h"
#include "Subject.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

/**
 * @brief Forward declaration of classes to avoid circular dependencies.
 */
class User;

/**
 * @brief ChatRoom class
 * @details This Abstract class represents a chat room where users can send and receive messages.
 */
class ChatRoom : public Subject
{
public:
/**
 * @brief Constructor for ChatRoom.
 */
    ChatRoom();
/**
 * @brief Destructor for ChatRoom.
 */
    virtual ~ChatRoom();
/**
 * @brief Registers a user in the chat room.
 * @param user The user to register.
 * @details implemented by derived classes.
 * @return void
 */
    virtual void registerUser(User *user) = 0;
/**
 * @brief Removes a user from the chat room.
 * @param user The user to remove.
 * @details implemented by derived classes.
 * @return void
 */
    virtual void removeUser(User *user) = 0;
/**
 * @brief Sends a message to the chat room.
 * @param message The message to send.
 * @param fromUser The user who sent the message.
 * @details implemented by derived classes.
 * @return void
 */
    virtual void sendMessage(std::string message, User *fromUser) = 0;
/**
 * @brief Saves a message to the chat room.
 * @param message The message to save.
 * @param fromUser The user who sent the message. 
 * @details implemented by derived classes.
 * @return void  
 */
    virtual void saveMessage(std::string message, User *fromUser) = 0;
/**
 * @brief Creates an iterator for the users in the chat room.
 * @return An iterator for the users in the chat room.
 */
    virtual Iterator<User *> *createUserIterator();
/**
 * @brief Creates an iterator for the messages in the chat room.
 * @return An iterator for the messages in the chat room.
 */
    virtual Iterator<std::string *> *createMessageIterator();
/**
 * @brief Gets the chat history of the chat room.
 * @return The chat history of the chat room.
 */
    std::vector<std::string *> getChatHistory();
/** @brief Gets the users in the chat room.
 * @return The users in the chat room.
 */
    std::vector<User *> getUsers();
/**
 * @brief Sets the users in the chat room.
 * @param users The users to set in the chat room.
 * @return The users in the chat room.
 */
    std::vector<User *> setUsers(std::vector<User *> users);
/**
 * @brief Sets the chat history of the chat room.
 * @param chatHistory The chat history to set.
 * @return The chat history of the chat room.
 */
    std::vector<std::string *> setChatHistory(std::vector<std::string *> chatHistory);
private:
/**
 * @brief The users in the chat room.
 */
    std::vector<User *> users;
/**
 * @brief The chat history of the chat room.
 */
    std::vector<std::string *> chatHistory;
};

#endif