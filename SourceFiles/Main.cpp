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
    handler.readyLabyrinth();
    
    while (minotaur.gameRunning())
    {
        // Loop till game finishes.
    }

    std::this_thread::sleep_for(std::chrono::seconds(3));

    Minotaur minotaurTwo;
    GuestHandler handlerTwo(numberOfGuests, &minotaurTwo);
    handlerTwo.readyShowcase();


    // I did not write an exit condition as one was not specified with problem 2.
    // GuestHandler handlerTwo(numberOfGuests, &minotaur);
    // handler.readyShowcase();

    return 0;
}

