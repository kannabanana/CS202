#include "clist.h"
using namespace std;


void duplicate(node *& new_copy,node * origional)
{
    node * temp = origional;
    node * temp2 = origional->next;
    origional = temp2;
    temp-> next = NULL; //cutting off LLL

    duplicate_lll(new_copy,origional);
    sew_back_cll(new_copy,new_copy);
    cout << "I'm about to display my duplicate " << endl << endl;
    display(new_copy);
}

void duplicate_lll(node *& new_copy,node * origonal)
{
//no nodes
if (origonal == NULL)
 {
        new_copy = NULL;
 }
if (origonal != NULL)
{
    new_copy = new node;
    new_copy->data = origonal->data;
    return duplicate_lll(new_copy->next,origonal->next);
//nodes
//create a new node for duplicate
//set duplicate to origonal's data
//call function with source's next and duplicate
}
}

void sew_back_cll(node * real_head, node *& head)
{
if (head == NULL)
    return;
if (head->next != NULL)
    sew_back_cll(real_head,head->next);
if (head->next == NULL)
    head->next = real_head;
}
