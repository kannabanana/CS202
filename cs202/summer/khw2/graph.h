/*
   SR Kanna
   HW1&2
   GRAPH.H

 */

//#include <fstream>
#include "edge.h"
#ifndef _GRAPH_H
#define _GRAPH_H
class graph
{

	public:
		graph(int size =5);					//default constructor I: size of hard coded O: Nothing
		graph(const graph &);					//copy constructor I: const object type O: Nothing
		~graph();						//deconstructor


		void read_in_vertex();					//reading in vertex from file - didn't do
		void read_in_edges();					//read in the edges from a file - didn't do
		int insert_vertex(int vertex);				//insert a vertex hard coded I: integer of which vertex, O: nothing - didn't do
		void insert_vertex();					//insert the edges I: Nothing O:Nothing
		void insert_edge(int vertex1,int vertex2);		//insert the edges I: two ints, O: Nnothing -didn't do
		void create_edges();					//creates the edges by hard coding O/I: nothing
		int find_location(int key_value);			//find the location of the edges in the list - didn't do I: takes the edge
		void display_adjacency_list();				//dispalys the adjacenc list I/O: nothing
		void display_adjacency_assist(edge * head);		//traverses the edge list I: edge pointer to head O: Nothing
		int * traverse(edge *, int *);				//traverse the graph I: edge pointer, integer pointer O: integer pointer
		int * ask(int * storage,int i);				//akss where they want to go in the tree I: int array, int index O: int array
		void remove(int one,int two);				//removes from the edge list based on the input of the edges the user wants


		void display();						//dipslays
		void print();						//prints the adjacency list I/O: nothing
		void retrieve();					//retrieves a specific edge I/O: Nothing
		void remove_all();					//removes all I/O: Nothing (destructor code)


	protected:
		vertex * adjacency_list;				//has an array of verticies
		int size;						//size of the table
};

#endif
