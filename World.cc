#include"World.h"
#include"Goat.h"
#include"Grass.h"

World::World(int n, int s):randomNumber(s){
	days= n;
	p= NULL;
	//initialize board
	for(int i=0; i<maximumRow; i++){
		for(int j=0; j<maximumColumn; j++){
			board[i][j]= NULL;
		}
	}
	/*initialize board*/
	int gen_Goat=5;
	int gen_Grass=10;

	//generate goats on board
	while(gen_Goat >0){

		int	x= randomNumber.getRandomNum(0, 19);
		int	y= randomNumber.getRandomNum(0, 34);
		if(isEmpty(x, y)){
			board[x][y]= new Goat(*this, 'X', x, y);
			gen_Goat--;
		}
	}

	//generate grass on board
	while(gen_Grass >0){

		int	x= randomNumber.getRandomNum(0, 19);
		int	y= randomNumber.getRandomNum(0, 34);

		if(isEmpty(x, y)) {
			board[x][y] = new Grass(*this, 'I', x, y);
			gen_Grass--;
		}
	}

}


void World::mainLoop(int d){

	while(days>0){

		/*traverse the board*/
		for(int i=0; i<maximumRow; i++){
			for(int j=0; j<maximumColumn; j++) {
				//pick a creature or an empty space
				p = board[i][j];
				if (p != NULL && !(p->isDone())) {
					p->act();
				}
			}
		}
		//display the board after each displayInterval
		if(days%d == 0){
			display();
		}
		/* set not done*/
		for(int i=0; i<maximumRow; i++){
			for(int j=0; j<maximumColumn; j++) {
				//pick a creature or an empty space
				p = board[i][j];
				if (p != NULL) {
					p->setDone(false);
				}
			}
		}
		days--;
	}

}
void World::putCreature(Creature *o,int x, int y){
	board[x][y]= o;
}
Creature* World::getCreature(int x, int y){
	return board[x][y];
}
RandomNum World::getRand(){
	return randomNumber;
}
/*check is an empty space*/
bool World::isEmpty(int x, int y){
	p= board[x][y];	//pick up the creature
	return (p == NULL);
}


bool World::isBoundary(int x, int y){
	return (x<0 || y<0||y>=maximumColumn || x>=maximumRow);
}

void World::display(){

	for(int i=0; i<=maximumRow+1; i++){	//maximumRow+1 for print '-'
		for(int j=0; j<=maximumColumn; j++){
			if(i > 0 && i<=maximumRow ) {
				if (j == 0) {
					cout <<(i-1) % 10<<"  ";    //output row boundary
				} else {
					/*output the creature*/
					p = board[i - 1][j - 1]; //i!=0 && j!=0
					if(p == NULL){
						cout<<' '<<" ";
					}else {
						cout << p->getType()<<" ";
					}
				}
			}else if(i == 0){
				cout<<" "<<j%10;	//output column boundary
			}else{	//i == maximumRow+1
				cout<<"--";
			}
		}
		cout<<endl;
	}
}
void World::die(int x, int y){
	delete board[x][y];
	board[x][y]= NULL;
}
