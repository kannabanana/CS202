/*
   LIFE.H

   SR Kanna
   HW1&2
   CS202
   6/26/2015

   PURPOSE OF FILE: This is the .H of the life, which contains all the prototypes
   They would want to use this file because it contains all of the life functions and the classes functions it contains (the methods) because it gives them access to increase/decrement the player's life
 */

#include "prize.h"
#ifndef _LIFE_H
#define _LIFE_H
//class life is in charges of lives
class life			//inherited from player class
{

	public:
		life();		//default constructor 	I/O: nothing
		life(const life &);	//copy constructor I: constant object Copy constructor
		~life();		//deconstructor I/O: Noting

		void remove_life();	//remove function I/O: Nothing
		void add_life(int life);	//add a life I: Takes a interger life to add a life
		void display_life();		//display life I/O: NOthing
		int get_life();			//getter of the number of lives I/O: NOthing

	protected:
		int count_life;			//number of lives
};

#endif
