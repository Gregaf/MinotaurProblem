#include "../HeaderFiles/GuestHandler.h"


void GuestHandler::start(int numberOfGuests)
{
    

    for(int i = 0; i < numberOfGuests; i++)
    {
        mGuests.emplace_back(std::thread(&GuestHandler::test, this));
        
    }

}

void GuestHandler::test()
{
    {
        std::lock_guard<std::mutex> lock {mEventMutex};
        std::cout << "This is thread " << std::this_thread::get_id() << std::endl;
    }
}

void GuestHandler::stop()
{

}