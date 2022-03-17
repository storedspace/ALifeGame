#ifndef _CREATURE_H
#define _CREATURE_H

// direction      N   S   W   E
const int dx[4]= {0,  0, -1,  1};
const int dy[4]= {1, -1,  0,  0};

#include"World.h"
class World;

class Creature{
public:

    Creature(World &world, char type, int x, int y);
    virtual ~Creature();
    // set a creature's position
    void setPosition(int x, int y);
    // set a creature "done" after an action
    void setDone(bool done);
    // ask whether the creature have done
    bool isDone();
    // return creature's type
    char getType();
    // derived class implement
    virtual void act() =0;
    virtual void born() =0;
    virtual bool isLegalAge()=0;
    virtual bool shouldDie() =0;

protected:
    World &world;
    // current position
    int X;
    int Y;

    int age;
    char type;
    bool done;
};
#endif