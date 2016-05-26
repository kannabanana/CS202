/*
PATH.H

SR Kanna
HW1&@
CS202
6/26/2015

   PURPOSE OF FILE: This is the .H of the path, which contains all the prototypes
   They would want to use this file because it contains all of the path functions and the classes functions it contains (the methods) because it gives them access to integer value of the path and a before flag
 
*/

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
//these two are the random
#include <time.h>
#include <stdlib.h>
using namespace std;

//path class
class path
{

public:
	path();				//default constructor 	I/O: Nothing
	path(const path &);		//copy constructor	I: constant object path
	path(int path);			//constructor w/arguments I: takes integer O:Nothing
	path(path * const& path_obj);	//constructor I: Takes a path object by pointer by reference
	virtual ~path();			//destructor (virtual) I/O:Nothing
	
	int ask_direction();			//ask the direction initally I: Nothing O: integer
	int ask_direction1();			//ask the direction I: Nothing O:returns what direction they want to go
	int * what_intersection(int *);		//What intersection they wat to go to I: gives an array of integers O: returns the array of integers
	int * is_finish_line(int *);		//checks if you have completed the game - other loose a life 			I: integer array, returns integer array
	int get_name();				//get name, O: returns name integer
	int get_before();			//get before O: returs before
	virtual void display() =0;		//pure virtual display function - class is now abstract

protected:
	int before;				//before integer
	int name;				//name integer
};
