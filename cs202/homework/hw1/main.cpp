/*

   SR Kanna
   4/17/2015
   CS202
   HW1
   Main.cpp
   Purpose: This is where I interact with my client program

   Program Description: This program plays Go Fish. There is one user and they can play Go Fish with the computer. Seven cards are initially drawn from the deck and given to the player and computer. They take turns going until one of them looses all their cards (which makes either one the winner). The other person asks a question for the other player, they get all the cards from the other player if they guess the card right, otherwise they draw from the deck. If they have a match of four "a book", they remove those cards from their hand.
 
 */

//Personal Note:
//SIZE OF ARRAY IS 13 -

//0 -2
//1 - 3
//2 - 4
//3 - 5
//4 - 6
//5 - 7
//6 - 8
//7 - 9
//8 - 10
//9 - Jack (11)
//10 - Quen (!2)
//11 - King (13)
//12 - Ace (14)



#include "deck.h"
using namespace std;


int main()
{

	//declaration of class objections:
	general general_go_fish;
	human human_go_fish;
	computer computer_go_fish;
	deck deck_go_fish(4);			//constuctor for deck
	card card_go_fish;
	node node_go_fish;




	general * ptr = &human_go_fish;				//dynamic biding to human - "have base class"
	general * ptr2 = &computer_go_fish;			//dynamic binding to computer - "have base class"

	//insert cards into the player's hand:
	int card = 0;
	for (int i = 0; i < 7; ++i)
	{
		card = deck_go_fish.random_shuffling();
		human_go_fish.insert(card);
	}


	//insert cards into the computer's hand:
	for (int i = 0; i < 7; ++i)
	{
		card = deck_go_fish.random_shuffling();
		computer_go_fish.insert(card);
	}


	cout << "WELCOME TO THE GO FISH GAME! " << endl << "You can go first! " << endl << endl;
	cout << "This is the key for cards: 11 - Jack. 12 - Queen. 13 - King. 14- Ace" << endl;


	while (!general_go_fish.is_empty())				//continue until either player has an empty hand
	{
		human_go_fish.ask_question(&human_go_fish,&computer_go_fish,deck_go_fish);
		computer_go_fish.ask_question(&computer_go_fish, &human_go_fish,deck_go_fish);
	}

	return 0;
};
