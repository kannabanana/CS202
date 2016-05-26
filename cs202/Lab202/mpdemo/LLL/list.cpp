#include "list.h"
using namespace std;

/*
   void display_all(node * head)
   {
   if (head == NULL)
   return;
   if (head != NULL)
   {
   cout << head->data << '\t';
   return display_all(head->next);
   }
   }


   void display_every_other(node * head)
   {
//nodes
if (head == NULL)
return;
if (head != NULL)
{
if (head->next == NULL)
{
cout << head->data << "-> ";
return;
}
if (head->next->next == NULL)
{
cout << head->data << "-> ";
return;
}

cout << head->data << "-> ";
return display_every_other(head->next->next);
//have only one
//have two
//have more than two
}
}


//display last
void display_last(node * head)
{
if (head == NULL)
return;
if (head->next == NULL)
{    cout << head->data;
return;
}
return display_last (head->next);
}


//function to count number of matching
int count_match(int num,node * head)
{
if (head == NULL)
return 0;
if (head != NULL)
{
if (head->data != num)
{
return (count_match(num,head->next)+0);
}
if (head->data == num)
{
return (count_match(num,head->next)+1);
}
}
}


int count_nodes(node * head)
{
    if (head == NULL)
        return 0;
    if (head != NULL)
        return (count_nodes(head->next)+1);
    //no nodes
    //nodes
    //  call head+1,
}



//count the number of twos
int count_twos(node * head)
{
    if (head == NULL)
        return 0;
    if (head->data != 2)
        return (count_twos(head->next)+0);
    if (head->data == 2)
        return (count_twos(head->next)+1);
}


//count the total
int count_total(node * head)
{
    if (head == NULL)
        return 0;
    if (head != NULL)
        return (count_total(head->next)+head->data);
    //no nodes
    //nodes
    //  take the nodes+nodes->data
}


int total_even(node * head)
{
    if (head == NULL)
        return 0;
    if ((head ->data)/2)==
        2k+1
            2k
            //no nodes
            //nodes
            //  node is odd
            //      return
            //  ndoe is  even
            //      return +head->data
}


//delete all nodes in the list
void remove_all(node *& head)
{
    if (head == NULL)
        return;
    if (head != NULL)
    {
        node * temp = head->next;
        delete head;
        head = temp;
        remove_all(head);
        //no nodes
        //nodes
        //assign a temp ptr to the next
        //delete head
        //set head to the temp
        //call the function on head
    }
}


int remove_all_not_last(node *& head)
{
    if (head == NULL)
        return -1;
    if (head != NULL)
    {
        if (head->next == NULL)
        {
            return 0;
        }
        if (head->next != NULL)
        {
            node * temp = head->next;
            delete head;
            head = temp;
            return (remove_all_not_last(head)+0);
        }
    }

    //remove everything but the last
    //POSSIBLE:
    //  find out the last value, remove all, and insert the last one back in
    //
    //POSSIBLE:
    //  no nodes
    //      return -1
    //nodes
    //     only one node
    //          don't do anything
    //      more than one
    //          delete it
}



//remove all but the last
void remove_all_but_last(node *& head)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
        return;
    if (head->next != NULL)
    {
        node * temp = head->next;
        delete head;
        head = temp;
        remove_all_but_last(head);
    }
}


void remove_last(node *& head)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    //one node
    remove_last(head->next);
    //more than one node
}

*/



//add to end w/o a tail pointer
void add_to_end(node *& head,int num)
{
    if (head == NULL)
        return;
    if (head != NULL)
    {
        if (head->next == NULL)  //at the end of the list
        {
            node * temp = new node;
            temp = head->next;
            temp->data = num;
            temp->next = NULL;
            return;
        }

        if (head->next != NULL) //not at the end of the list
            return  add_to_end(head->next,num);
    }
}



void display_every_other(node * head)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        cout << head->data << endl;
        return;
    }
    if (head->next->next == NULL)
    {
        cout << head->data << endl;
        return;
    }
    if (head->next->next != NULL)
    {    
        cout << head->data << "-> ";
        return display_every_other(head->next->next);
        //no nodes
        //one node - display
        //two nodes - display first
        //more than two
        //call function to with head->next->next
    }
}


void display_all(node * head)
{
    if (head == NULL)
        return;
    if (head != NULL)
    {
        cout << head->data << "-> ";
        display_all(head->next);
    }
}


void display_last(node * head)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {    cout << head->data << endl;
        return;
    }
    if (head->next != NULL)
        return display_last(head->next);
}


//count number of matching items - supplied as argument
int count_match(int num, node * head)
{
    if (head == NULL)
        return 0;
    if (head != NULL)
    {
        if (head->data == num)
        {
            return (count_match(num,head->next)+1);
        }
        return (count_match(num,head->next)+0);
    }
}


int count_nodes(node * head)
{
    if (head == NULL)
    {
        return 0;
    }
    if (head != NULL)
        return (count_nodes(head->next)+1);
}


int count_even(node * head)
{
    if (head == NULL)
        return 0;
    if (head != NULL)
    {
        if (head->data%2 != 0)
            return (count_even(head->next)+0);
        return(count_even(head->next)+1);
    }
}


void remove_all(node *& head)
{
    if (head == NULL)
        return;
    if (head != NULL)
    {
        remove_all(head->next);
        delete head;
        head = NULL;

    }
}


