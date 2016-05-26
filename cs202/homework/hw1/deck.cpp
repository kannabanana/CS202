/*
SR Kanna
CS202
HW1
4/20/2015

DECK.CPP
PURPOSE OF FILE: This is where the implementation of the DECK.H and CARD.H are. This contains all the functions which handle the deck - including the card and nodes associated such as removing, displaying, checking if it's empty etc. 

*/

#include "deck.h"
using namespace std;


//constructor with arguments
deck::deck(int size)
{
	srand(time(NULL));				//seeding random number initilizier
	suit_array = new node *[size];			//allocating new nodes to the size of of "4"
	for (int i = 0; i < size; ++i)
	{
		suit_array[i] = NULL;			//setting head to NULL

	}
	size_of_suit_array = size;			//setting size of the array to 4
	insert_deck();					//inserting the cards into the deck
}



//deck copy constructor
deck::deck(const deck & deck_go_fish)
{
	size_of_suit_array = deck_go_fish.size_of_suit_array;

}



//deck deconstructor
deck::~deck()
{
	//doubly linked list
	//size of array is 4
	for (int i = 0; i< size_of_suit_array; ++i)
	{	
		if (suit_array[i] != NULL)
		{
			node * temp = suit_array[i];		//temp is set to head
			while (temp != NULL)			//while it's not NULL
			{
				temp = temp-> go_next();	
				delete suit_array[i];		//delete head
				suit_array[i] = temp; 		//set head to temp

			}
		}
	}
	delete [] suit_array;					//delete the array
}



//function to check if the deck is empty
int deck::is_empty(void)
{
	int count = 0;					//set the count to NULL
	for (int i = 0;i<size_of_suit_array;++i)
	{
		if(suit_array[i] != NULL)
			++count;			//1 means the deck isn't empty
	}
	if (count > 0)
		return 1;			//0 means the deck is not empty
	else
		return 0;			//1 means deck is empty
}



//function to pick two random numbers - one of the array and one out of 1-13 to prevent memory shifting so it appears like the deck is shuffling to the client
int deck::random_shuffling(void)
{

	int suit_random =0;				//imitilize the random number for the suit to zero
	do
	{
		suit_random = (rand()%4);		//draw a random number 0-3
	}
	while (suit_array[suit_random] == NULL);

	int card_random = 0;				//initilize the card in the linked list to zero
	{
		card_random = (rand()%13);		//0-13 - draws for the array						
	}
	


	node * temp = suit_array[suit_random];					//set temp to head of right array
	while (temp->go_next() != NULL && !(temp->compare(card_random+2)))	//until the next is not NULL and you're not at the right card
	{
		temp = temp->go_next();
	}

	int remove = temp->get_card_number(temp);		//get the data of temp and store it in an integer
	remove_from_deck(suit_random,remove);
	return (remove-2);					//decrement 2 because of array positioning


}



//remove a card from the deck
int deck::remove_from_deck(int suit_random, int card_random)
{
	//case 1: only one
	if (suit_array[suit_random]->go_next() == NULL)
	{
		delete suit_array[suit_random];				//delete the head
		suit_array[suit_random] = NULL;				//set it NULL
		return 0;		//success
	}


	node * temp = suit_array[suit_random];				//set temp to head
	//case two: more than two

	while (temp->go_next() && !(temp->compare(card_random+2)))	//keep going until you're not the end of the list and you're not the data
	{
		temp = temp->go_next();
	}
	node * prev = temp->go_previous();				//previous is set to temp's previous
	node * next = temp->go_next();					//next is set to temp's next
	if (prev) prev->go_next() = next;
	if (next) next->go_previous() = prev;

	delete temp;
	return 0;
}



//display function to display deck
void deck::display(void)
{
	for (int i = 0; i < size_of_suit_array;++i)
	{
		if(suit_array[i] != NULL)				//as long as you're not at the end of list
		{
			node * temp = suit_array[i];			//set temp to head
			while (temp != NULL)
			{
				temp->display();			//display the number and suit (display is part of card)
				temp = temp->go_next();
			}
		}
		cout << '\n';						//newline for each suit
	}
}



