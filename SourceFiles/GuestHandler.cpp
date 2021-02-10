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

// The regular guest can eat one cupcake, and does not request a new one if the plate is empty
void GuestHandler::regularGuest()
{
    int cupcakesEaten = 0;

    while(mMinotaur->gameRunning())
    {
        // Scope of the lock...
        {
            std::lock_guard<std::mutex> lock{mEventMutex};
            mMinotaur->EnterLabyrinth(std::this_thread::get_id());
            //std::cout << "Guest " << std::this_thread::get_id() << " enters the labyrinth" << std::endl;

            if (cupcakesEaten <= 0 && !mMinotaur->plateEmpty())
            {
                cupcakesEaten++;
                mMinotaur->ConsumeCupcake();
            }

            if(mMinotaur->plateEmpty())
            {
                // Do nothing
            }      
        }
    }
}

// The counter guest is responsible for counting the number of times the plate is empty.
// The strategy employs allowing only eating one cupcake.
// And the counter is the only one who will request a cupcake
void GuestHandler::counterGuest()
{
    int counter = 0;
    int cupcakesEaten = 0;

    while(mMinotaur->gameRunning())
    {
        // Scope of the lock...
        {
            std::lock_guard<std::mutex> lock{mEventMutex};
            mMinotaur->EnterLabyrinth(std::this_thread::get_id());
            //std::cout << "CGuest " << std::this_thread::get_id() << " enters the labyrinth" << std::endl;

            if (cupcakesEaten <= 0 && !mMinotaur->plateEmpty())
            {
                cupcakesEaten++;
                mMinotaur->ConsumeCupcake();
            }

            if(mMinotaur->plateEmpty())
            {
                counter++;
                mMinotaur->RequestCupcake();
            }


            if(counter == mNumberOfGuests)
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
