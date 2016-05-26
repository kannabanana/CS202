/*
SR Kanna
CS202
4/28/2015
HW2

LLL_LLL.CPP

PURPOSE OF LLL_LLL.CPP: This is the implementatation of the functions in the .cpp 
*/

#include "lll_lll.h"
using namespace std;

//default constructor
term::term()
{
	name_of_term = NULL;
}


//copy constructor
term::term(const term & term_obj):lll(term_obj)
{
	
	this->name_of_term = new char[strlen(term_obj.name_of_term)+1];
	strcpy(this->name_of_term,term_obj.name_of_term);

}


//copy consturctor- takes ptr as argument- calls initialization list
term::term(term * const& to_insert):lll(to_insert)
{


}


//destructor
term::~term()
{
	delete [] name_of_term;	
}


//getter for term name
char *& term::get_term_name()
{
	return name_of_term;
}


//deep copy of the term name
void term::insert_name(char * name_of_term)
{
	this->name_of_term = new char[strlen(name_of_term)+1];
	strcpy(this->name_of_term,name_of_term);
}


//display the term name
void term::display_term()
{
	cout << name_of_term << '\t';
	display_all();	
}


//default
node_term::node_term()
{
	next = NULL;
	left = NULL;
	right = NULL;
}


//copy constructor
node_term::node_term(const node_term & node_term_obj):term(node_term_obj)
{

}


//initialization list
node_term::node_term(const term & to_insert):term(to_insert)
{

}


//copy consturctor w/initialization list
node_term::node_term(node_term * const& to_insert):term(to_insert)
{


}


//deconstructor
node_term::~node_term()
{


}


//return the next
node_term *& node_term::go_next()
{
	return next;
}


//return the right
node_term *& node_term::go_right()
{
	return right;
}


//return the left ptr
node_term *& node_term::go_left()
{
	return left;
}


//set next
void node_term::set_next(node_term * source)
{
	next = source;
}


/*
//get the credits for term
int node_term::count_credit_one_term()
{
	get_credit_lll(head);
}


//get grades for the term
int node_term:check_grade_one_term()
{
	get_grade_lll(head);
}


//counting the number of required classes taken
int node_term::count_required_one_term()
{
	count_required(head);
}


//calculate the gpa
float node_term::calculate_gpa_one_term()
{
	calculate_gpa_lll(head);
}


//classes tken in a term
int node_term::what_classes_one_term()
{
	what_classes_lll(head);
}


//count
int node_term::count_one_term()
{
	count(head);
}


term *& node_term::get_term()
{
	return data;
}
*/


//default constructor
term_list::term_list()
{
	head = NULL;
	srand(time(NULL));
}



//copy constructor -takes in terms
term_list::term_list(const term_list & term_obj)
{

}


//insert into term list
void term_list::insert_term_list(const term & to_insert)
{
	if (head == NULL)
	{
		head = new node_term(to_insert);		//calls the node_term copy constructor - make sure the initialization list matches!
		head->go_next() = NULL;
		return;
	}

	if (head != NULL)
	{
		node_term * temp = new node_term(to_insert);
		temp->set_next(head);
		head = temp;
		return;
	}
}



//deconstructor - no dynamic memory
term_list::~term_list()
{


}


//display the terms 
void term_list::display_term_list()
{
	node_term * temp = head;
	while (temp != NULL)
	{
		temp->display_term();
		temp = temp->go_next();
	}
}


//count function of the number of terms
int term_list::count_term_list(node_term * head)
{
	if (head == NULL)
		return 0;
	if (head != NULL)
		return (count_term_list(head->go_next())+1);
}


//wrapper function
node_term * term_list::find_random_wrapper()
{
	find_random(head);
}


//find random node to return
node_term * term_list::find_random(node_term *& head)
{
int length = count_term_list(head);
if (length == 0)		//no nodes
	return NULL;

//only one node in term list
if (head->go_next() == NULL)
{
	node_term * current = head;
	head = NULL;
	return current;
}


//there is more than one node in the list
if (head->go_next() != NULL)
{
	int find_random = ((rand()%length)+1);		//initialzing a random number between the length of the list
	if(find_random == 1)
	{
		do{
			find_random = ((rand()%length)+1);
		}
		while (find_random ==1);
	}
	
	if (find_random != 1)
	{
		//check if the first head isn't head
		node_term * previous = head;
		node_term * current = head->go_next();
		//base cases - no nodes, one node, more than one
		//more than one
		for (int i = 2;i<find_random;++i)
		{
			previous = previous->go_next();
			current = current->go_next();
		}
			previous->set_next(current->go_next());	//previous->next = current->next;
			current->set_next(NULL);		//current->next = NULL
			return current;		//return the pointer to the bst function
	}
}
}
