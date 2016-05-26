/*
   BST_NODE.CPP
   SR Kanna
   6/27/2015
   HW1&2
   CS202

   PURPOSE OF FILE: This is .CPP the player class which is of prize class. The algorithms which it utlizes include figuring out the number of prizes (which is protected data member, adding to the number of prizes, counting the number of prizes all of wich assist the manager class.
   There is no data structure used in tis file, its simply a class which is utilized by the data structures. 
 *

 */


#include "bst_node.h"

//prize defualt constructor -initializing values
bst_node::bst_node()
{
	left = NULL;
	right = NULL;
}


//copy constructor - copies the implicit instance of the life using the this ptr and from the prize object. Input is constant object of the class. No output
bst_node::bst_node(const bst_node & to_copy):path(to_copy)
{

}


//constructor w/argumets takes in a pointer by references and is passe back up to pat because of iheritance
bst_node::bst_node(bst_node * const& bst_obj):path(bst_obj)
{

}


//constructor w/argumets takes in a pointer by references and is passe back up to pat because of iheritance
bst_node::bst_node(int random_path):path(random_path)
{

}

//destructor 
bst_node::~bst_node()
{

}


//getter for go left, returns a pointer
bst_node *& bst_node::go_left()
{
	return left;
}


//getter for right, returns a pointer
bst_node *& bst_node::go_right()
{
	return right;
}


//display is here to ensure the bst_node class is not an abstract base class
void bst_node::display()
{

}
