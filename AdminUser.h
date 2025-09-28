#ifndef ADMINUSER_H
#define ADMINUSER_H

#include "User.h"

class AdminUser : public User {
    public:
        AdminUser(std::string name);
        virtual ~AdminUser() override;
        void send(std::string message, ChatRoom* chatRoom) override;
        void receive(std::string message, User* fromUser, ChatRoom* chatRoom) override;
        void addCommand(Command* command) override;
        void executeAll() override;
};

#endif