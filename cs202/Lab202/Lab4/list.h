//list.h
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
void duplicate(node * &new_copy, node *original); //supplied

/* *****************YOUR TURN! ******************************** */
/* These are the functions you will be implementing for this lab */

int num_times(node * head, int match);
int display_first_last(node * head);
bool remove_except(node * & head);
void duplicate(node * &new_copy, node *original); 
bool same_contents(node * head1, node * head2);
