/*
SR Kanna
HW1
CS202
4/5/2015

DECK.H
Purpose of File: This is the application program. It's human readable. This is the classes and contains the prototypes for the deck. The deck has a relation with card, so it is contained in another .h 

INPUT: I
OUTPUT: I
*/



//list of pound
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "player.h"	//uses general in match function

//class data structure 

class deck
{
	public:

		deck(int size = 4);	//default constructor - I:allocating the size of suit_array. O: Nothing
		deck(const deck &);	//copy constructor. I: Deck Class. O: Nothing
		~deck();		//deconstructor. I/O: Nothing
	
	
//FUNCTIONS:

		int is_empty(void);		//checking if the deck is empty. I: Nothing. O: True/False flags
		int random_shuffling(void);	//function to randomly pick a suit and card. I: Nothing. O: Returns a random card from the linked list to insert/remove

		int remove_from_deck(int suit_random,int card_random);	//card to remove from deck. I: The suit and card from a specific linked list. O: True/False flags
		void display(void);		//display the deck. I/O: Nothing	
		void insert_deck();		//Inserts cards into the deck. I/O: Nothing

	protected:

		node ** suit_array;		//dynamically allocated suit array
		int size_of_suit_array;		//size of the array of doubly linked list
};



