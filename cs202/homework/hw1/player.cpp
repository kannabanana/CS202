/*this is my player.cpp
  SR Kanna
  CS202
  HW1
  4/6/2015

  PLAYER.CPP:
  PURPOSE OF FILE: This is where the implementation of the PLAYER.H functions are. This contains all the functions which handle the player's hands (general, human and computer).

*/
#include "player.h"
using namespace std;


//constructor with arguments
general::general()
{
	srand(time(NULL));		//seeding
	int size = 13;			//setting the size of array to 13 (eventually)
	player = new node *[size];
	for (int i = 0; i < size; ++i)
	{
		player[i] = NULL;	//setting each array "head" ptr to NULL
	}		

	size_of_hash_table = size;	//setting size of the array to "size"
}


//copy constructor
general::general(const general & general_go_fish)
{
	size_of_hash_table = general_go_fish.size_of_hash_table;

}


//destructor
general::~general(void)
{
	for (int i = 0; i < 13; ++i)
	{
		if (player[i] != NULL)
		{
			node * temp = player[i];			//set temp to the head
			while (temp != NULL)
			{	
				temp = temp->go_next();			//set temp to the next
				delete player[i];			//delete the head
				player[i] = temp;			//set head to temp
			}
		}
	}
}


//call the display player's hand function
void general::display(int size_of_hash_table)
{
	//loop through array and go through linked list - 
	for (int i = 0; i < size_of_hash_table; ++i)
	{
		if (player[i] != NULL)
		{
			node * temp = player[i];			//set temp to head
			while (temp != NULL)
			{	
				cout << "**";	
				temp-> display_number();		//calling display function of card (node inherited from card)
				temp = temp->go_next();
			}
			cout << '\n';
		}
	}
} 


//function to insert into the player's hand
void general::insert(int num)
{
	int place_in_array = num;				//set the place in the array to number

	if (player[place_in_array] == NULL)			//check if the it's NULL
	{
		player[place_in_array] = new node(num+2);	//data is set to two higher because of 2-14
		player[place_in_array]-> go_next()  = NULL;

		return;
	}


	else							//if it's not NULL
	{
		node * temp = new node(num+2);			//data is set to "two higher"	
		temp-> go_next() = player[place_in_array];	//set temp's next to head
		player[place_in_array] = temp;			//set head to temp

		//call the count function - check if you have "book"
		int count =  count_card(place_in_array);	//check if it's NULL in that area
		if (count == 4)
		{
			cout << "Congragulations! You got a book for all the " << num+2 << " of a kind cards!!!" << endl;	//tell the user they got 4 of a kind
	
			for (int i = 0; i < 4; ++i)
			{
				remove_card(place_in_array);		//call the remove function
			}
			
			int game_over = is_empty();			//check if the player's hand is empty
			if (game_over == 0)
			{
				cout << "YOU WIN! " << endl;
			}
		}
		return;
	}
}



//function to count how many of the same kinds of cards you have
int general::count_card(int card_number)
{
	int count = 1;

	if(player[card_number] == NULL)			//checking if there are none of the cards
	{
		return 0;				//return 0
	}
	
	else
	{
		node * temp = player[card_number];	//set temp to head
		while (temp->go_next() != NULL)		//keep gooing until not NULL
		{
			temp = temp->go_next();		
			++count;
		}
		return count;
	}
}


//function to remove a card from the hand
void general::remove_card(int num)
{
if (player[num] == NULL)				//if the array is empty
	return;
if (player[num] != NULL)				//array is not empty
{

	if (player[num]->go_next() == NULL)		//only one piece of data
	{	
		delete player[num];			//delete it & set it to NULL
		player[num] = NULL;			//set head to NULL
		return;
	}

	if (player[num]->go_next() != NULL)		//if there's more than one piece of data
	{
		node * temp = player[num]->go_next();	//set temp to next of head
		delete player[num];			//delete head
		player[num] = temp;			//set head to temp
	
		return;
	}
}
}


//function to tell if the player's hand is empty
int general::is_empty(void)
{
	int count = 0;					//setting count
	for(int i = 0; i<13; ++i)			
	{
		if (player[i] != NULL)			//anything there is something in the array
			++count;			//increment count
	}
	
	if (count > 0)
		return 1;				//has values
	else
		return 0;				//empty
}


//checks to see if the card you have matches anything the other player may have
int general::is_match(int card_in_hand)
{
	if(player[card_in_hand] == NULL)
		return 0;			//returns 0 if no card
	else
		return 1;			//returns 1 if player has hand
}


//dynamic binding
int general::ask_question(general * general_go_fish, general * general_go_fish2, deck & deck_go_fish)
{
	cout << "Hello" << endl;

}


//computer constructor default
computer::computer():general()
{

}


//default computer deconstructor
computer::~computer()
{

}



//generate random number from 0-12
int computer::random_number(void)
{
	int num = (rand()%13);			//picks a random number between 0-12 (array size)
	return (num);				//returns a number between 1-13
}



//computer asks for a card from player
int computer::ask_question(general * computer_go_fish,general * human_go_fish, deck & deck_go_fish)
{
	int card = 0;				//variable to store random card
	do
	{
		card = random_number();
	}
	while(player[card] == NULL);		//continue drawing random integers through the array until a NULL head ptr isn't encountered

	cout << "Do you have a " << card+2 << "?" << endl;		//adds plus two to accomadate starting from 2 (2-14)
	match_function_wrapper(card,human_go_fish,computer_go_fish,deck_go_fish);	//call match function to check if the player if they do

	return 1;
}


//human default constuctor
human::human():general()
{

}


//human deconstructor
human::~human()
{


}


//the ask question function for the player - asks the computer
int human::ask_question(general * human_go_fish, general * computer_go_fish, deck & deck_go_fish)
{
	int card_number = 0;					//random card the player may want from the computer
	
	cout << "This is the Player's hand: " << endl;
	display(size_of_hash_table);
	
	cout << "What card would you like to ask the computer if it has?" << endl;
	cin >> card_number;
	cin.ignore(100,'\n');

	match_function_wrapper(card_number-2, computer_go_fish,human_go_fish,deck_go_fish);		//decrement to accomadate array
	
	cout << "This is the Player's hand (after): " << endl;
	display(size_of_hash_table);
	
	return 1;
}

