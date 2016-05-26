/*
VERTEX.CPP
SR Kanna
6/26/2015
HW1&2
CS202

   PURPOSE OF FILE: This is .CPP the vertex class which is of bst class. The algorithms which it utlizes include figuring out the where there user wants to go and how to get them there and recording what they say (which is protected data member, adding to the number of prizes, counting the number of prizes all of wich assist the manager class.

It returns what kind of vertex they are on and allows the user to ask where they want to go in the graph

*/


#include "vertex.h"

//default constructor
vertex::vertex()
{
	head = NULL;
}

//copy constructor - copies the implicit instance of the life using the this ptr and from the prize object. Input is constant object of the class. No output
vertex::vertex(const vertex & vertex_obj):path(vertex_obj)
{


}

//deconstructor - no dynamic memory
vertex::~vertex()
{


}


//display is a abstract base class in the pat class- don't need it to display anything in the vertex class
void vertex::display()
{

}


//getter of the head of the edge list
edge *& vertex::get_head()
{
	return head;
}
