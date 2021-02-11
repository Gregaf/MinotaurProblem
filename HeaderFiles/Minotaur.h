#ifndef MINOTAUR_H
#define MINOTAUR_H

#include <thread>
#include <iostream>
#include <unordered_set>


class Minotaur
{
    public:
        void RequestCupcake();
        void ConsumeCupcake();
        void beginParty();
        bool plateEmpty();
        void EnterLabyrinth(std::thread::id ID);
        bool verifySuccess(int n);
        bool gameRunning();

    private:
        bool isGameRunning = false;
        bool cupcakePresent = true;
        // The int will be represented by the thread ID.
        std::unordered_set<std::thread::id> trackedGuests;
        

};

#endif