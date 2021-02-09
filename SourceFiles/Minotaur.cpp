#include "../HeaderFiles/Minotaur.h"

void Minotaur::InviteGuest()
{
    // Pick a random guest --> rand() % numGuests
    // which means that thread will aquire the lock
    // all other threads will have to wait
    
}

void Minotaur::RequestCupcake()
{
    cupcakePresent = true;
}

void Minotaur::ConsumeCupcake()
{
    cupcakePresent = false;
}

bool Minotaur::plateEmpty()
{
    return (cupcakePresent == false);
}
