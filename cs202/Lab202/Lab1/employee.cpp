#include "employee.h"
using namespace std;

//Step 6 implement select functions as provided here:

employee::employee(char * name, char * street, char * zip, int id):person(name,street,zip), employee_id(id), root(NULL)
{ 
        //Avoid accessing the base class members here.
        //Instead, use an initialization list to cause the
        //base class constructor to be called with the name
}

//Set up a new hourly employee, give a person's information
//Think about how to use the member functions inherited to
//initialize the new hourly employee.
//Avoid use of the = operator as it does a shallow copy!
hourly_employee::hourly_employee(const person & input):employee(input)
{

//person(name_of_person)
}

//employee::employee(const employee & source):person(source)
//{..}

//Implement the wrapper function to display an employee
//and then call the recursive display function to display
//the BST containing performance review information
void employee::display() const
{
    display(root);  //wrapper function
}


//Implement the recursive display function using the 
//functions available within the hierarchy
void employee::display(node * root) const
{
if (root == NULL)
    return;
display(root->left);
cout << root-> employee_id;
display(root->right);
}

//Challenge - implement a recursive copy function
void employee::copy_tree(node * & dest_root, node * source_root) const
{
{
if (source_root == NULL)
    dest_root = NULL;
else
{
    dest_root = new node(*source_root);         //WHAAAA?
copy(dest_root->go_left(), source_root->go_left());     //pass by reference allows you to modify the actual pointer 
}
