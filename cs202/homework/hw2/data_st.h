/*
SR Kanna
CS202
4/28/2015
HW2

DATA_ST.H

PURPOSE OF DATA_ST.H: Function declarations of the course lll and nodes inside it (node_lll and lll). Human readible file.

*/

#include "course.h"

//class of node_lll
class node_lll: public course
{
public:

	node_lll();		//Default constructor I: Nothing O: Nothing
	node_lll(node_lll * const& to_insert);		//copy constructor I: Takes a node_lll pointer O: NA
	node_lll(const course &);			//copy consturcotr I: Takes a course object by reference O: NA
	~node_lll();					//Deconstructor I/O: Nothing	
	void set_next(node_lll * source);		//Setter I: Takes a node_lll ptr O: Nothing
	node_lll *& go_next();		//function to return next pointer I: Nothing O: Returns node


//POTENTIAL FUNCTIONS TO BE POTENTIALLY IMPLEMENTED:
//	node_lll(const node_lll &);	//copy constructor I: type of the class O: nothing
//	node_lll(course *);	//insert function 
//	void copy(node_lll * const&);	//overloading
//	void copy(node_lll *&);	//copy function for lll copy
//	char *& get_course_name();

protected:
	node_lll * next;		//next pointer of type node_lll
};



//class of lll
class lll
{
public:

	lll();			//constructor I/O: Nothing
	~lll();			//deconstructor I/O: Nothing
	lll(const lll &);	//copy costructor I: object of type lll O: nothing

	lll(lll * const& to_insert);	//Copy constuctor I: Takes lll ptr as argument O: Nothing
	void copy(lll * source);	//Copy function that has a source ptr only - for manager class copying utility	O: Nothing
	void copy_lll(node_lll * const& source, node_lll *& dest);	//Copy function for the copy constructor I: Node_ll ptr source and dest O: Nothing
	
	void insert(const course & to_insert);		//insert into LLL I: Course object to insert	O: Nothing
	void display_all();		//display everything in the node I/O: Nothing
	char *& get_course_name();	//Get the course name	I: Nothing	O: Returns a char by reference

	void retrieve(char * course_find);	//retrieve and display I: Takes a char ptr O: Nothing
	void remove_matching_wrapper(char * find);	//remove all the matching to the user's request I: Character ptr O: Nothing
	void remove_matching(node_lll *& head, char * course_find);	//remove a specific class I: Takes a node_lll ptr by reference and a char ptr, O nothing
	void remove_all(node_lll *& head);				//Removes all for the destructor-wrapper function in case the user wants to remove. I/O:NA
	void remove_all_wrapper();


//FUNCTIONS TO BE POTENTIALLY IMPLEMENTED:
//	int get_credit_lll(node_lll * head);
//	int count_required(node_lll * head);
//	int count(node_lll * head);
//	float calculate_gpa_lll(node_lll * head);
//	int what_classes_lll(node_lll * head);

protected:
	node_lll * head;			//node_lll head ptr

};
