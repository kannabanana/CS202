/*
   BST.CPP

   SR Kanna
   CS202
   HW1&2
   6/27/2015

   PURPOSE OF FILE: This is .CPP the bst class which is of bst class. The algorithms which it utlizes include figuring out the where there user wants to go and how to get them there and recording what they say (which is protected data member, adding to the number of prizes, counting the number of prizes all of wich assist the manager class.

   The data structure in this file is a binary search treea. You can also go backwards.  
 */

#include "bst.h"
//defualt constructor - initializing values
bst::bst()
{
	srand(time(NULL));	//set the random generator
	root = NULL;
}


//copy constructor - copies the implicit instance of the life using the this ptr and from the prize object. Input is constant object of the class. No output
bst::bst(const bst & to_copy)
{
	copy(to_copy.root,root);
}



//destructor- calls remove_all function
bst::~bst()
{
	remove_all(root);
}


//remove all function 
void bst::remove_all(bst_node *& root)
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


//Copy function - Takes a constant pointer by reference, and a destination node 
void bst::copy(bst_node * const& source,bst_node *& dest)
{
	if (source == NULL)
	{
		dest = NULL;
		return;
	}
	else
	{
		dest = new bst_node(source);
		copy(source->go_left(),dest->go_left());		//copy go left, go left
		copy(source->go_right(),dest->go_right());		//copy go right,go right
	}
}



void bst::remove_wr(int name)
{
	remove(root,name);				//remove function (calls the remove with the remove pointer)
}


void bst::remove(bst_node *& root,int name)
{
	if (root == NULL)
		return;
	else
	{
		if((root->get_name()==name))
		{	
			if (root->go_right() == NULL && root->go_left() == NULL)	//check if it's a child
			{
				delete root;
				root = NULL;
				return;
			}
			if (root->go_right() == NULL)					//check if you want to go right
			{
				bst_node * root2 = root->go_left();			//remove it
				delete root;
				root = root2;
				return;
			}
			if (root->go_right() != NULL)					//check if you want to left
			{
				bst_node * root2 = root->go_right();
				find_in_order_sucessor(root,root2);				//find the in order sucessor
			}
			remove(root->go_right(),name);						//call the remove again recursive
			remove(root->go_left(),name);						//call the remove again (left)
		}
		if (root->get_name() != name)
		{
			remove(root->go_right(),name);
			remove(root->go_left(),name);			//recursive
		}	
	}
}


//check to find an inorder sucessor - 
void bst::find_in_order_sucessor(bst_node * root,bst_node *& root2)
{
	if (root2->go_left() == NULL)
	{
		//	root->get_name() = root2->get_name();
		//	root->get_before() = root2->get_before();
		bst_node * temp = root2->go_right();
		delete root2;		//delete root
		root2 = temp;
		return;
	}
	return find_in_order_sucessor(root,root2->go_left());		//keep going until you don't have a left pointer anymore
}


//display function that serves as a wrapper
void bst::display_wr()
{
	display(root);
}



//display function
void bst::display(bst_node * root)
{
	if (root == NULL)
		return;
	else{
		display(root->go_left());
		cout << root->get_name() << '\t';
		display(root->go_right());
	}
}


//
void bst::retrieve_wr(int name)
{
	retrieve(root,name);
}



void bst::retrieve(bst_node * root,int name)
{
	if (root == NULL)
		return;
	else
	{
		if (root->get_name() == name)
		{
			cout << root->get_name();
			return;
		}
		else
		{
			if (root->get_name() >= name)
				retrieve(root->go_left(),name);
			else
				retrieve(root->go_right(),name);
		}
		//no nodes
		//nodes
		//it is that node - return that node's data
		//you are larger
		//you are smaller
	}
}

//wrapper
void bst::create_path_wr()
{
	create_path(root);
}



void bst::create_path(bst_node *& root)
{
	int random_path;
	int path_storage[5];			//array to store the path info

	do{
		random_path = (rand()%5);	//keep drawing numbers - don't want root to be 0 (then left side will be empty)
	}
	while (random_path == 0);

	path_storage[0] = random_path;

	root = new bst_node (random_path);
	root->go_left() = NULL;
	root->go_right() = NULL;
	//	root->go_parent() = NULL;
//	cout << random_path <<'\t';

	for(int i =0;i<4;++i)
	{

		do{
			random_path = (rand()%5);
			path_storage[i+1] = random_path;
		}

		while ((compare_array(i,path_storage,random_path))== 0);

		//		cout << "The random number is: " << random_path <<'\t';
		bst_node * temp = new bst_node(random_path);		//create new node
	//	cout << "The name of the node is" << temp->get_name() << '\t';
		insert(root,temp);
	}

	bst_node * current = new bst_node(5);
	insert(root,current);
	//choose 5 random numbers (1-5) %5+1 (for int i = 0; i<5;++1) 
	//store it into an array
	//create a bst node
	//insert into tree -root if there are no nodes
	//keep picking a random number - check with the array if it's there
	//if it's there, choose another
	//otherwise put store it in the array
	//create a bst_node and assign it data
	//


}


