#include"Goat.h"

/*
 * construct a goat
 */
Goat::Goat(World &w, char t, int x, int y):Creature(w, t, x, y){
    //set location
    setPosition(x, y);
    foodPoints= 20;
    setDone(false);
}
/*
 * simulate a goat's life cycle:
 *  age>=70 or food points =0 -> die
 *  50<= age <=55 -> born baby goat
 *  the rest time  -> pass and eat
 */
void Goat::act() {
    if (shouldDie()) {
        world.die(X, Y);
    } else {
        if (isLegalAge()) {
            born();
        } else {
            pass();
        }
        age++;
    }

}
/*
 * move one step , consume 1 points
 */
void Goat::pass(){

    //random select one direction
    int i= world.getRand().getRandomNum(0,3);

    //next location
    int x= X+dx[i];
    int y= Y+dy[i];

    /*check whether is boundary or a space*/
    if(!world.isBoundary(x, y)){

        //not empty: grass or goat
        if(!world.isEmpty(x, y)){
            if((world.getCreature(x, y)->getType()) == 'I'){	//is grass: gain 5 points and loss 1 point with pass
                foodPoints+=4;
                delete (world.getCreature(x, y)); //delete grass
                world.putCreature(this, x, y);	//pass to the destination
                world.putCreature(NULL, X, Y);
                //update the location
                setPosition(x, y);
                setDone(true);
            }else{ //is goat: can not pass
                return;
            }
        }else{ //empty: goat pass
            foodPoints--;
            //update the location
            world.putCreature(this, x, y);	//pass to the destination
            world.putCreature(NULL, X, Y);

            setPosition(x, y);
            setDone(true);
        }
    }
}

/*
 *born a babe in random direction(remember to check age in the world)
 */
void Goat::born(){

    //try every direction to born
    for(int i=0; i<4; i++){

        //next location
        int x= X+dx[i];
        int y= Y+dy[i];

        if(!world.isBoundary(x, y)){
            /*check whether is a space*/
            //not empty: grass or goat
            if(!world.isEmpty(x, y)){
                if((world.getCreature(x, y))->getType() == 'I'){	//is grass: mommy goat gain 5 points and born a babe
                    foodPoints+=5;
                    world.putCreature(new Goat(world, 'X', x, y), x, y);
                    setDone(true);	//set mommy goat's action is done
                    break;	//born a babe at once
                }else{	//has goat
                    continue;
                }
            }else{	//empty: born a babe
                world.putCreature(new Goat(world, 'X', x, y), x, y);
                setDone(true);	//set mommy goat's action is done
                break;
            }

        }
    }
}
/*
 * check age
 */
bool Goat::isLegalAge(){
    return (age>=50 && age<=55);
}
/*
 * To check whether the goat should die.
 */
bool Goat::shouldDie(){
    return (age>=70 || foodPoints <= 0);
}
