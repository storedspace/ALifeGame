#ifndef _GOAT_H
#define _GOAT_H

#include"Creature.h"

class Goat: public Creature{
    public:
        // constructor
        Goat(World &world, char type, int x, int y);
        // destructor
        virtual ~Goat(){};
        // simulate a goat
        void act();
        // move one step
        void pass();
        // born a babe
        void born();
        // check whether could born a babe
        bool isLegalAge();
        // check whether should die
        bool shouldDie();
    private:
        int foodPoints;

};
#endif
