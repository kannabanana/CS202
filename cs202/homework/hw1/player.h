/*
SR Kanna
CS202
HW1
4/6/2015

PLAYER.H

Purpose of File: This is the application program. It's human readable. This is the classes and prototypes for the player's hand. The deck is included in the begining because it is used in the ask question function.
Notes: 

INPUT: I
OUTPUT: O

*/

#include <iostream>
#include <stdlib.h>
#include "card.h"



//promising declaration of deck because deck is used in functions of general 
class deck;


//General player class - contains the ADT which holds the player hand
class general
{
	public:
		general();				//constructor to set the "hash table head points to NULL. Input: No Input. Output: No Output
		general(const general &); 		//copy constructor-have dynamic memory. I: None. O: None
		~general();				//destructor. I: None. O: None


//FUNCTIONS:
//data structure functions:
		void insert(int num);			//insert into "hash table". I: Take array location. O: None.
		int count_card(int card_number);	//count the number of same cards. I: Array location. O: How many nodes in linked list
		void remove_card(int num);		//remove cards of the same. I: Array location. O: None.
		int is_empty(void);			//checking to see if the players hand is empty - to determine winner. I: None. I: Sucess, failure
		void display(int size_of_hash_table);			//display the player's hand. I: Take size of array. O: Nothing.
		int match_function_wrapper(int num,general *, general *, deck &);	//wrapper function to access match function in card node. I: takes the number user wants, the other player's hand, and the deck. Output: True/False flags.

		int is_match(int num);			//match function to see if the other player has what. I: Array location. Output: True/False flag.

		virtual int ask_question(general *, general *, deck &);			//virutal dynamic binding. I: Takes a player and deck. O: true/false flags.

	protected:
		node ** player;				//head pointer
		int size_of_hash_table;			//size of array - 13 - # of cards
};


class human;		//included because ask_question function needs to pass human as a paramater of argument list


//class computer inherited from class general
class computer: public general
{
	public:
		computer();				//constructor. I/O: None
		~computer();				//Destructor. I/O: None

//FUNCTIONS:
		int random_number(void);		//find a number in the array randomly. I: None. I: Returns a random number
		int ask_question(general *, general *,deck &);	//function asks if the player has a card. I: Takes the human hand, and deck. O: Returns true/false flag.


	protected:
		//nothing
};



//class player inherited from class general - user gets to decide what to do - client interface
class human: public general
{
	public:
		human();		//constructor. I/O: Nothing
		~human();		//destructor. I/O: Nothing

//FUNCTIONS:
		int ask_question(general *, general *, deck &);		//function asks if the card  has a card. I: Takes in computer's hand and deck. O: True/False flag.

	protected:
		//nothing

};
