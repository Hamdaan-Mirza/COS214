#include "ChatRoom.h"
#include "CtrlCat.h"
#include "Dogorithm.h"
#include "User.h"
#include "CatUser.h"
#include "DogUser.h"
#include "AdminUser.h"
#include "Command.h"

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

    delete catRoom;
    delete dogRoom;
    std::cout << "====================================="<<std::endl;
    std::cout << "Testing Command"<<std::endl;
    std::cout << "====================================="<<std::endl;
    CtrlCat* catRoom2 = new CtrlCat();
    Dogorithm* dogRoom2 = new Dogorithm();

    CatUser* cat2 = new CatUser("User3");
    DogUser* dog2 = new DogUser("User4");
    AdminUser* admin2 = new AdminUser("Admin2");

    admin2->send("Admin speaking", catRoom2);
    cat2->send("Love cats", catRoom2);
    
    for(int i = 0; i < catRoom2->getChatHistory().size(); i++) {
        std::cout << *catRoom2->getChatHistory()[i] << std::endl;
    }

    delete catRoom2;
    delete dogRoom2;
    delete cat2;
    delete dog2;
    delete admin2;
    std::cout << "====================================="<<std::endl;
}