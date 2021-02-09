#ifndef GUESTHANDLER_H
#define GUESTHANDLER_H

#include <thread>
#include <iostream>
#include <mutex>

using std::thread;
using std::cout;

// Going to have to store all the threads in once instance that they all reference
// That way they will actually be operating on the same function with their local stacks.
class GuestHandler
{   
    private:
        const int maxCanEat = 1;
        void execute();
        
    public:
        std::thread threadObj;
        void intialize();
        void start();
        GuestHandler()
        {
            //threadObj = thread(&Guest::execute, this);
        }

        //~Guest() { threadObj.join(); }
        ~GuestHandler() { }

};

#endif