//help determine if the number has been used already
int bst::compare_array(int i,int * path_storage,int random_path)
{
	int count = 6;
	for(int j = 0;j<=i;++j)
	{
		if (path_storage[j] == random_path)
		{
			count = 0;			
			return count;
		}
	}
	return count;
}



//insert function
void bst::insert(bst_node *& root,bst_node *& to_insert)
{
	if (root == NULL)
	{
		root = to_insert;
		//	cout << "What I'm inserting into the tree "<<to_insert->get_name();
		root->go_left() = NULL;
		root->go_right() = NULL;
		//	root->go_parent() = NULL;
		return;
	}
	else
	{	//if the node is greater than or equal to root
		if(to_insert->get_name() >= root->get_name())
			insert(root->go_right(),to_insert);
		else
			insert(root->go_left(),to_insert);
	}

	//base case - nothing
	//no nodes - create root (already been created) so when you are at the leaf, you want "root" to equal the "insert"
	//nodes
	//is larger
	//it's smaller
}




//the first time you traverse the tree
int * bst::ask0(int * storage)
{
	int path_number = root->get_name();		//integer that stores the name of the root's name
	storage[3] = path_number;			//integer is stored in third portion of the array
	//cout << "The number before is. Which I'm storing in storage[3] " << storage[3] << endl;
	//path_number = storage[3];
	int response = root->ask_direction();		//store their response
	if (response == 0)
	{	
		bst_node * temp = root->go_left();		//store the temp response
		storage =traverse(temp,storage);			//life_choice is the kind of path you are on
	}
	else
	{
		bst_node * temp = root->go_right();		//store the temp response if it's right
		storage = traverse(temp,storage);		//store the integer array
	}
	return storage;			//return the storage array
}



//every other time you traverse the tree - there is the option to traverse backwards
int * bst::traverse_wr(int * store)
{
	//access the array's second element and traverse the bst until they're equal (retrieve functio
	//call the traverse 2 function when I do
	//no nodes
	//nodes
	int name = store[1];				//store the name inside the first element
	store = ask(root,store);
	return store;				//return array of integers
}




//retrieve where you are inside the bst I: bst node root, int name O: return a bst_node
bst_node * bst::retrieve_node(bst_node * root,int name)
{
	if (root == NULL)		//check if it's null
		return NULL;
	else
	{
		if (root->get_name() == name)		//check it's equivilent
		{	//return it
			return root;
		}
		else
		{
			if (root->get_name() >= name)	//if it's bigger
				retrieve_node(root->go_left(),name);	//go left
			else	//if it's smaller go right
				retrieve_node(root->go_right(),name);
		}
	}
}



//ask where they want to go - I: give it a root, and an array of numbers O: integer of arrays
int * bst::ask(bst_node *& root,int * storage)
{
	int path_number = root->get_name();
	storage[2] = path_number;

	int response = root->ask_direction1();		//holds whether they want to go backwards, left or right
	if (response ==0)
	{
		bst_node * current = retrieve_node(root,storage[1]);
		storage =traverse(current->go_left(),storage);			//life_choice is the kind of path you are on
	}
	if (response == 1)
	{
		bst_node * current = retrieve_node(root,storage[1]);		//check if that's the response ->go and find the node
		storage = traverse(current->go_right(),storage);
	}
	if (response == 2)
	{
		bst_node * current = retrieve_node(root,storage[3]);
		storage = traverse(current,storage); 
	}
	return storage;			//return the array of integers
}



//traverse the tree I: node of root and integer ptr O: itnerg array
int * bst::traverse(bst_node *& root,int * storage)
{
	if (root == NULL)
	{
		storage[0] = 111;	//return odd and loose a life
		return storage;
	}
	//will never happen (because of insertion algorithm
	if (root->go_left() == NULL && root->go_right() == NULL)		//check if you are a child node
	{	
		storage = root->is_finish_line(storage);			//check if you loose points or gain
		return storage;			//return array pointer
	}
	else
	{
		storage = root->what_intersection(storage);		//cechk if it has children
		return storage;
	}
}
