#include "clist.h"
using namespace std;


void copy_every_other(node *& head,node *& copy)
{
    if (head == NULL)
        return;
    node * temp = head;
    node * temp2 = head->next;
    head = temp2;
    temp->next = NULL;  //changing into LLL

    copy_every_other_lll(head,copy);
    sew_lll(head,head);
}

void copy_every_other_lll(node * source,node *& dest)
{
    if (source == NULL)
    {    
        dest = NULL;
        return;
    }
    if (source != NULL)
    {
        dest = new node;
        dest->data = source->data;
        return copy_every_other_lll(source->next->next,dest->next);
    }
}


void sew_lll(node * head,node *& head2)
{
if (head == NULL)
    return;
if (head2->next != NULL)
    sew_lll(head,head2->next);
if (head->next == NULL)
    head2->next = head;
}
