/*
   MAIN.CPP

   SR Kanna
   cs202
   6/22/2015

   PURPOSE OF PROGRAM: The purpose of the program is a maze, based off the movie and book. The user is able to interact with the computer program and it gives the user hints through prizes and lives (prizes if they are closer to winning) and loose lives if they are not. This is the first level of the game. If they win, they will progress to the second level of the game. They are allowed to go right, left or backward. 

   File TYPE: The purpose of this file is to interact with the user. It provides the interface with the client program. It's kept short by the manager class

 */



#include "manager.h"
using namespace std;

int main()
{
	manager manager_obj;			//manager object
	bst a_bst;				//bst object
	prize prize_obj;			//prize object
	life life_obj;				//life object
	player * player_obj;			//player object
	char temp[1000];			//temporary variable to hold name/description


	manager_obj.instructions();		//calls the manager class instructions	

	cout << "Please enter your name ";			//enters your name and dynamically creates name
	cin.get(temp,1000,'\n');		cin.ignore(100,'\n');
	char * name = new char[strlen(temp)+1];
	strcpy(name,temp);

	cout << "Please enter the description of the player ";		//creates player and dynamically creates description
	cin.get(temp,1000,'\n');		cin.ignore(100,'\n');
	char * description = new char[strlen(temp)+1];
	strcpy(description,temp);


	player_obj = new player(name,description);		//enters name and description into constructor
	player_obj->display();					//displays this information

	cout << endl << endl;
	cout << "HINT: IF YOU'RE STUCK AFTER A WHILE GO BACKWARDS. " << endl;

	manager_obj.create_path_wr();				//calls manager to create a random maze
	manager_obj.display_wr();				//displays the random maze (in order traversal)
	manager_obj.traverse();					//helps you traverse the maze

	return 0;
};
