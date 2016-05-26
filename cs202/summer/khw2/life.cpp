/*
   LIFE.CPP

   SR Kanna
   HW1&2
   CS202
   6/26/2015

   PURPOSE OF FILE: This is .CPP the player class which is of life class. The algorithms which it utlizes include figuring out the number of lives (which is protected data member, adding to the number of lives, counting the number of lives all of wich assist the manager class.
   There is no data structure used in tis file, its simply a class which is utilized by the data structures. 
 */

#include "life.h"
//default constructor. Sets the default value. No input or output
life::life()
{
	count_life = 3;
}


//copy constructor - copies the implicit instance of the life using the this ptr and from the life object. Input is constant object of the class. No output
life::life(const life & life_obj)
{
	this->count_life = life_obj.count_life;
}


//destructor - no dynamic memory. No input or outpout.
life::~life()
{

}


//remove a life from the player if they encounter a particular interection. No inpout or output.
void life::remove_life()
{
	count_life=count_life-1;
}


//add a life to the player if they have more than 5 pts. Takes in an integer as in inpout called by te manager class. No output
void life::add_life(int count)
{
	count_life = count_life+count;
}


//display the number of lives the player has. Output is display. No input
void life::display_life()
{
	cout << "The number of lives you have is: " << count_life << endl;
}


//Getter. No inpout, output is the count_life integer
int life::get_life() 
{
	return count_life;
}
