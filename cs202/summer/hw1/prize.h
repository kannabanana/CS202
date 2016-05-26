/*
SR Kanna
HW1&2
7/25/2015

   PURPOSE OF FILE: This is the .H of the prize, which contains all the prototypes
   They would want to use this file because it contains all of the prize functions and the classes functions it contains (the methods) because it gives them access to increase/decrement the player's prizes
 

PRIZE.H



*/

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
//these two are the random
#include <time.h>
#include <stdlib.h>
using namespace std;


//class prize is in charge of the prizes
class prize
{
public:
	prize();			//constructor I/O: nothing
	prize(const prize &);		//constructor w/arguments I: const object of te class
	~prize();			//destructor		I/O: Nothing

	void remove_coin(int life);	//remove coin		I: integer to remove the  in an integer as

	int add_coin(int add_value);		//add coin I:integer which says how many coints ot add O: returns if the number of coins is significant enough to add a life
	void display();			//display I/O: Nothing


protected:
	int coin;			//the number of coints a player has
};
