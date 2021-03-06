/*
   MANAGER.CPP

   SR Kanna
   6/27/2015
   HW1&2
   CS202

   PURPOSE OF FILE: This is .CPP the player class which is of manager class. The algorithms which it utlizes include figuring out the number of prizes (which is protected data member, adding to the number of prizes, counting the number of prizes all of wich assist the manager class. It also figures out the number of lives, removing lives and helps the user traverse the tree.
   There is no data structure used in tis file, its simply a class which is utilized by the data structures. 

 */


#include "manager.h"
//default constructor
manager::manager()
{

}

//copy constructor - copies the implicit instance of the life using the this ptr and from the prize object. Input is constant object of the class. No output
manager::manager(const manager & manager_obj)
{

//	this->a_player = manager_obj.a_player;
//	this->a_bst = manager_obj.a_bst;
//	this->a_graph = manager_obj.a_graph;

}


//destructor I/O: nothing
manager::~manager()
{

}


//retrieve wrapper: Nothing (I/O)
void manager::retrieve_wr(int num)
{
	a_bst.retrieve_wr(num);
}

//wrapper to call bst dispaly function I/O: Nothing
void manager::display_wr()
{
	a_bst.display_wr();
}


void manager::display_wr2()
{
	a_graph.display_adjacency_list();
}

//wrapper to call create and insert function I/O: Nothing
void manager::create_path_wr()
{
	a_bst.create_path_wr();
}


void manager::create_path_wr2()
{
	a_graph.insert_vertex();
	a_graph.create_edges();
}


//remove an edge connecting two verticies
void manager::remove_wr(int first,int second)
{
	a_graph.remove(first,second);
}


//instructions for level one I/O: Nothing
void manager::instructions()
{
	cout << "Hello Player! Welcome to level one of the Maze Runner. Can you get out? We doubt it! " << endl;

	cout << "You may go right, left on your first turn and then go right/left or backwards. You will encounter deaths (up to three and then game over) and prizes." << endl << endl;

	cout << "REMEMBER! You have not lost until your number of lives is zero. You have not won until a congragulations message appears! " << endl;
	//	cout << "If you manage to find the exit, you will suceed to the second level." << endl;

	cout << "First choose your name and description. " << endl;
	cout << endl << endl;
}


//function to say the instructions for the game2
void manager::instructions_2()
{

	cout << "You have 3 lives to begin with. If you loose your lives, then game over and you start from level one. There is one entry point out of this maze. You can go backwards or possibly up to five different directions (depeding on how the gods feel). If you are lucky you will win prizes and increase the number of lives. " << endl << endl << endl;

} 


//help the user traverse the tree through a while loop, check first and then keep going until they win or loose all their lives I.O: nothign
int manager::traverse()
{

	int life[3] = {5,5,5};
	int * life_decider;
	int count_lives;
	//int storage[3];

	life_decider = a_bst.ask0(life);  //returns what kind of "path it is"
	//	cout << life_decider[1] << endl;
	if (life_decider[0]%2 != 0)			//is a odd number
	{	
		a_player.remove_life_wr();		//removes a life
		a_player.display_life();		//says how many lives left
	}
	//if I gain points - add coins - check how many poits - add life
	else if (life_decider[0] == 6)
	{
		cout << "Coungragulations! You won the first level! ";
		return 1;
	}

	else
	{
		int lives = a_player.add_coin_wr(life_decider[0]);				//returs how may lives you have earned
		if (lives != 0)
		{
			a_player.add_life(lives);
			a_player.display_life();
		}
		else
		{
			a_player.display_coin();
		}
	}
	count_lives = a_player.get_life();	//tells you how many lives you have left	


	while (life_decider[0] != 6 && count_lives > 0)
	{
		life_decider = a_bst.traverse_wr(life);	//tells you which path they took
		//		cout << life_decider[1] << endl;
		//		cout << "The previous data was " << life_decider[3] << endl;
		if (life_decider[0] == 1)
		{	
			a_player.remove_life_wr();
			a_player.display_life();
			//if I gain points - add coins - check how many poits - add life
		}
		else if (life_decider[0] == 6)
		{
			cout << "Coungragulations! You won the first level! " << endl;
			return 1;
		}

		else
		{
			int lives = a_player.add_coin_wr(life_decider[1]);				//returs how may lives you have earned
			if (lives != 0)
			{
				a_player.add_life(lives);
				a_player.display_life();
			}

			else
			{
				a_player.display_coin();
			}
		}	
		count_lives = a_player.get_life();
		if (count_lives == 0)
			return 0;
	}
}



void manager::traverse2()
{
	int life[3] = {5,5,5};
	int * life_decider;
	int count_lives;

	int i = 0;
	life_decider = a_graph.ask(life,i);  //returns what kind of "path it is"
	//	cout << life_decider[1] << endl;
	if (life_decider[0]%2 != 0)			//is a odd number
	{	
		a_player.remove_life_wr();		//removes a life
		a_player.display_life();		//says how many lives left
	}
	//if I gain points - add coins - check how many poits - add life
	else if (life_decider[0] == 6)
	{
		cout << "Coungragulations! You won the second level! ";
	}

	else
	{
		int lives = a_player.add_coin_wr(life_decider[0]);				//returs how may lives you have earned
		if (lives != 0)
		{
			a_player.add_life(lives);
			a_player.display_life();
		}
		else
		{
			a_player.display_coin();
		}
	}
	count_lives = a_player.get_life();	//tells you how many lives you have left	

	++i;
	while (life_decider[0] != 6 && count_lives > 0)
	{
		life_decider = a_graph.ask(life,i);	//tells you which path they took
	//			cout << life_decider[1] << endl;
	//			cout << "The previous data was " << life_decider[3] << endl;
		if (life_decider[0] == 1)
		{	
			a_player.remove_life_wr();
			a_player.display_life();
			//if I gain points - add coins - check how many poits - add life
		}
		else if (life_decider[0] == 6)
		{
			cout << "Coungragulations! You won the second level! " << endl;
		}

		else
		{
			int lives = a_player.add_coin_wr(life_decider[1]);				//returs how may lives you have earned
			if (lives != 0)
			{
				a_player.add_life(lives);
			//	a_player.display_coin();
				a_player.display_life();
			}

			else
			{
				a_player.display_coin();
			}
		}	
		count_lives = a_player.get_life();
		++i;
	}

}
