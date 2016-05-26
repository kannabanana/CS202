/*
SR Kanna
CS202
4/28/2015
HW2

DATA_ST.CPP

PURPOSE OF DATA_ST.CPP: This is the implementatation of the functions in the .cpp 

*/

#include "data_st.h"
using namespace std;


//defualt constructor
node_lll::node_lll():course()
{
	next = NULL;
}


//destructor to NULL
node_lll::~node_lll()
{


}


//copy constructor
node_lll::node_lll(const course & course_obj):course(course_obj)
{


}


//second constructor with arguments - 
node_lll::node_lll(node_lll * const& to_insert):course(to_insert)
{


}


//setter
void node_lll::set_next(node_lll * source)
{
	next = source;
}


//getter of next ptr
node_lll *& node_lll::go_next()
{
	return next;
}


//default constructor
lll::lll()
{
	head = NULL;
}


//destructor
lll::~lll()
{
	remove_all(head);
}



//lll copy constructor- takes lll ptr as argument
lll::lll(lll * const& to_insert)
{
	copy_lll(to_insert->head,head);
}


//copy constructor
lll::lll(const lll & source)
{
	copy_lll(source.head,head);
}


//lll copy function
void lll::copy(lll * source)
{
	copy_lll(source->head,head);
}


//insert course object into lll
void lll::insert(const course & to_insert)
{
	if (head == NULL)
	{
		head = new node_lll(to_insert);
		head->go_next() = NULL;
		return;
	}

	if (head != NULL)
	{
		node_lll * temp = new node_lll(to_insert);
		temp->set_next(head);
		head = temp;
		return;
	}

}


//copy function
void lll::copy_lll(node_lll * const& source, node_lll *& dest)
{
	if (source == NULL)
	{
		dest = NULL;
		return;
	}
	if (source != NULL)
	{
		dest = new node_lll(source);
		return copy_lll(source->go_next(),dest->go_next());


	}
}



//function to display everything in lll
void lll::display_all()
{

	node_lll * temp = head;	//set temp to head
	while (temp != NULL)		//traverse until NULL
	{
		temp->display();	
		temp = temp->go_next();
	}
}


//remove all wrapper
void lll::remove_all_wrapper()
{
	remove_all(head);
}


//function to remove all from lll
void lll::remove_all(node_lll *& head)
{

if (head == NULL)
	return;
if (head != NULL)
	remove_all(head->go_next());

delete head;
head = NULL;

}


//function to display a specific class requested by user
void lll::retrieve(char * course_find)
{
node_lll * temp =  head;	//set temp to head
while (temp != NULL)
	{
	if (strcmp(temp->get_course_name(),course_find)==0)	//display as long they have the same name as the user is looking for
		{
			temp->display();
		}
		temp = temp->go_next();
	}
}


//remove all the matching that the user wants - wrapper
void lll::remove_matching_wrapper(char * find)
{
	remove_matching(head,find);
}


//function to remove a specific class requested by user
void lll::remove_matching(node_lll *& head, char * course_find)
{
if (head == NULL)
	return;
if (head->go_next() == NULL)
{
	if (strcmp(head->get_course_name(),course_find)==0)
	 {
	 	delete head;		//calls the destructor
	 	head = NULL;
		head->go_next() = NULL;
		return;
	 }
	return;
}

if (head->go_next() != NULL)
{
	if (strcmp(head->get_course_name(),course_find)==0)
	{
		node_lll * temp = head->go_next();	//set the temp to head next
		delete head;
		head = temp;
		return remove_matching(head->go_next(),course_find);
	}
	if (strcmp(head->get_course_name(),course_find) != 0)
		return remove_matching(head->go_next(),course_find);
}
}



/*
//returns the number of credits taken in a "term"
int lll::get_credit_lll(node_lll * head)
{
	if (head == NULL)
		return 0;
	if (head != NULL)
	{
		//	cout << "The number of credits for the course is : " << head->get_credit() << '\t';
		return (get_credit_lll(head->go_next()+(head->get_credit())));
	}
}


int lll:check_grade_lll(node_lll * head)
{
if (head == NULL)
	return 0; 
if (head != NULL)
{
	if (head->get_required() == 1)	//cs course
	{
		course * ptr = &cs;
		(return get_credit_lll(head->go_next()+(head->check_grades_wrapper(cs);
	}

	if (head->get_required() == 2)
	{	
		course * ptr = &non_cs;
		(return get_credit_lll(head->go_next()+(head->check_grades_wrapper(non_cs);
	}
}
}


//counting the number of required classes taken in a term
int lll:count_required(node_lll * head)
{
if (head == NULL)
	return 0;
if (head != NULL)
	if (head->get_required() == 1 || head->get_required() == 2)
	{
		count_required(head->go_next()+1);
	}
}


//counting the number of courses
int lll:count(node_lll * head)
{
if (head == NULL)
	return 0;
if (head != NULL)
		count_required(head->go_next()+1);
}

//calculating the gpa
float lll:calculate_gpa(node_lll * head)
{
if (head == NULL)
	return 0;
if (head != NULL)
{
	return (get_credit_lll(head->go_next()+(head->calculate_grade())));
}
}


int lll:what_classes_lll(node_lll * head)
{
if (head == NULL)
	return 0; 
if (head != NULL)
{
	if (head->get_required() == 1)	//cs course
	{
		course * ptr = &cs;
		(return get_credit_lll(head->go_next()+(head->check_classes_wrapper(cs);
	}

	if (head->get_required() == 2)
	{	
		course * ptr = &non_cs;
		(return get_credit_lll(head->go_next()+(head->check_classes_wrapper(non_cs);
	}
}
}
*/
