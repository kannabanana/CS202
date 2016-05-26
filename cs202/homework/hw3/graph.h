
//GRPAH.H
#include "vertex.h"
using namespace std;

#ifndef _GRAPH_H
#define _GRAPH_H

class graph
{
public:
	graph();
	graph(int size = 7); 	//constructor w/arguments
	graph(const graph &);	//copy constructor
	~graph();


//FUNCTIONS:
	void insert_vertex(vertex &);	//inserting genres into adjacency list

	void insert_last(vertex * head,vertex * insert);

	void display_adjacency_assist(ostream &,vertex *) const;

//OPERATORS:
	graph & operator +=(const song &);	//add a song to the graph
	friend ostream & operator << (ostream & o,const graph &);	//display



protected:

	vertex ** adjacency_list;	//adjacency list of vertex ptrs
	int size;
};

#endif