//remove everyhing but the last node
int remove_not_last(node *& head)
{
    if (head == NULL)
        return -1;
    if (head->next == NULL)
        return -1;
    if (head->next != NULL)
    {
        node * temp = head->next;
        delete head;
        head = temp;
        remove_not_last(head);
    }
}

void remove_last(node *& head)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    if (head->next != NULL)
    {
        remove_last(head->next);
    }

}


void remove_all_twos(node *& head)
{
    if (head == NULL)
        return;
    if (head != NULL)
    {
        if (head->data == 2)
        {
            node * temp = head->next;
            delete head;
            head = temp;
            return remove_all_twos(head);
        }
        if (head->data != 2)
            return remove_all_twos(head->next);
    }
}


void remove_every_other(node *& head)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    if (head->next->next == NULL)
    {
        node * temp = head->next;
        delete head;
        head = temp;
        return;
    }
    if (head->next->next != NULL)
    {
        node * temp = head->next;
        delete head;
        head = temp;
        remove_every_other(head->next);
    }
    //no nodes
    //one node
    //two nodes
    //  remove first
    //more than two
    //remove the first and not the second
    //call function on head->next`
}



void remove_all_even(node *& head)
{
    if (head == NULL)
        return;
    if (head != NULL)
    {
        if (head->data%2 == 0)
        {   
            node * temp = head->next;
            delete head;
            head = temp;
            remove_all_even(head);
            return;
        }
        remove_all_even(head->next);
    }
}


void copy_backward_lll(node * source,node *& dest)
{
    if (source == NULL)
    {    
        return;
    }

    if (source != NULL)
    {

        if (dest == NULL)
        {
            dest = new node;
            dest->data = source->data;
            dest->next = NULL;
            return copy_backward_lll(source->next,dest);
        }          
        else
        {
            node * temp = new node;
            temp->data = source->data;
            temp->next = dest;
            dest = temp;
            return copy_backward_lll(source->next,dest);
        }
    }
}

//copy backwards into array
void copy_backwards_array(node *& head)
{
    if (head == NULL)
        return;
    //call count
    int num = count_nodes(head);
    int array[num];

    node * temp = head;
    for (int i = num-1;i >= 0;--i)
    {
        array[i] = temp->data;
        temp = temp->next;
    }

    for(int i = 0; i < num; ++i)
        cout << array[i] << " ";
    cout << endl;

}


void insert_before_two(node *& head,int num)
{
if (head == NULL)
    return;
if (head->next == NULL)
{
    if (head->data == 2)
    {
        node * temp = new node;
        temp->data = num;
        temp->next = head;
        head = temp;
        return;
    }
    return;
}
if (head->next != NULL)
{
    if (head->data != 2)
    {
        insert_before_two(head->next,num);
    }
    if (head->data == 2)
    {
        node * temp = new node;
        temp->data = num;
        temp->next = head->next;
        head->next = temp;
        insert_before_two(head->next->next,num);
    }
}
}




void copy_only_twos(node * source,node *& dest)
{
if (source == NULL)
{
    dest = NULL;
    return;
}
if (source != NULL)
{
    {
    if (source->data == 2)
    {
        dest = new node;
        dest->data = source->data;
       return  copy_only_twos(source->next,dest->next);
    }
    if (source->data != 2)
        return copy_only_twos(source->next,dest);
    }
}
}

void remove_first_two(node *& head)
{
if (head->next != NULL)
    remove_first(head);
if (head->next != NULL)
    remove_first(head);

}

void remove_first(node *& head)
{
if (head == NULL)
    return;
//one node
if (head->next == NULL)
{
    delete head;
    head == NULL;
    return;
}
//more than one node
if (head->next != NULL)
{
    node * temp = head->next;
    delete head;
    head = temp;
    return;
}
}


void remove_before_twos(node *& head)
{
if (head == NULL)
{
    return;
}
if (head->next == NULL)
{
    if (head->data == 2)
    {
        delete head;
        head = NULL;
    }
    return;
}
if (head->next != NULL)
{
    if (head->data == 2)
    {
        node * temp = head->next;
        delete head;
        head = temp;
        remove_before_twos(head->next);
    }
    if (head->data != 2)
        remove_before_twos(head->next);
}
}



void remove_last_two(node *& head)
{



}

void copy_first_last_two(node * source,node *& dest)
{


}

/*
void remove_middle(node *& head)
{
int count = count_nodes(head);
if (count%2 == 2)
    remove_node_odd(head,(num+1)/2);
if (count%2 != 2)
    //remove
}
*/




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



void remove_from_origional(node *& head)
{
if (head == NULL)
    return;
if (head->next == NULL)
{
   return;
}
if (head->next->next == NULL)
{
    node * temp = head->next;
    delete temp;
    temp = NULL;
    head->next = NULL;
    return;
}
if (head->next->next != NULL)
{
    node * temp = head->next->next;
    node * current = head->next;
    delete current;
    current = NULL;
    head->next = temp;
    return remove_from_origional(head->next);
}
}


//change the value of the last node to sum of preceding values
void change_last_value(node *& head)
{
//find the last nodes value
    remove_last(head);
  int num=  count_nodes(head);
//  insert it back into the list

 // set_last_to_sum(head,sum);
}



void set_last_to_sum(node *& head,int num)
{
if (head == NULL)
    return;
if (head->next == NULL)
{
    head->data = num;
    return;
}
if (head->next != NULL)
{
    return set_last_to_sum(head->next,num);

}
}
//no nodes
//return
//one node
//set it to the value
//more than one
    //keep going until you're at last
