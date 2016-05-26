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

void display_all(node * head);
void display_every_other(node * head);
void display_last(node * head); 
int count_match(int num, node * head);
int count_nodes(node * head);   //count the number of nodes
int count_twos(node * head);    //count the number of twos
int count_total(node * head);   //total count
int count_even(node * head);
void remove_all(node *& head);  //remove all
int remove_not_last(node *& head);
void remove_all_but_last(node *& head);
void remove_last(node *& head);
void remove_all_twos(node *& head);
void remove_every_other(node *& head);
void remove_all_even(node *& head);
void add_to_end(node *& head,int num);
int find_last(node * head);
void copy_backward_lll(node * source,node *& dest);
void copy_backwards_array(node *& head);
void insert_before_two(node *& head,int num);
void copy_only_twos(node * source,node *& dest);
void remove_first_two(node *& head);
void remove_first(node *& head);
void remove_before_twos(node *& head);
void copy_every_other_lll(node * source,node *& dest);
void remove_from_origional(node *& head);
void change_last_value(node *& head);
int sum_everything_but_last(node * head);
void set_last_to_sum(node *& head,int num);
