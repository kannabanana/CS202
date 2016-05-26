/*
   MANAGER.CPP

   SR Kanna
   CS202
   6/27/2015
   HW1&2


   PURPOSE OF FILE: This is Manager Class it manages all the other classes and interacts with the client program. They would want to use this file because it contains all of the prize functions and the classes functions it contains (the methods) because it gives them access to increase/decrement the player's prizes

 */


#include "player.h"
#include "bst.h"
#include "graph.h"
#ifndef _MANAGER_H
#define _MANAGER_H

//manager class manages bst, player and eventually graph
class manager
{
	public:
		manager();			//default constructor I/O: nothing
		manager(const manager &);	//constructor w/arguments I: takes a construcor w/arguments O: nothing
		~manager();			//destructor I/O: nothing

		void instructions();		//instructions I/O: nothing
		void instructions_2();		//displays instructions for game 2
		void create_path_wr();		//creates a path wrapper I/O: nothing
		void create_path_wr2();		//creates a path wrapper for the second game I/O:nothing
		void display_wr();		//display I/O: nothing
		void display_wr2();		//display the graph I/O: nothing
		void retrieve_wr(int num);	//tretrieve wrapper I/O: Nothing
		void remove_wr(int first,int second);	//remove wrapper
		int traverse();		//helsp you traverse the tree IO: Nothing
		void traverse2();	//traverse the graph I/O:nothing
	protected:
		player a_player;		//has a player object
		bst a_bst;			//as a bst object
		graph a_graph;			//a graph object
		//graph
		//bst


};
#endif
