#ifndef GUESTHANDLER_H
#define GUESTHANDLER_H

#include <thread>
#include <condition_variable>
#include <iostream>
#include <vector>
#include "Minotaur.h"


// Going to have to store all the threads in once instance that they all reference
// That way they will actually be operating on the same function with their local stacks.
class GuestHandler
{   
    private:
        Minotaur* mMinotaur;

        std::condition_variable mEvent;

        std::mutex mEventMutex;
        bool mStopping = false;

        std::vector<std::thread> mGuests;    
        void start(int numberOfGuests);
        void stop();
        void regularGuest();
        void counterGuest();
        
        int mNumberOfGuests;
        
    public:
        GuestHandler(int n, Minotaur* mino)
        {
            mNumberOfGuests = n;
            this->mMinotaur = mino;
            start(n);
        }

        ~GuestHandler() 
        { 
            for(auto &thread : mGuests)
            {
                if(thread.joinable())
                    thread.join();
                else
                    std::cout << "Can't join." << std::endl;
            }
        }

};

#endif