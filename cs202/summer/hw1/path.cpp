/*
PATH.CPP

SR Kanna
6/26/2015
HW1&2
CS202


*/

#include "path.h"

//default constructor
path::path()
{
	name = 0;
}


//copy constructor - copies the implicit instance of the life using the this ptr and from the prize object. Input is constant object of the class. No output
path::path(const path & path_obj)
{
	this->name = path_obj.name;
}


//constructor with pointer by reference arugment (passes from bst_node)
path::path(path * const& path_obj)
{
	this->name = path_obj->name;
}


//path constructor w/argument takes another integer
path::path(int path)
{
	name = path;
}


//destructor - no dynamic memory (no arguments)
path::~path()
{

}


//checks what kind of intersection it is - loose a life or gain points
int * path::what_intersection(int * storage)
{
if (name%2 ==0)		//the path is even
	{
		storage[1] = name;
		storage[0] = name;
		return storage;
	//	return name;
	}
else
	{
		storage[1] = name;
		storage[0] = 1;
		return storage;
		//return 1;
	}
}


//level one uses the function when you are at a leaf - if you are at a certain number, it will say you have won, otherwise it will cause you to loose a life
int * path::is_finish_line(int * storage)
{
	if (name == 5)
	{
		storage[1] = name;
		storage[0] = 6;
		return storage;
	//	return 6;
	}
	else
	{
		storage[1] = name;
		storage[0] = 1;
		return storage;
		//it will remove a life
	//	return 1;	//returns an odd number- all odd numbers cause you to loose a life

	}
}


//asks teh direction (only asks to go right or left) not bakwards. Returns what they said
int path::ask_direction()
{
	char temp[100];
	cout << "Please enter a valid entry. Would you like to left or right? ";
	cin.get(temp,100,'\n');	cin.ignore(100,'\n');
	char * t = new char[strlen(temp)+1];
	strcpy(t,temp);
	*t = tolower(*t);	
	cout << endl;
	if((strcmp(t,"left")==0))
	{
		return 0;
	}
	else		//if((strcmp(t,"right")==0))
		return 1;

}


//asks the direction (only asks to go right or left or backwards). Returns the answer by an integer
int path::ask_direction1()
{

	char temp[1000];
	cout << "Please enter a valid entry. Which direction would you like to go? left? right? Or backward? ";
	cin.get(temp,100,'\n');	cin.ignore(100,'\n');
	char * answer = new char[strlen(temp)+1];
	strcpy(answer,temp);
	*answer = tolower(*answer);	//lowercase asy response
	cout << endl;
	if((strcmp(answer,"left")==0))
		return 0;
	else if((strcmp(answer,"right")==0))
		return 1;
	else //((strcmp(answer,"backward")==0))
		return 2;
}



//getter for the name. returns the integer
int path::get_name()
{
	return name;
}


//get before integer. returns the integer
int path::get_before()
{
	return before;
}

//PURE VIRTUAL FUNCITON - BODILESS
void path::display()
{

} 
