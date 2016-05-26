//doubly linked list
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>


struct node
{
    int data;
    node * previous;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display(node * head);  //supplied
void destroy(node * &head); //supplied

/* *****************YOUR TURN! ******************************** */
/* place your prototype here */
void copy_DLL(node * source,node *& dest);
void remove_end_DLL(node *& head);
void remove_last_node_lll(node *& head);
void DLL_LLL(node * head);
void set_previous(node * head);
