#include "../HeaderFiles/GuestHandler.h"

void GuestHandler::readyLabyrinth()
{
    mGuests.clear();

    mMinotaur->beginParty();

    for (int i = 0; i < (mNumberOfGuests - 1); i++)
    {
        mGuests.emplace_back(std::thread(&GuestHandler::regularGuest, this));
    }

    mGuests.emplace_back(std::thread(&GuestHandler::counterGuest, this));

}


void GuestHandler::readyShowcase()
{
    mGuests.clear();

    mMinotaur->beginParty();

    for (int i = 0; i < (mNumberOfGuests); i++)
    {
        // Need to figure out a way to store same thread in my vector and my queue...
        mLine.emplace(std::thread(&GuestHandler::showcaseGuest, this));
    }

    // Loop again and put all the threads in the queue. 
}

// Build the line within here
void GuestHandler::showcaseGuest()
{
    while(mMinotaur->gameRunning())
    {
        std::unique_lock<std::mutex> lock{mEventMutex};
        while(!mReady) mEvent.wait(lock);
        
        viewShowcase();
    }
}

void GuestHandler::viewShowcase()
{
    mReady = false;
    // Print some stuff....
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "I guest # " << std::this_thread::get_id() << " took my look!!" << std::endl;

    stopViewing();
}

void GuestHandler::stopViewing()
{
    mReady = true;
    mEvent.notify_all();
}
// The regular guest can only request one cupcake, and leaves otherwise
void GuestHandler::regularGuest()
{
    int replaced = 0;

    while(mMinotaur->gameRunning())
    {
        // Scope of the lock...
        {
            std::lock_guard<std::mutex> lock{mEventMutex};

            // Adds this thread to the list of tracked threads to ensure proper success declaration
            mMinotaur->EnterLabyrinth(std::this_thread::get_id());

            // Guests only replace the cupcake onetime, and never eat any.
            if (replaced <= 0 && mMinotaur->plateEmpty())
            {
                replaced++;
                mMinotaur->RequestCupcake();
            }     
        }
    }
}

// The counter guest is responsible for counting the cupcakes he eats.
// The strategy employs allowing only eating the cupcakes
void GuestHandler::counterGuest()
{
    int cupcakesEaten = 0;

    while(mMinotaur->gameRunning())
    {
        // Scope of the lock...
        {
            std::lock_guard<std::mutex> lock{mEventMutex};

            // Adds this thread to the list of tracked threads to ensure proper success declaration
            mMinotaur->EnterLabyrinth(std::this_thread::get_id());

            // If the plate is not empty, then eat the cupcake and track the count of cupcakes eaten.
            if (!mMinotaur->plateEmpty())
            {
                cupcakesEaten++;
                mMinotaur->ConsumeCupcake();
            }

            // If number of cupcakes eaten equals the amount of guests, then everyone has entered. Declare success.
            if(cupcakesEaten == (mNumberOfGuests))
            {
               bool correct = mMinotaur->verifySuccess(mNumberOfGuests);

                if(correct)
                    std::cout << "The minotaur is pleased" << std::endl;
                else
                    std::cout << "The minotaur stares intensely" << std::endl;
            }
            
        }
    }
}
