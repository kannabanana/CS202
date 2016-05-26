/*
SR Kanna
CS202
4/28/2015
HW2

LLL_LLL.H

PURPOSE OF LLL_LLL.H: Function declarations of the terms, term_node and termlist lll and nodes inside it. Creates a linked list of linked list. The linked list of terms containing a linked list of course nodes. Human readible file.

*/

#include "data_st.h"

//a term is a list of courses - lll is a list of courses
class term: public lll
{
	public:
		term();			//default constructor I/O: Nothing
		~term();		//destructor	I/O:Nothing
		term(const term &);	//Copy constructor I: Object of that type O:NA
		term(term * const&);	//Copy constructor I: Object ptr O:Nothing
		void display_term();	//Display the terms I/O: NA
		void insert_name(char * term);	//Insert a name into the term list I: Takes a char ptr-name of the term O:NA
		char *& get_term_name();	//Get the name of the term I:NA O: Retursn the char by reference

	protected:
		char * name_of_term;		//Name of the term
};


///node is a term
class node_term: public term
{
	public:
		node_term();					//default constructor
		node_term(const node_term &);			//copy construcotr I: takes object by reference O: Nothing
		node_term(const term & to_insert);		//copy constructor I: takes term by reference O: Nothing
		node_term(node_term * const& to_insert);	//Copy constructor I: Takes a node term ptr O: Nothing
		~node_term();					//deconstructor I/O Nothing
		node_term *& go_next();				//go next I: Nothing O: Returns a node_temr ptr
		node_term *& go_right();			//go next I: Nothing O: Returns a node_temr ptr
		node_term *& go_left();				//go next I: Nothing O: Returns a node_temr ptr
		void set_next(node_term * source);		//set next I: takes a node_temr ptr O: Nothing


//FUNCTIONS TO POTENTIALLY IMPLEMENT:
//		int count_credit_one_term();
//		int check_grade_one_term();
//		int count_required_one_term();
//		int count_one_term();
//		float calculate_gpa_one_term();
//		int what_classes_one_term();

	protected:

		node_term * next;				//next ptr
		node_term * left;				//left ptr
		node_term * right;				//right ptr
};


//list of terms has a node_term
class term_list
{
	public:
	term_list();						//default constructor
	~term_list();						//deconstructor
	term_list(const term_list &);				//copy constructor I:Takes term list object O: Nothing
	void insert_term_list(const term & to_insert);		//insert a term into the term list I: Takes a term object O: Nothing
	void display_term_list();				//display the term list I/O: Nothing
	int count_term_list(node_term * head);			//count the number of terms I: Takes a node_term ptr O: Number of terms

	node_term * find_random_wrapper();			//picks a random number wrapper to insert inot bst I: NOthing O: Node_term ptr
	node_term * find_random(node_term *& head);		//picks a random term to insert into bst I: Node_term ptr O: Returns ptr to bst

	protected:
		node_term * head;				//head ptr
};
