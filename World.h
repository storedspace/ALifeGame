#ifndef _WORLD_H
#define _WORLD_H

#include<iostream>
#include"RandomNum.h"

#include"Creature.h"

using namespace std;

static const int maximumRow=20;
static const int maximumColumn=35;

class Goat;
class Grass;
class RandomNum;
class Creature;
class World{
	public:
		World(int numPass, int seed);
		~World(){};
		//main
		void mainLoop(int displayInterval);
		//get creature from the board
		Creature* getCreature(int x, int y);
		//put the creature on the board
		void putCreature(Creature *o,int x, int y);
		//check whether the place is empty
		bool isEmpty(int x, int y);
		// check whether the place is over boundary
		bool isBoundary(int x, int y);
		// make creature die
		void die(int x, int y);
		//display the board
		void display();
		//get the randomNumber from the board
		RandomNum getRand();
	private:
		Creature* board[maximumRow][maximumColumn];
		Creature *p;
		RandomNum randomNumber;
		int days;
	};
#endif
