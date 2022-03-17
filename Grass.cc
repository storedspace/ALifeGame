#include"Grass.h"
/*
 * construct Grass
 */
Grass::Grass(World &w, char t, int x,int y):Creature(w, t, x, y){
    //set location
    setPosition(x, y);
    setDone(false);
}
/*
 * simulate grass life cycle:
 *  age >=6      -> die
 *  3<= age <=5  ->sprout new grass
 */
void Grass::act(){
    if (shouldDie()) {
        world.die(X, Y);
    } else {
        if (isLegalAge()) {
            born();
        }
        age++;
    }
}
/*
 * grow new grass
 */
void Grass::born(){

    //try every direction to born
    for(int i=0; i<4; i++){

        //next location
        int x= X+dx[i];
        int y= Y+dy[i];

        if(!world.isBoundary(x, y)){

            /*check whether is a space*/
            //not empty: grass or goat
            if(!world.isEmpty(x, y)){
                //try the other directions
                continue;
            }else{	//empty: sprout
                world.putCreature(new Grass(world, 'I', x, y), x, y);
                break;	//sprout at once
            }
        }
    }
}
/*
 * check age
 */
bool Grass::isLegalAge() {
    return (age >= 3 && age <= 5);
}
/*
 * To check whether the grass should die.
 */
bool Grass::shouldDie(){
    return (age>=6);
}
