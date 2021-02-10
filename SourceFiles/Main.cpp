#include <iostream>
#include <thread>
#include "../HeaderFiles/GuestHandler.h"
#include "../HeaderFiles/Minotaur.h"
#include <vector>

using std::cout;

int main()
{
    Minotaur minotaur;
    GuestHandler handler(5, &minotaur);
    
    

    return 0;
}

