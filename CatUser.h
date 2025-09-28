#ifndef CATUSER_H
#define CATUSER_H

#include "User.h"

class CatUser : public User {
    public:
        CatUser(std::string name);
        virtual ~CatUser() override;
        void send(std::string message, ChatRoom* chatRoom) override;
        void receive(std::string message, User* fromUser, ChatRoom* chatRoom) override;
        void addCommand(Command* command) override;
        void executeAll() override;
};

#endif