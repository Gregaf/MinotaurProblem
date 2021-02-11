#include "../HeaderFiles/GuestHandler.h"

void GuestHandler::start(int numberOfGuests)
{
    mMinotaur->beginParty();

    for (int i = 0; i < (numberOfGuests - 1); i++)
    {
        mGuests.emplace_back(std::thread(&GuestHandler::regularGuest, this));
    }

    mGuests.emplace_back(std::thread(&GuestHandler::counterGuest, this));

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
