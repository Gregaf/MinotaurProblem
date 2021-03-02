#ifndef GUESTHANDLER_H
#define GUESTHANDLER_H

#include <thread>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <iostream>
#include <vector>
#include <queue>
#include "Minotaur.h"


// Going to have to store all the threads in once instance that they all reference
// That way they will actually be operating on the same function with their local stacks.
class GuestHandler
{   
    private:
        int mNumberOfGuests;
        bool mReady = true;
        Minotaur* mMinotaur;
        std::condition_variable mEvent;
        std::mutex mEventMutex;
        std::vector<std::thread> mGuests;
        void regularGuest();
        void counterGuest();
        void showcaseGuest();
        void viewShowcase();
        void stopViewing();
        

    public:
        GuestHandler(int n, Minotaur* mino)
        {
            mNumberOfGuests = n;
            this->mMinotaur = mino;
            
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

        void readyLabyrinth();
        void readyShowcase();


};

#endif