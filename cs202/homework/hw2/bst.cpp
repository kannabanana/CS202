/*
SR Kanna
CS202
4/28/2015
HW2

BST.CPP

PURPOSE OF BST.CPP: This is the implementatation of the functions in the .cpp 
*/
#include "bst.h"
using namespace std;



//default copy constructor
manager::manager()
{
	root = NULL;
}


//copy constructor
manager::manager(const manager & manager_obj)
{
	copy(manager_obj.root,root);

}


//copy function
void manager::copy(node_term * const& source,node_term *& dest)
{
	if (source == NULL)
	{
		dest = NULL;
		return;
	}
	if (source != NULL)
	{
		dest = new node_term(source);		//call copy constructor
		copy(source->go_left(),dest->go_left());
		copy(source->go_right(),source->go_right());
	}
}


//deconstructor
manager::~manager()
{
	//call remove all function
	remove_all(root);
}


//remove all
void manager::remove_all(node_term *& root)
{
	if (root == NULL)
		return;
	if (root != NULL)
	{
		remove_all(root->go_left());
		remove_all(root->go_right());
		delete root;
		root = NULL;
	}
}


//dislay wrapper
void manager::wrapper_display()
{
	display_all(root);
}

//display all terms and classes and all information in the term
void manager::display_all(node_term * root)
{
	if (root == NULL)
		return;
	if (root != NULL)
	{
		display_all(root->go_left());
		cout << "The name of the term is: "<< root->get_term_name() << '\t';
		root->display_all();		//calling node_bst's paren'ts display all
		display_all(root->go_right());
	}
}


//wrapper function for retrieve
void manager::wrapper_retrieve(char * term)
{
   retrieve(root,term);
}


//display all classes in a term
void manager::retrieve(node_term * root,char * find)
{
	if (root == NULL)
		return;
	if (root != NULL)
	{
		if ((strcmp(root->get_term_name(),find)==0))
			{
				retrieve(root->go_left(),find);

				root->display_all();		//call that term's display - that lll display
				retrieve(root->go_right(),find);
			}
		if (strcmp(root->get_term_name(),find)!= 0)
			{
				retrieve(root->go_left(),find);
				retrieve(root->go_right(),find);
			}
	}
}



//wrapper function to remove one
void manager::wrapper_remove_one(char * term)
{
	remove_one(root,term);
}


//remove a term
void manager::remove_one(node_term *& root, char * find)
{
	if (root == NULL)
		return;
	else
	{
		if ((strcmp(root->get_term_name(),find)==0))
			{
				if (root->go_right() == NULL && root->go_left() == NULL)	//only one node
				{
					delete root;
					root = NULL;
					return;
				}

				//has no left - find successor
				if (root->go_right() == NULL)
				{
				//call helper
					node_term * root2 = root->go_left();
					delete root;
					root = root2;
					return;
				}

				if (root->go_right() != NULL)
				{
					node_term * root2 = root->go_right();
				//call helper
					find_in_order_sucessor(root,root2);
				}

			remove_one(root->go_right(),find);			//keep going if even if you find one
			remove_one(root->go_left(),find);
			}
		if ((strcmp(root->get_term_name(),find)!= 0))			//if you don't find one
		{
			remove_one(root->go_right(),find);
			remove_one(root->go_left(),find);
		}
	}
}



//finds the inorder sucessor and calles functiont to replace roots data with inorder sucessor
void manager::find_in_order_sucessor(node_term * root,node_term *& root2)
{
	if (root2->go_left() == NULL)
	{
		replace_root_data(root,root2);		//copy function which removes the data of root
		node_term * temp = root2->go_right();	//connect up children of inorder sucessor
		delete root2;
		root2 = temp;
		return;
	}
	return find_in_order_sucessor(root,root2->go_left());
}


//delete root's data and replace the lll data
void manager::replace_root_data(node_term *& root,node_term *& in_order)
{
	root->remove_all_wrapper();
	in_order->copy(in_order);
}


//balance the bst
void manager::insert_wrapper(node_term * insert2)
{
	insert(root,insert2);
}


//insert function
void manager::insert(node_term *& root,node_term *& insert_bst)
{
	//if there are no nodes
	if (root == NULL)
	{
		root = insert_bst;
		root->go_right() = NULL;
		root->go_left()= NULL;
		root->go_next() = NULL;
		return;
	}

	//if I have nodes ->insert at a leaf

	if (root != NULL)
	{
		if (strcmp(root->get_term_name(),insert_bst->get_term_name())<0)
			insert(root->go_left(),insert_bst);
		if (strcmp(root->get_term_name(),insert_bst->get_term_name())>0)
			insert(root->go_right(),insert_bst);
		//call helper
	}
}



/*
int manager::count_credits_wrapper()
{
	count_credits(root);
}


//count credits-traverse the tree
int manager::count_credits(node_term * root)
{
if (root == NULL)
	return 0;
if (root != NULL)
{
	count_credits(root->go_left());
	root->count_credit_one_term();
	count_credits(root->go_right()); 
}
}


//wrapper for checking grades
int manager::check_grade_wrapper()
{
	check_grade(root);
}


//function to traverse tree and check grades
int manager::check_grade(node_term * root)
{
if (root == NULL)
	return 0;
if (root != NULL)
{
	check_grade(root->go_left());
	root->check_grade_one_term();
	check_grade(root->go_right());
}
}


//wrapper for counting the number of required terms
int manager::count_required_wrapper()
{
	count_required(root);
}


//count the number of required courses taken
int manager::count_required(node_term * root)
{
if (root == NULL)
	return 0;
if (root != NULL)
{
	count_required(root->go_left());
	root->count_required_one_term();
	count_required(root->go_right());
}
}


//calculate the gpa wrapper function
float manager::calculate_gpa_wrapper()
{
	calculate_gpa(root);
}


//count the number of required courses taken
float manager::calculate_gpa(node_term * root)
{
if (root == NULL)
	return 0;
if (root != NULL)
{
	calculate_gpa(root->go_left());
	root->calculate_gpa_one_term();
	calculate_gpa(root->go_right());
}
}



//wrapper for the classes
int manager::what_classes_wrapper()
{
	what_classes(root);
}


//calculating the classes
int manager::what_classes(node_term * root)
{
if (root == NULL)
	return 0;
if (root != NULL)
{
	what_classes(root->go_left());
	root->what_classes_one_term();
	what_classes(root->go_right());
}
}


//wrapper for counting the courses
int manager::count_wrapper()
{
	count(root);
}


//counting the courses
int manager::count(node_term * root)
{
if (root == NULL)
	return 0;
if (root != NULL)
{
	count(root->go_left());
	root->count_one_term();
	count(root->go_right());
}
}
*/

