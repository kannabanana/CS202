/*VERTEX.CPP
  SR Kanna
  6/26/2015
  HW1&2
  CS202

  PURPOSE OF FILE: This is .CPP the vertex class which is of edge class. The algorithms which it utlizes include figuring out the where there user wants to go and how to get them there and recording what they say (which is protected data member, adding to the number of prizes, counting the number of prizes all of wich assist the manager class.

  Data structure: LLL
 */


#include "edge.h"

//default construcotr
edge::edge()
{
	next = NULL;
	adjacent= NULL;
}


//copy construcor -takes a contant edge object O: nothing
edge::edge(const edge & edge_obj)
{
	this->next = edge_obj.next;
	this->adjacent = edge_obj.adjacent;
}


//destructor
edge::~edge()
{
	next = NULL;
	adjacent = NULL;
}


//getter of next
edge *& edge::go_next()
{
	return next;
}



//getter of adjacent
vertex *& edge::get_adjacent()
{
	return adjacent;
}

//gets the first vertex connecting to the edge
int edge::get_vertex1()
{
	return vertex1;
}


//gets the second vertex connecting to the edge
int edge::get_vertex2()
{
	return vertex2;
}
