#include <iostream>
#include <thread>
#include "../HeaderFiles/GuestHandler.h"
#include "../HeaderFiles/Minotaur.h"
#include <vector>

using std::cout;
using std::cin;

int main()
{
    Minotaur minotaur;

    int numberOfGuests = 0;
    cout << "Minotaur Master: How many guests will participate? ";
    cin >> numberOfGuests;
    
    GuestHandler handler(numberOfGuests, &minotaur);
    
    

    return 0;
}

