//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;;
    node * next;
};

void build(node * & root);  //supplied
void display(node *  root); //supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
 
int count_nodes(node * root);
int leave(node * root);
void in_order_sucessor(node * root);
void helper_left(node * root);
void helper_right(node * root);
void remove_in_order(node *& root);
void helper_remove_sucessor(node *& root);
void helper_remove_in_order(node *& root);
void remove_largest(node *& root);
void helper_remove_right(node *& root);
void remove_all(node *& root);
int count_root_data(node * root,int num);
int wrapper_root_data(node * root);
void copy_BST(node * source, node *& BST);
void copy_LLL(node * source, node *& dest);
