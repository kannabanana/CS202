/*
VERTEX.H

SR Kanna
HW1&@
CS202
6/26/2015

   PURPOSE OF FILE: This is the .H of the path, which contains all the prototypes
   They would want to use this file because it contains all of the path functions and the classes functions it contains (the methods) because it gives them access to integer value of the path and a before flag
 
*/

#include "path.h"

#ifndef _VERTEX_H
#define _VERTEX_H

class edge;
class vertex:public path		//incomplete declaration of edge class
{
	public:
		vertex();		//default constructor i/O: NOthing
		vertex(const vertex & vertex_obj);	//copy constructor I: constant vertex object
		~vertex();		//default constructor

		
		edge *& get_head();	//get the head object
		void display();		//empty function - need it so this is not an abstract base class
	
	protected:
		edge * head;		//pointer to the beginning of the edge list
};

#endif
