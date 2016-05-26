//list.h
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
int num_times(node * head, int match);
int display_first_last(node * head);
int first_node (node * head);
int last_node(node * head);
bool remove_except(node *& head);
bool same_content(node * head1,node * head2);
