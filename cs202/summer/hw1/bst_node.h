/*
   BST_NODE.H

   SR Kanna
   HW1&2
   CS202
   6/26/2015


   PURPOSE OF FILE: This is the .H of the bst_node, which contains all the prototypes
   They would want to use this file because it contains all of the bst_node functions and the classes functions it contains (the methods) because it gives them access to the right/left and the flags 

 */



#include "path.h"
class bst_node:public path
{
	public:	
		bst_node();				//bst node default I/O: nothing
		bst_node(const bst_node &);		//copy constructor I: Constant bst object O: Nothing
		bst_node(bst_node * const& bst_obj); 	//bst constructor w/argumetts I: pass by reference
		bst_node(int random_path);		//constructor w/arguments i: integer O:Noting
		~bst_node();		//destructor I/O: Nothing


		int *& get_bflag();		//getter I/O: Nothing
		bst_node *& go_left();		//getter go left I: Nothing O: returns bst_node
		bst_node *& go_right();		//getter I: nothing O: bst_node
		bst_node *& go_parent();	//getter I: nothing O: bst_node
		void display();			//display I/O: nthing

	protected:
		bst_node * left;			//left
		bst_node * right;			//right
		int bflag;				//before integer
		bst_node * parent;			//parent pointer
};
