/*

//class of bst nodes
class node_bst: public lll //course
{
public:

	node_bst();		//default constructor I/O: Nothing
	~node_bst();		//deconstructor I/O: Nothing
	node_bst(const node_bst &);	//copy constructor I: object of type node_bst O: Nothing

	node_bst *& go_right();	//function to retrieve a right pointer I: Nothing O: Node
	node_bst *& go_left();	//function to retrieve a left pointer I: Nothing O: node
	char *& get_term();	

protected:
//	node_bst * right;	//right ptr
//	node_bst * left;	//left ptr
//	char * term;
};

*/

/*
//default constructor
node_bst::node_bst()
{
	right = NULL;
	left = NULL;
}


//deconstructor
node_bst::~node_bst()
{
	right = NULL;
	left = NULL;
}


//copy constructor
node_bst::node_bst(const node_bst & node_bst_obj):lll(node_bst_obj)
{

}

//getter for right ptr
node_bst *& node_bst::go_right()
{
	return right;
}


//getter for left ptr
node_bst *& node_bst::go_left()
{
	return left;
}


char *& node_bst::get_term()
{
	return term;	
}




void manager::insert_less_than_root(node_term *& root,node_term *& insert_bst)
{
	if (root->go_left() == NULL)
	{
		if(root->go_right() == NULL)
		{
			root->go_right() = insert_bst;
		insert_bst->go_left() = NULL;
		insert_bst->go_right() = NULL;
		insert_bst->go_next() = NULL;
	
			return;

		}
		if (root->go_right() != NULL)
		{
			//call helper
			insert_less_helper(root->go_right(),insert_bst);
		}
	}
	//keep going left
	return insert_less_than_root(root->go_left(),insert_bst);
}


void manager::insert_less_helper(node_term *& root,node_term *& insert_bst)
{
	if (root == NULL)
		return;
	if (root->go_right() == NULL)
	{
		root->go_right() = insert_bst;
		insert_bst->go_left() = NULL;
		insert_bst->go_right() = NULL;
		insert_bst->go_next() = NULL;
		return;
	}
	return insert_less_helper(root->go_right(),insert_bst);
}



void manager::insert_more_than_root(node_term *& root,node_term *& insert_bst)
{
	if (root->go_right() == NULL)
	{
		if (root->go_left() == NULL)
		{
			root->go_left() = insert_bst;
		insert_bst->go_left() = NULL;
		insert_bst->go_right() = NULL;
		insert_bst->go_next() = NULL;
	
				return;
		}

		if (root->go_left() != NULL)
		{
			//call helper
			insert_more_helper(root->go_left(),insert_bst);
		}
	}
	return insert_more_than_root(root->go_right(),insert_bst);
}


void manager::insert_more_helper(node_term *& root,node_term *& insert_bst)
{
	if (root == NULL)
		return;
	if (root->go_left() == NULL)
	{
		root->go_left() = insert_bst;
		insert_bst->go_left() = NULL;
		insert_bst->go_right() = NULL;
		insert_bst->go_next() = NULL;
		return;
	}
	return insert_more_helper(root->go_left(),insert_bst);
}




void manager::find_sucessor(node_term * root,node_term *& root2)
{
if (root2->go_right() == NULL)
	{
	if(root2->go_left() == NULL)
	{
		//copy_replace(root,root2);
	
		delete root2;
		root2 = NULL;
		return;
	}
	if (root2->go_left() != NULL)
	{
	//	copy_root(root,root2);
		node_term * temp = root2->go_left();
		delete root2;
		root2 = temp;
		return;
	}

	}
	return find_sucessor(root,root2->go_right());
}



*/
