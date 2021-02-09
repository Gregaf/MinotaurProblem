#include <iostream>
#include <thread>
#include "../HeaderFiles/Guest.h"
#include "../HeaderFiles/Counter.h"
#include <vector>

using std::cout;

int main()
{
    Counter* guests = new Counter[5];
    
    for (int i = 0; i < 5; i++)
    {
        guests[i].start();

    }

    for (int i = 0; i < 5; i++)
    {
        guests[i].threadObj.join();
    }

    delete guests;

    system("pause");

    return 0;
}
