/*
BST.H

SR Kanna
CS202
HW1&2
6/27/2015

   PURPOSE OF FILE: This is the .H of the life, which contains all the prototypes. They would want to use this file because it contains all of the bst functions and the classes functions it contains (the methods) because it gives them access to create, display, remove, remove all, copy, find etc the maze. It's an essential class the program.
 
*/



#include "bst_node.h"

//bst class in charge of the bst
class bst
{

public:
	bst();			//construcotr I/O: noting
	bst(const bst &);	//copy constructor I/O: const object of type class O: Nothing
	~bst();			//destructor

	//WRAPPER FUNCTIONS
	void display_wr();	//display wrapper I/O: nothing
	void create_path_wr();	//create a path wrapper I/O: Nothing
	void retrieve_wr(int);	//retrieve wrapper I: integer certain path
	int * traverse_wr(int *);	//traverse wrapper I: Interger pointer arrao: integer pointer
	void remove_wr(int name);	//remove wrapper I: integer name O: nothing
	//FUNCTIONS
	
	//display, remove, insert, remove_all, 

	void insert(bst_node *& root,bst_node *& insert);	//insert I: bast root, node insert O; Nothing
	void create_path(bst_node *& root);		//create path I: root O: nothing
	int compare_array(int i,int *,int path_storage);	//compare array I: integer, two array integers O: integer
	void copy(bst_node * const& ,bst_node *&);		//copy functio I: bst constant by reference O: bst node by reference
	void display(bst_node * root);			//display O: root node O: nothing
	void remove_all(bst_node *& root);		//remove all I: Root pointer O: Nothing
	void find_in_order_sucessor(bst_node * root,bst_node *& root2);	//find the in order sucessor I: root and root2 bst_node, O: Nothing
	void remove(bst_node *& root,int name);		//remove function I: root pointer by reference, int name O: name
	void retrieve(bst_node * root,int name);	//retrieve function I: bst node, int O: Nothing
	bst_node * retrieve_node(bst_node * root,int name);	//retrieve node I: bst node pointer, integer of the path, O: bst pointer

	int * ask0(int * storage);				//ask them were tey want to go I: int array by reference O: Integer array by reference
	int * traverse(bst_node *& root,int * storage);		//traverse the binary tree I: bst node by reference, int array O: integere array
	int * ask(bst_node *& root,int *);		//ask where they want to go I: binary tree node by reference, integer array O: integer array
	

protected:
	bst_node * root;		//root pointer of type bst_node
};
