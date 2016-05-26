/*
   PLAYER.CPP

   SR Kanna
   CS202
   6/22/2015

   PURPOSE OF FILE: This is .CPP the player class which is of life class. The algorithms which it utlizes include figuring out the number of lives (which is protected data member, adding to the number of lives, counting the number of lives all of wich assist the manager class. It also is in charge of the number of prizes, remove etc. 
   There is no data structure used in tis file, its simply a class which is utilized by the data structures. 

 */


#include "player.h"

//default constructor. set default value. No input or value
player::player()
{
	description = NULL;		//setting description & name to null
	name = NULL;
}


//copy constructor - copies the implicit instance of the life using the this ptr and from the life object. Input is constant object of the class. No output
player::player(const player & player_obj)
{

	//using the this ptr to implicitly imply, dynamically allocate and copy the same info of the player object
	this->description = new char[strlen(player_obj.description)+1];
	strcpy(this->description,player_obj.description);

	this->name = new char[strlen(player_obj.name)+1];
	strcpy(this->name,player_obj.name);

	this->a_prize = player_obj.a_prize;
	this->a_life = player_obj.a_life;
}



//constructor with arguments when the user inputs the name and description of the player
player::player(char * name,char * description)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name,name);

	this->description = new char[strlen(description)+1];
	strcpy(this->description,description);
}


//destructor
player::~player()
{
//		delete [] description;
//		delete [] name;
}


//display function of the player's name and the description
void player::display()
{
	cout << "The name of the player is: "<<name <<". Their description is: "<<description << endl;
}


//display life NO input or output
void player::display_life()
{
	a_life.display_life();
}


//display coint no output or input
void player::display_coin()
{
	a_prize.display();
}

//function to add a life if the count is greater than five (based on the multiple of five)
void player::add_life(int path_value)
{
	int life = add_coin_wr(path_value);
	if (life != 0)
		add_life_wr(life);
}

//add a coin wraper (calls the prize add coin)
int player::add_coin_wr(int path_value)
{
	int lives = a_prize.add_coin(path_value);
	return lives;
}

//WRAPPER FUNCTIONS to remove a life No input or output
void player::remove_life_wr()
{
	a_life.remove_life();
}


//add a life wrapper. Input is to adda  lfie. no output
void player::add_life_wr(int life)
{
	a_life.add_life(life);
}


//getter of a life. No inpout, returns a life integer
int player::get_life()
{
	int life = a_life.get_life();
	return life;	
}
