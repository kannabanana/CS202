//clist.h
#include <iostream>
#include <cstring>
#include <cctype>


struct node
{
    int data;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & rear);  //supplied
void display(node * rear);  //supplied
void destroy(node * &rear); //supplied
void duplicate(node * & new_copy); //provides a duplicate copy of the list

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:

void duplicate(node *& new_copy,node * origional);
void duplicate_lll(node *& new_copy,node * origional);
void sew_back_cll(node * head, node *& head2);
