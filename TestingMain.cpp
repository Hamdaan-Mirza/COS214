#include "ChatRoom.h"
#include "CtrlCat.h"
#include "Dogorithm.h"
#include "User.h"
#include "CatUser.h"
#include "DogUser.h"
#include "AdminUser.h"
#include "Command.h"
#include "Iterator.h"
#include "ChatRoomIterator.h"
#include "ChatRoomObserver.h"
#include "Subject.h"
#include "Observer.h"
#include <iostream>

int main() {

    std::cout << "====================================="<<std::endl;
    std::cout << "Testing Mediator"<<std::endl;
    std::cout << "====================================="<<std::endl;
    CtrlCat* catRoom = new CtrlCat();
    Dogorithm* dogRoom = new Dogorithm();

    CatUser* cat1 = new CatUser("User1");
    DogUser* dog1 = new DogUser("User2");
    AdminUser* admin1 = new AdminUser("Admin");

    catRoom->registerUser(cat1);
    catRoom->registerUser(admin1);
    dogRoom->registerUser(dog1);
    dogRoom->registerUser(admin1);

    admin1->send("Welcome fellow users!", catRoom);
    cat1->send("Hello everyone!", catRoom);
    dog1->send("Hi there!", dogRoom);
    admin1->send("Adhere to the rules. Thank you", dogRoom);

    std::cout << "\nCat Room Chat History:\n";
    for (int i = 0; i < catRoom->getChatHistory().size(); i++) {
        std::cout << *catRoom->getChatHistory()[i] << std::endl;
    }
    std::cout << "\nDog Room Chat History:\n";
    for (int i = 0; i < dogRoom->getChatHistory().size(); i++) {
        std::cout << *dogRoom->getChatHistory()[i] << std::endl;
    }

    catRoom->removeUser(cat1);
    dogRoom->removeUser(dog1);

    delete cat1;
    delete dog1;
    delete admin1;
    delete catRoom;
    delete dogRoom;
    
    std::cout << "====================================="<<std::endl;
    std::cout << "Testing Mediator Completed"<<std::endl;
    std::cout << "Testing Command"<<std::endl;
    std::cout << "====================================="<<std::endl;
    CtrlCat* catRoom2 = new CtrlCat();
    Dogorithm* dogRoom2 = new Dogorithm();

    CatUser* cat2 = new CatUser("User3");
    DogUser* dog2 = new DogUser("User4");
    AdminUser* admin2 = new AdminUser("Admin2");

    catRoom2->registerUser(cat2);
    catRoom2->registerUser(admin2);
    dogRoom2->registerUser(dog2);
    dogRoom2->registerUser(admin2);

    admin2->send("Admin speaking", catRoom2);
    cat2->send("Love cats", catRoom2);
    
    for(int i = 0; i < catRoom2->getChatHistory().size(); i++) {
        std::cout << *catRoom2->getChatHistory()[i] << std::endl;
    }

    admin2->addCommand(new SendMessageCommand(catRoom2, admin2, "Manual Send: Hello!"));
    admin2->addCommand(new LogMessageCommand(catRoom2, admin2, "Manual Save: Hello!"));

    std::cout << "Commands added to admin's queue but not executed yet.\n";
    admin2->executeAll();

    delete catRoom2;
    delete dogRoom2;
    delete cat2;
    delete dog2;
    delete admin2;
    
    std::cout << "====================================="<<std::endl;
    std::cout << "Testing Iterator"<<std::endl;
    std::cout << "====================================="<<std::endl;
    
    CtrlCat* catRoom3 = new CtrlCat();
    Dogorithm* dogRoom3 = new Dogorithm();
    
    CatUser* cat3 = new CatUser("IteratorCat");
    DogUser* dog3 = new DogUser("IteratorDog");
    AdminUser* admin3 = new AdminUser("IteratorAdmin");
    CatUser* cat4 = new CatUser("AnotherCat");
    
    catRoom3->registerUser(cat3);
    catRoom3->registerUser(admin3);
    catRoom3->registerUser(cat4);
    dogRoom3->registerUser(dog3);
    dogRoom3->registerUser(admin3);
    ;
    Iterator<User*>* userIter = catRoom3->createUserIterator();
    int userCount = 0;
    for (userIter->first(); !userIter->isDone(); userIter->next()) {
        User* user = userIter->currentItem();
        std::cout << "User " << ++userCount << ": " << user->getName() << std::endl;
    }
    delete userIter;
    
    userIter = dogRoom3->createUserIterator();
    userCount = 0;
    for (userIter->first(); !userIter->isDone(); userIter->next()) {
        User* user = userIter->currentItem();
        std::cout << "User " << ++userCount << ": " << user->getName() << std::endl;
    }
    delete userIter;
    
    Iterator<std::string*>* msgIter = catRoom3->createMessageIterator();
    int msgCount = 0;
    for (msgIter->first(); !msgIter->isDone(); msgIter->next()) {
        std::string* message = msgIter->currentItem();
        std::cout << "Message " << ++msgCount << ": " << *message << std::endl;
    }
    delete msgIter;

    msgIter = dogRoom3->createMessageIterator();
    msgCount = 0;
    for (msgIter->first(); !msgIter->isDone(); msgIter->next()) {
        std::string* message = msgIter->currentItem();
        std::cout << "Message " << ++msgCount << ": " << *message << std::endl;
    }
    delete msgIter;
    
    CtrlCat* emptyRoom = new CtrlCat();
    userIter = emptyRoom->createUserIterator();
    if (userIter->isDone()) {
        std::cout << "No users in empty room (correct)" << std::endl;
    }
    delete userIter;
    
    msgIter = emptyRoom->createMessageIterator();
    if (msgIter->isDone()) {
        std::cout << "No messages in empty room (correct)" << std::endl;
    }
    delete msgIter;
    
    userIter = catRoom3->createUserIterator();
    
    userIter->first();
    if (!userIter->isDone()) {
        User* firstUser = userIter->currentItem();
        std::cout << "First user: " << firstUser->getName() << std::endl;
    }
    
    userIter->next();
    if (!userIter->isDone()) {
        User* secondUser = userIter->currentItem();
        std::cout << "Second user: " << secondUser->getName() << std::endl;
    }
    
    userIter->first();
    while (!userIter->isDone()) {
        User* user = userIter->currentItem();
        std::cout << "Current user: " << user->getName() << std::endl;
        userIter->next();
    }
    
    delete userIter;
    
    delete catRoom3;
    delete dogRoom3;
    delete emptyRoom;
    delete cat3;
    delete dog3;
    delete admin3;
    delete cat4;
    
    std::cout << "====================================="<<std::endl;
    std::cout << "Testing Observer"<<std::endl;
    std::cout << "====================================="<<std::endl;
    
    CtrlCat* obsCatRoom = new CtrlCat();
    Dogorithm* obsDogRoom = new Dogorithm();
    
    ActivityObserver* activityObs = new ActivityObserver();
    StatisticsObserver* statsObs = new StatisticsObserver();
    AdminObserver* adminObs = new AdminObserver();
    
    obsCatRoom->attach(activityObs);
    obsCatRoom->attach(statsObs);
    obsCatRoom->attach(adminObs);
    
    obsDogRoom->attach(activityObs);
    obsDogRoom->attach(statsObs);
    
    CatUser* obsCatUser = new CatUser("ObserverCat");
    DogUser* obsDogUser = new DogUser("ObserverDog");
    AdminUser* obsAdminUser = new AdminUser("ObserverAdmin");
    
    obsCatRoom->registerUser(obsCatUser);
    obsCatRoom->registerUser(obsAdminUser);
    obsDogRoom->registerUser(obsDogUser);
    obsDogRoom->registerUser(obsAdminUser);
    
    obsCatUser->send("Hello from observer cat!", obsCatRoom);
    obsDogUser->send("Hello from observer dog!", obsDogRoom);
    obsAdminUser->send("Admin message with observers!", obsCatRoom);
    obsAdminUser->send("Another admin message!", obsDogRoom);
    
    obsCatRoom->removeUser(obsCatUser);
    obsDogRoom->removeUser(obsDogUser);

    obsCatRoom->detach(adminObs);
    obsCatUser = new CatUser("NewCatAfterDetach");
    obsCatRoom->registerUser(obsCatUser);
    
    for (int i = 1; i <= 3; i++) {
        obsCatUser->send("Message " + std::to_string(i), obsCatRoom);
    }
    
    userIter = obsCatRoom->createUserIterator();
    for (userIter->first(); !userIter->isDone(); userIter->next()) {
        User* user = userIter->currentItem();
        std::cout << "User: " << user->getName() << std::endl;
    }
    delete userIter;
    
    userIter = obsDogRoom->createUserIterator();
    for (userIter->first(); !userIter->isDone(); userIter->next()) {
        User* user = userIter->currentItem();
        std::cout << "User: " << user->getName() << std::endl;
    }
    delete userIter;
    delete obsCatRoom;
    delete obsDogRoom;
    delete activityObs;
    delete statsObs;
    delete adminObs;
    delete obsCatUser;
    delete obsDogUser;
    delete obsAdminUser;
    
    return 0;
}