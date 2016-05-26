/*
SR Kanna
CS202
4/28/2015
HW2

DATA_ST.H

PURPOSE OF BST.H: Function declarations of the BST. Human readible file.

*/

#include "lll_lll.h"



//bst ->manager class
class manager
{

public:

	manager();		//default constructor	I/O: Nothing
	~manager();		//deconstructor		I/O: Nothing
	manager(const manager &);	//copy constructor	I: takes object of type Manager O: NA

	void copy(node_term * const& source,node_term *& dest);		//copy function I: Takes a node term ptr O: Nothing

	void remove_all(node_term *& root);	//remove all I: root O: nothing

	void wrapper_display();				//display wrapper I/O: Nothing
	void display_all(node_term * root);		//display all I/O: Nothing

	void wrapper_retrieve(char * find);			//Wrapper for retrieve I/O: I: Takes a char ptr O: NA
	void retrieve(node_term * root,char * find);		//retrieve a specific term I: root and the thing to find
	
	void wrapper_remove_one(char * find);			//wrapper to remove one I: Takes a char ptr O: NOthing
	void remove_one(node_term *& root, char * find);	//remove a specific term I: O: root and the thing to remove
	void find_in_order_sucessor(node_term * root,node_term *& in_order);	//Function to find the inorder sucessor I: Takes a node_term ptrs - keep track of root, and the sucessor to the left	O: NA
	void replace_root_data(node_term *& root,node_term *& in_order);	//Function to replace the root w/sucessor I: ptr O: NA
//	void copy_root(node_term * source,node_term *& dest);

	void insert_wrapper(node_term * insert);	//balance tree insert function I: Takes a ndoe_term ptr O: NA
	void insert(node_term *& root,node_term *& insert_bst);	//insert into bst I: Takes a root ptr and a term node by reference O: NOthing


//FUNCTIONS TO POTENTIAL IMPLENT:

//	int count_credits_wrapper();	
//	int count_credits(node_term * head);
//	int check_grade_wrapper();
//	int check_grade(node_term * root);
//	int count_required_wrapper();
//	int count_required(node_term * root);
//	float calculate_gpa_wrapper();
//	float calculate_gpa(node_term * root);
//	int what_classes_wrapper();
//	int what_classes(node_term * root);
//	int count_wrapper();
//	int count(node_term * root);
//	void admitted_into_program(void);	//if student is admitted into the program I/O: Nothing

protected:
	node_term * root;			//node_term root ptr
};

