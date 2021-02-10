#include "../HeaderFiles/Minotaur.h"

bool Minotaur::verifySuccess(int n)
{
    isGameRunning = false;
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

void Minotaur::EnterLabyrinth(std::thread::id ID)
{
    if(trackedGuests.find(ID) == trackedGuests.end())
    {
        trackedGuests.insert(ID);
    }
    else
    {
        //std::cout << ID << " Already has entered the labryinth before." << std::endl;
    }

}