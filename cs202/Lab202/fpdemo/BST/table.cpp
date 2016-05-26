#include "table.h"
using namespace std;

//count the number of nodes in a tree
int count_nodes(node * root)
{
    if (root == NULL)
        return 0;

    if (root != NULL)
        return (count_nodes(root->left)+count_nodes(root->right)+1);
}

//return how many leaves are in the tree
int leave(node * root)
{
    if (root == NULL)
        return 0;

    if ((root->left) == NULL && (root->right) == NULL)
        return 1;

    return (leave(root->left)+leave(root->right));
}

//
void in_order_sucessor(node * root)
{
//no nodes
if (root == NULL)
    return;

//no children
if ((root-> left) == NULL && (root->right)== NULL)
{
    cout << root->data << endl;
    return;
}

//no right data - base case
if ((root->right == NULL))
{
    //call helper function for root->right
    helper_right(root->left);

}

if (root->right != NULL)
{
    //call helper funciton for root->right
    helper_left(root->right);

}
}


void helper_left(node * root)
{
if (root->left == NULL)
    cout << root->data << endl;
if (root->left != NULL)
    return helper_left(root->left);
}

void helper_right(node * root)
{
if (root->right == NULL)
    cout << root->data << endl;
if (root->right != NULL)
    return helper_right(root->right);
}

//remove remove the inorder sucessor
void remove_in_order(node *& root)
{
//no nodes
if (root == NULL)
    return;

//is a leaf
if (root->right == NULL && root->left == NULL)
{    delete root;
    root = NULL;
    return;
}

//does not have a right
if (root->right == NULL)
{
    helper_remove_sucessor(root->left);
    return;
}
//has a right
if (root->right != NULL)
{
    helper_remove_in_order(root->right);
    return;
}
}


void helper_remove_sucessor(node *& root)
{
if (root->right == NULL)
{
    if (root->left == NULL)         //no children
    {    delete root;
         root = NULL;
         return;
    }
    if (root->left != NULL)
    {
        node * temp = root->left;
        delete root;
        root = temp;
        return;
    }
}
    return helper_remove_sucessor(root->right);
}

void helper_remove_in_order(node *& root)
{
if (root->left == NULL)
{
    if (root->right == NULL)
    {
        delete root;
        root = NULL;
        return;
    }
    if (root->right != NULL)
    {
        node * temp = root->right;
        delete root;
        root = temp;
        return;
    }
}
    return helper_remove_in_order(root->left);
}

//remove the largest two items
void remove_largest(node *& root)
{
//no nodes
if (root == NULL)
    return;
//one node

if (root->right == NULL && root->left == NULL)
{
    delete root;
    root = NULL;
    return;
}
//has a no right
if (root->right == NULL)
{
    node * temp = root->left;
    delete root;
    root = temp;
    return;
}

//has a right
if (root->right != NULL)
{
    helper_remove_right(root->right);
    //call helper function
    return;
}   
}

void helper_remove_right(node *& root)
{
if (root->right == NULL)
{
    if(root->left == NULL)
    {
        delete root;
        root = NULL;
        return;
    }
    if (root->left != NULL)
    {
        node * temp = root->left;
        delete root;
        root = temp;
        return;
    }
}
    return helper_remove_right(root->right);
}

//count the number of times root's data appears
int wrapper_root_data(node * root)
{
    int root_data;
    int num = 100;
    root_data = count_root_data(root,num);
    return root_data;
}


int count_root_data(node * root,int num)
{
if (root == NULL)
    return 0;
if (root != NULL)
    {
        if (root->data == num)
        {
            return (count_root_data(root->left,num)+count_root_data(root->right,num)+1);
        }
        if (root->data != num)
        {
            return (count_root_data(root->left,num)+count_root_data(root->right,num)+0);
        }
    }   
}




//Copy BST
void copy_BST(node * source,node *& dest)
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
    copy_BST(source->right,dest->right);
    copy_BST(source->left,dest->left);

}
}
//
//
//
//


//remove all
void remove_all(node *& root)
{
if (root == NULL)
    return;
if (root != NULL)
{
    remove_all(root->left);
    remove_all(root->right);
    delete root;
    root = NULL;
}
}


//Copy into LLL
void copy_LLL(node * source,node *& dest)
{
if (source == NULL)
    return;
if (source != NULL)
{
    dest = new node;
    dest->data = source->data;
    copy_BST(source->right,dest->next);
    copy_BST(source->left,dest->next);
}
}
