//EDGE.H
#include "vertex.h"
using namespace std;

#ifndef _EDGE_H
#define _EDGE_H

class edge
{
public:
	edge();			//default constructor
	edge(const edge &);	//copy constructor
	~edge();		//deconstructor

	edge *& go_next();	//return the next ptr
	vertex *& go_adjacent();	//return the adjacent ptr inside the edge list
	void set_next(edge * source);

protected:
	edge * next;		//next ptr for edge list
	vertex * adjacent;	//where it points to in the adjacency list
};

#endif