//build doubly linked list
//constructor with arguments
void deck::insert_deck()
{
	for (int i = 0; i<size_of_suit_array;++i)					//insert 4 times (for 4 suits)
		{
			if (suit_array[i] == NULL)					//if head is NULL
			{
				suit_array[i] = new node(14,i);				//insert backwards - 14 beccause 2-14
				suit_array[i] ->go_next() = NULL;
				suit_array[i] ->go_previous() = NULL;

			}
			if (suit_array[i] != NULL)					//if head is not NULL
			{
				{
					for(int j=13;j>1;--j)				//go backwards until you reach 2
					{	
						node * temp = new node(j,i);		//call constructor of node - initilization list!
						temp-> go_next() = suit_array[i];
						suit_array[i]->go_previous() = temp;
						suit_array[i] = temp;
					}
				}	
			}
		}
}





//card default
card::card()
{
		number = 0;
		suit = 0;

}



//card constructor with arguments
card::card(int new_number,int new_suit)
{

		number = new_number;
		suit = new_suit;
}


//card w/arguments
card::card(int new_number)
{

	number = new_number;
}


//copy constructor
card::card(const card & card_go_fish)
{
	number = card_go_fish.number;

	suit = card_go_fish.suit;
}



//card destructor
card::~card()
{
	//no dynamic memory
}


//display function
void card::display(void)
{

	cout << number << " ";
		if (suit == 0)
			cout << "Diamonds" << "      ";				//specifiying for each suit
		else if (suit == 1)
			cout << "Clubs" << "        ";
		else if(suit == 2)
			cout << "Spades" <<"        ";
		else if(suit ==3)
			cout << "Hearts" <<"        ";

}


//compare function checks if the card has the same number
int card::compare(int to_compare)
{
	if(number == to_compare)
		return 1;			//sucess
	else
		return 0;			//fail
}



//display only displays card
void card::display_number(void)
{

	cout << number << endl;
}


//default constructor
node::node()
{
	next = NULL;
	previous = NULL;
}


//constructor w/arguments - initilization list
node::node(int number,int suit):card(number,suit)
{
	
}


//constuctor with arguments initilization list
node::node(int number):card(number)
{

}


//constructor with arguments
node::node(node * next,node * previous)
{

		next = NULL;
		previous = NULL;	
}



//copy construcotr is initilization list
node::node(const node & node_go_fish):card(node_go_fish)
{

}


//destructor
node::~node()
{
		next = NULL;
		previous = NULL;
}


//pass back to node's number (because it's protected data member)
int node::get_card_number(node * head)
{
	return head->number;
}




//setter and getters
node *& node::go_next()
{	
		return next;
}


//setters and getters
node *& node::go_previous()
{
		return previous;
}


//wrapper function to call the match function in card
int general::match_function_wrapper(int num,general * questioner, general * asker, deck & deck_go_fish)
{
	int count = questioner->is_match(num);		//check if they have it 	
	
	if (count == 1)		//player was right
	{
		int the_ints = questioner->count_card(num);
		for (int i = 0;i < the_ints; ++i)
		{
			insert(num);			//needs to be inserted into other class
			questioner->remove_card(num);		//needs to be removed from the general class - one specified on the argument
		}

			asker->ask_question(asker,questioner,deck_go_fish);
	}

	if (count == 0)
	{
		int empty = is_empty();	//check if deck is empty
		if (empty == 0)
		{
			cout << "The Deck is Empty :(! It's a draw!" << endl;
			return 0;
		}
		if (empty != 0)
		{
			cout << endl << "No Dice. GO FISH!" << endl;
			int num = deck_go_fish.random_shuffling();			//call shuffle function to pick random number to insert (2-14)
			insert(num);		//insert into player's hand}		//insert that card into player's hand
		}
	}
	return 1;
}
