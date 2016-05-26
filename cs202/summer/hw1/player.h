/*
   PLAYER.H

   SR Kanna
   CS202
   6/22/2015


   FILE TYPE: .H implementation of the player class which contains all the prototypes. They would want to use this file because it contains all of the life functions and the classes functions it contains (the methods) because it gives them access to increase/decrement the player's life and the prizes. It also allows them to acces and add a name and description. 


 */


#include "life.h"


//PLAYER CLASS
class player
{
	//METHODS:
	public:

		player();				//Default constructor I/O: Nothing
		player(const player &);			//Copy Constructor I: player object O: Nothing
		player(char * name,char * description);	//constructor with arguments I:Name and Descirption O: Nothing
		~player();				//deconstructor  I/O: Nothing

		void display();				//displays name and description. I/O: Nothing
		void add_life(int path_value);		//add life takes an integer of any value and does not return anything

		//WRAPER FUNCTIONS:
		void display_life();			//display life does not take or return anything
		void display_coin();			//display coin does not tkae or reutn ranything
		void remove_coin_wr(int life);		//remove coin is  awrapper function that that calls the remove coin inside of prize. I: integer of wat you want to remove
		int add_coin_wr(int add_value);		//add coin is a wrapper tat adds an integer to however muc you want and returns the number of lives

		void remove_life_wr();			//remove life removes a life I/O: Noting
		void add_life_wr(int life);		//Add a life is a wrapper I: Adds a n life O: Noting
		int get_life();				//Getter of the number of lives I: NA O: Returns the number of livs

	protected:
		//FIELDS:
		char * description;			//description of the player
		char * name;				//name of the player
		prize a_prize;				//as a prize
		life a_life;				//has a life
};
