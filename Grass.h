#ifndef _GRASS_H
#define _GRASS_H

#include"Creature.h"

class Grass: public Creature{
    public:
        Grass(World &world, char type, int x, int y);
        virtual ~Grass(){};
        // simulate a grass
        void act();
        // sprout new grass
        void born();
        // check whether can born new grass
        bool isLegalAge();
        // check whether should die
        bool shouldDie();

    private:

};
#endif
