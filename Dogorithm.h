#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"

class Dogorithm : public ChatRoom {
    public:
        Dogorithm();
        ~Dogorithm() override;
        void registerUser(User* user) override;
        void removeUser(User* user) override;
        void sendMessage(std::string message, User  *fromUser) override;
        void saveMessage(std::string message, User *fromUser) override;
};

#endif 