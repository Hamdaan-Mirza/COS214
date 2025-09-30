#include "ChatRoomObserver.h"

void ActivityObserver::update(const std::string &event, void *data)
{
    ChatRoom *room = static_cast<ChatRoom *>(data);

    if (event == "user_joined")
    {
        std::cout << "[ACTIVITY] New user joined the chat room" << std::endl;
    }
/**
 * @brief 
 * @param "user_left" 
 * @return 
 */
    else if (event == "user_left")
    {
        std::cout << "[ACTIVITY] User left the chat room" << std::endl;
    }
/**
 * @brief 
 * @param "message_sent" 
 * @return 
 */
    else if (event == "message_sent")
    {
        std::cout << "[ACTIVITY] New message sent the chat room" << std::endl;
    }
}

StatisticsObserver::StatisticsObserver()
{
    numUsers = 0;
    numMessages = 0;
}

void StatisticsObserver::update(const std::string &event, void *data)
{
    ChatRoom *room = static_cast<ChatRoom *>(data);

    if (event == "user_joined")
    {
        numUsers++;
        std::cout << "[STATS] Total users across all rooms: " << numUsers << std::endl;
    }
/**
 * @brief 
 * @param "message_sent" 
 * @return 
 */
    else if (event == "message_sent")
    {
        numMessages++;
        std::cout << "[STATS] Total messages sent: " << numMessages << std::endl;
    }
}

void AdminObserver::update(const std::string &event, void *data)
{
    ChatRoom *room = static_cast<ChatRoom *>(data);
    if (event == "user_joined")
    {
        std::cout << "[ADMIN] User joined - room now has "<< room->getUsers().size() << " users" << std::endl;
    }
}