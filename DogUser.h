#ifndef DOGUSER_H
#define DOGUSER_H

#include "User.h"

class DogUser : public User {
    public:
        DogUser(std::string name);
        virtual ~DogUser() override;
        void send(std::string message, ChatRoom* chatRoom) override;
        void receive(std::string message, User* fromUser, ChatRoom* chatRoom) override;
        void addCommand(Command* command) override;
        void executeAll() override;
};

#endif