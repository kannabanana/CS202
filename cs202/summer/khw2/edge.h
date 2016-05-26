/*
EDGE.H
SR Kanna
HW1&@
CS202
6/26/2015

   PURPOSE OF FILE: This is the .H of the path, which contains all the prototypes
   They would want to use this file because it contains all of the path functions and the classes functions it contains (the methods) because it gives them access to integer value of the path and a before flag
 
*/


#include "vertex.h"
#ifndef _EDGE_H
#define _EDGE_H

class edge			
{
	public:
		edge();				//default constructor
		edge(const edge & edge_obj);	//copy constructor I: takes a constant edge object
		~edge();			//destructor I: Nothing


		edge *& go_next();		//getter of the next pointer O: returns edge pointer
		vertex *& get_adjacent();	//getter of the adjacent pointer O: vertex pointer
		int get_vertex1();		//gets the first vertex	O: Int
		int get_vertex2();		//gets the second vertex O: int

	protected:
		edge * next;			//contains a next pointer
		vertex * adjacent;		//contains an adjacent pointer
		int vertex1;			//first vertex attached to
		int vertex2;			//second vertex attached to
};

#endif
