#include "../HeaderFiles/Minotaur.h"

// Check if the number of guests is equal to the number of guests that entered the labyrinth.
bool Minotaur::verifySuccess(int n)
{
    isGameRunning = false;
    std::cout << "The number of guests is m: " << n << " and my tracked guests list has size of " << trackedGuests.size() << std::endl; 
    return (n == (trackedGuests.size()));
}   

void Minotaur::RequestCupcake()
{
    cupcakePresent = true;
}

void Minotaur::ConsumeCupcake()
{
    cupcakePresent = false;
}

void Minotaur::beginParty()
{
    isGameRunning = true;
}

bool Minotaur::plateEmpty()
{
    return (cupcakePresent == false);
}


bool Minotaur::gameRunning()
{
    return isGameRunning;
}

// Add the thread id to the unordered set to keep track of how many guests have entered the labyrinth.
void Minotaur::EnterLabyrinth(std::thread::id ID)
{
    if(trackedGuests.find(ID) == trackedGuests.end())
    {
        std::lock_guard<std::mutex> lock{mEventMutex};
        trackedGuests.insert(ID);
    }
}

void Minotaur::EnterShowcase(bool* ready)
{
    *ready = false;
    // Thread enters room.
}