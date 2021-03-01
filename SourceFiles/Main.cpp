#include <iostream>
#include <thread>
#include "../HeaderFiles/GuestHandler.h"
#include "../HeaderFiles/Minotaur.h"
#include <vector>
#include <mutex>

using std::cout;
using std::cin;
std::mutex mut;

int main()
{
    Minotaur minotaur;

    int numberOfGuests = 0;
    cout << "Minotaur Master: How many guests will participate? ";
    cin >> numberOfGuests;

    GuestHandler handler(numberOfGuests, &minotaur);
    handler.readyShowcase();
    // GuestHandler handler(numberOfGuests, &minotaur);
    // handler.readyLabyrinth();
    
    

    return 0;
}

