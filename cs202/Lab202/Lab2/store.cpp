#include "store.h"
using namespace collection;

//These are the functions you will be implementing for Lab #2

//Default constructor
binary_tree::binary_tree()
{
    root = NULL;
}


//Place your binary_tree copy constructor here. Make this a
//wrapper function, calling the recursive copy function below
//
//You should have already placed the prototype for this function
//in the .h file (that was NOT done for you already!)
//Use CARE when deciding the SYNTAX for the copy constructor!
//
//YOU WILL NEED TO "uncomment out" THIS CODE ONCE THIS 
//FUNCTION IS WRITTEN!
binary_tree::binary_tree(const binary_tree & source)
{
    copy_tree(root,source.root);
} 

//Recursive copy function
void binary_tree::copy_tree(node * & result, node * source)
{
if (source == NULL)
    result == NULL;
if (source != NULL)
{
    result = new node(*source);
    copy_tree(result->go_left(),source->go_left());
    copy_tree(result->go_right(),source->go_right());

}
}

//Implement the binary_tree destructor. Make this a
//wrapper function, calling the recursive delete_all function below
binary_tree::~binary_tree()
{
    delete_all(root);
}

//Recursive delete all function
void binary_tree::delete_all(node * & root)
{
if (root == NULL)
    return;
if(root->go_left() == NULL && root->go_right() == NULL)
    delete root;
if (root -> go_left() != NULL)
    delete_all(root->go_left();
if (root-> go_right() != NULL)
   delete_all(root->go_right();
}

//BST constructor
BST::BST()
{

    balance_factor = 0;
}

//store default constructor
//Think about what this should do
store::store()
{
    //call copy constructor
    address.read();
    name.read();
}

//Store constructor with an argument
//Hint: Think about initialization lists
store::store(char * new_store_name, address & stores_location):location(stores_location),store_name(new_store_name)
{



}

//Display all - think about what the job of this function should be:
void store::display_all() 
{
if (root == NULL)
    return;
if (root!= NULL)
{
    display_all(root->go_left());
    store_name.display() << '\t';
    location.display() << '\t';
    display_all(root->go_right());
}
}
