/*
   PRIZE.CPP
   SR Kanna
   HW1&2
   7/25/2015

   PURPOSE OF FILE: This is .CPP the player class which is of prize class. The algorithms which it utlizes include figuring out the number of prizes (which is protected data member, adding to the number of prizes, counting the number of prizes all of wich assist the manager class.
   There is no data structure used in tis file, its simply a class which is utilized by the data structures. 
 *

 */


#include "prize.h"
using namespace std;


//prize defualt constructor -initializing values
prize::prize()
{
	coin = 0;
}



//copy constructor - copies the implicit instance of the life using the this ptr and from the prize object. Input is constant object of the class. No output
prize::prize(const prize & prize_obj)
{
	this->coin = prize_obj.coin;
}


//no dynamic memory. No input/output
prize::~prize()
{

}


//will remove the number of coins if more than 5. Takes input of of whatever you wantw ill remove and no return
void prize::remove_coin(int life)
{
	int remove = life*5;		//remove 
	coin = coin-remove;
}


//function to add coins to the prizes - allows you add lives if count is more than 5. Will take input and take input of whatever you would like and will return depending on if you can add a life or not
int prize::add_coin(int add_value)
{
	coin+=add_value;
	//	cout << "I'm inside the add_coin function. I have this many coins " << coin << endl;
	if(coin >=5)
	{
		int count_life = coin/5;		//count how mmany lives they have earned and pass into the life function
		//	life::remove_coin(count_life);
		return count_life;
	}
	else
		return 0;
}


//display fucntion no input/output
void prize::display()
{
	cout << "The number of coins you have is: "<<coin << endl;
}
