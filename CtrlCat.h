#ifndef CTRL_CAT_H
#define CTRL_CAT_H

#include "ChatRoom.h"

class CtrlCat : public ChatRoom {
    public:
        CtrlCat();
        virtual ~CtrlCat() override;
        void registerUser(User* user) override;
        void removeUser(User* user) override;
        void sendMessage(std::string message, User *fromUser) override;
        void saveMessage(std::string message, User *fromUser) override;
};

#endif

