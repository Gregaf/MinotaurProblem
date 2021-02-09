#include <iostream>
#include <thread>
#include "../HeaderFiles/GuestHandler.h"
#include "../HeaderFiles/Minotaur.h"
#include "../HeaderFiles/Counter.h"
#include <vector>

using std::cout;

int main()
{
    Minotaur* minotaurMaster = new Minotaur();   
    GuestHandler* guestHandler = new GuestHandler();

    system("pause");

    return 0;
}
