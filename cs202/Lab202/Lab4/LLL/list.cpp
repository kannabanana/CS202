#include "list.h"
using namespace std;

//count the number of times you get a match to the data
int num_times(node * head, int match)
{
if (head == NULL)
    return 0;
if (head->data != match)
    return (num_times(head->next,match)+0);
if (head->data == match)
    return (num_times(head->next,match)+1);
//no data
//nodes
    //the data matches
    //the data doesn't match
}

int display_first_last(node * head)
{
    int first = first_node(head);
    cout << "This is the first node " << first << endl;
    int last = last_node(head);
    cout << "This is the last node " << last << endl;
    return (first+last);
    //return the sum of the two
}

int first_node(node * head)
{
if (head == NULL)
    return 0;
if (head != NULL)
    return head->data;
//no nodes
//nodes
}

int last_node(node * head)
{
if (head == NULL)
    return 0;
if (head != NULL)
{
    if (head->next != NULL)
        return (last_node(head->next)+0);
    if (head->next == NULL)
        return (last_node(head->next)+(head->data));
}
//no nodes
//nodes
    //not at the last node
    //at the last node
    //return the data

}


//remove all but hte last two in linked list
bool remove_except(node *&  head)
{
if (head == NULL)
    return false;
if (head ->next == NULL)
    return false;
if (head->next->next == NULL)
    return false;
if (head->next->next != NULL)
{
    node * temp = head->next;
    delete head;
    head = temp;
    return remove_except(head)+true;
}
//no nodes
//one node
//two nodes
//more than two nodes
//set temp to head->next
//remove head
//set head to temp
//call the function with head

}


//determine if two linked lists are contain the same values
bool same_content(node * head1, node * head2)
{
if (head1 == NULL && head2 == NULL )
    return true;
if (head1 == NULL && head2 != NULL)
    return false;
if (head2 == NULL && head1 != NULL)
    return false;
if (head1 != NULL && head2 != NULL)
{
    if (head1->data != head2->data)
        return false;
    if (head1->data == head2->data)
        return (same_content(head1->next,head2->next)+1);
}
//no data
//  true
//  data
//  if the data of of the first linked list doesn't match the second
//  return false
//  if it data matches
//  keep going

}

/*
//copy backwards
void copy_backwards(node * origional, node *& copy)
{
//no nodes
//  set 
//nodes
//

}

void 
*/

