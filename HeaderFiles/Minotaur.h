#ifndef MINOTAUR_H
#define MINOTAUR_H

#include <unordered_set>
#include <stdlib.h>
#include "GuestHandler.h"

class Minotaur
{
    public:
        void InviteGuest();
        void RequestCupcake();
        void ConsumeCupcake();
        bool plateEmpty();
        void beginParty();

    private:
        const int maxGuestsInside = 1;
        bool cupcakePresent = true;
        // The int will be represented by the thread ID.
        std::unordered_set<int> trackedGuests;
        

};

#endif