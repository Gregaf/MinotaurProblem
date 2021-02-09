#include "../HeaderFiles/GuestHandler.h"

std::mutex mtx;

void GuestHandler::execute()
{
    int cupcakesEaten = 0;

    // Some sort of loop to ensure that none stop until success condition.

}

void GuestHandler::start()
{
    threadObj = thread(&GuestHandler::execute, this);
}
