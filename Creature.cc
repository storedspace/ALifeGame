#include"Creature.h"

Creature::Creature(World &w, char t, int x, int y):world(w){
    //set location
	setPosition(x, y);
    //set age
    age=0 ;
    //set type
    type= t;

}
Creature::~Creature(){
}
void Creature::setPosition(int x, int y){
    this->X= x;
    this->Y= y;
}

void Creature::setDone(bool d){
    done= d;
}
bool Creature::isDone(){
    return done;
}
char Creature::getType(){
    return type;
}

