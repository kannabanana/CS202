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
void build(node * & head);  //supplied
void display(node * head);  //supplied
void destroy(node * &head); //supplied
void duplicate(node * & new_copy); //provides a duplicate copy of the list

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:

void copy_every_other(node * source);
void display_lll(node * head);
void remove_all_twos(node *& head);
void sew_cll(node *& rear,node *& rear2);
