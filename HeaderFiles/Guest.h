#ifndef GUEST_H
#define GUEST_H

#include <thread>
#include <iostream>

using std::thread;
using std::cout;

class Guest
{   
    private:
        void execute();
        
    public:
        std::thread threadObj;
        void start();
        Guest()
        {
            //threadObj = thread(&Guest::execute, this);
        }

        //~Guest() { threadObj.join(); }
        ~Guest() { }

};

#endif