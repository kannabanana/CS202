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
#include <fstream>
using namespace std;
#ifndef _PATH_H
#define _PATH_H

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
	int ask_direction2(int i);			//ask what direction you want to go in the second part of the maze
	

	int * what_intersection(int *);		//What intersection they wat to go to I: gives an array of integers O: returns the array of integers
	int * is_finish_line(int *);		//checks if you have completed the game - other loose a life 			I: integer array, returns integer array
		
	int * is_finish_line2(int *);


	int get_name();				//get name, O: returns name integer
	int get_before();			//get before O: returs before

	void set_name(int );			//set name I: New int name O: Nothing
	void set_before(int);			//set beforer i: new before int O: Nothing

	virtual void display() =0;		//pure virtual display function - class is now abstract

protected:
	int before;				//before integer
	int name;				//name integer
};

#endif
