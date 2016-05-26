/*
   GRAPH.CPP

   SR Kanna
   HW1&2
   CS202
   7/11/2015


   PURPOSE OF FILE: This is .CPP the player class which is of graph class. The algorithms which it utlizes include figuring out the where there user wants to go and how to get them there and recording what they say (which is protected data member, adding to the number of prizes, counting the number of prizes all of wich assist the manager class.

   The data structure in this file is graph containing vertex nodes in an adjacency list and edges ocnnecting them. You can also go backwards.  

 */

#include "graph.h"
//default constructor
graph::graph(int size)
{
	adjacency_list = new vertex[size];
	for(int i  = 0;i<size;++i)		//looping through and setting everything to NULL
	{
		adjacency_list[i].get_head() = NULL;
		adjacency_list[i].set_name(0);
		adjacency_list[i].set_before(0);
	}
	this->size = size;	//allocating the size
}



//copy constructor - copies the implicit instance of the life using the this ptr and from the prize object. Input is constant object of the class. No output
graph::graph(const graph & graph_obj)
{

}


//destructor
graph::~graph()
{
	for(int i =0; i<size;++i)
	{	//set a temp to head
		edge * temp = adjacency_list[i].get_head();
		while(temp != NULL)		//keep traversing and deleting edge list until tere is no more list
		{
			adjacency_list[i].get_head() = adjacency_list[i].get_head()->go_next();
			delete temp;
			temp = adjacency_list[i].get_head();
		}
		adjacency_list[i].get_head() = NULL;

	}
	delete [] adjacency_list;		//delete array
}



//insert vertex function takes no arguments and returns nothing
//hard codes in the verticies
void graph::insert_vertex()
{
	for(int i=0;i<5;++i)
	{
		adjacency_list[i].set_name(i+1);
	}
}


//print function to double check the verticies
void graph::print()
{
	for(int i =0;i<5;++i)
	{
		cout << adjacency_list[i].get_name() << '\t';
	}
}



//for loop - 
//for each index, create an edge (5) for each vertex (it goes back to itself to (circular paths)
//No arguments, no return type
void graph::create_edges()
{
	for(int i = 0;i<5;++i)
	{		
		for (int j =0;j<5;++j)
		{
			edge * temp = adjacency_list[i].get_head();	//temp to the head
			if (temp == NULL)		//base case of nothing
			{
				temp = new edge;
				temp->get_adjacent() = &adjacency_list[j];
				temp->go_next() = NULL;
				adjacency_list[i].get_head() = temp;
			}
			else if (temp->go_next() == NULL)	//base case of only one element
			{
				temp = new edge;
				adjacency_list[i].get_head()->go_next() = temp;
				temp->get_adjacent()=&adjacency_list[j];
				temp->go_next() = NULL;
			}
			else		//base case of more than one element
			{
				edge * current = adjacency_list[i].get_head();	//points to the head
				temp = new edge;
				while (current->go_next() != NULL)
				{
					current = current->go_next();
				}
				current->go_next() = temp;
				temp->get_adjacent() =&adjacency_list[j];
				temp->go_next() = NULL;
			}	//set it to be after the head (in ordeR)
		}
	}
}




//display edges next to adjacecy list
//no arguments, no return type - recursive function to go trough each index in adjacency list and call functiont to display each edge
void graph::display_adjacency_list(void)
{
	for(int i =0;i<size;++i)
	{
		cout << "The vertex is " << adjacency_list[i].get_name() << " is connected to ";
		display_adjacency_assist(adjacency_list[i].get_head());
		cout << endl << endl << endl;
	}
}


//recursive function to display names in edge list of an adjacent index
//takes an edge head as an argument, no return type
void graph::display_adjacency_assist(edge * head)
{
	if(head == NULL)
		return;
	cout << head->get_adjacent()->get_name() << '\t';
	display_adjacency_assist(head->go_next());
}




//tell an edge they want removed
//tell two numbers
//the linked list is empty
//it's the first one
//there is more than one
void graph::remove(int first,int second)
{
	first = first-1;
	second = second-1;
	if(adjacency_list[first].get_head() == NULL)
	{
		return;
	}

	else
	{	//temp to the head of the edge list
		edge * temp = adjacency_list[first].get_head();

		//check what it's attachig to is equivlanet to is the first node in the linked list

		if (second == 0)
			//		if(adjacency_list[first].get_head()->get_adjacent() == adjacency_list[second].get_head())
		{
			edge * temp2 = adjacency_list[first].get_head()->go_next();
			delete adjacency_list[first].get_head();
			adjacency_list[first].get_head() = temp2;
		}

		else	//base case of going backwards
		{
			edge * prev = NULL;
			edge * current = adjacency_list[first].get_head();

			for(int i = 1;i<second+1;++i)
			{
				prev = current;
				current = current->go_next();	
			}
			prev->go_next() = current->go_next();
			delete current;
			temp = NULL;
		}
	}
}

//retrieve


//gives you options when you want to traverse te graph and calls the function to traverse once it figures out where you are in the graph
//takes an int pointer, index of where you are in the adj list and returns int array
int * graph::ask(int * storage,int i)
{	

	int response = adjacency_list[i].ask_direction2(i);		//store their response

	storage[3] = adjacency_list[i].get_name();		//the name of the node in the first one
	int back = storage[3];
	edge * temp;

	if (response > 0)		//response is greater than zero, meaning they are going forward in the graph
	{
		if (i < 5)
			temp = adjacency_list[i].get_head();		//to ensure that it keeps looping even if they exceed five turns
		else
			temp = adjacency_list[back].get_head();

		for(int j = 1;j<response;++j)
		{
			temp = temp->go_next();
		}

		storage = traverse(temp,storage);	//calls the function to traverse the list
	}

	else	//want to go backwards
	{
		//find out what the third element is
		edge * temp = adjacency_list[back].get_head();
		for(int j = 1;j<response;++j)
		{
			temp = temp->go_next();
		}

		storage = traverse(temp,storage);	//calls the function to traverse the list
	}
	return storage;
}


//traverse the graph
//takes a int array as arugment and returns int
int * graph::traverse(edge * temp,int * storage)
{
	if (temp == NULL)
	{
		storage[0] = 11;		//returns if you hit null (which you shouldn't)
		return storage;
	}
	else
	{
		//find the adjacent one it's pointing
		vertex * current = temp->get_adjacent();

		//send it into the path to find out it's even or odd
		storage = current->what_intersection(storage);
		storage = current->is_finish_line2(storage);

		//call the what_intersection function
		return storage;	
	}
}
