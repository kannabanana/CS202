/*
SR Kanna
CS202
HW1

CARD.H
PURPROSE OF FILE: This is the application file. It's human readable. It contains all the prototypes for the implementation for the card class and the derived node class


*/



//has a relationship from deck
class card
{
	public:
		card();				//default construcor. I/O: Nothing
		card(int number,int suit);	//constructor w/arguments. I: Takes the number and suit. O: Nothing (initialization list used)
		card(int number);		//constructor w/arguments. I: Takes the number. O: Nothing. (Initialization list used)
		
		card(const card &);		//copy constructor. I: Takes card class. O: Nothing
		~card();			//destructor. I/O: Nothing

//FUNCTIONS:
	
		int compare(int to_compare);	//compare the input with the number I: Number which you want to compare to the number. O: True/False flag 
		void display(void);		//display function. I/O: Nothing
		void display_number();		//displays the number. I/O: NOthing

	protected:
		int number;			//number on the card
		int  suit;			//suit on the card
};


//has a is a relationship with card
class node:public card
{
	public:
		node();						//default constructor I/O: Nothing
		node(int number,int suit);			//Constructor that takes in the num & suit - for initilization list to be passed back. I: num and suit. O: Nothing
		node(int number);				//constructor with arguments of number used for initilization. I: Number. O: Nothing
		node(node * next,node * previous);		//constructor with arguments of protected data. I: Next and previous ptrs. O: Node
		node(const node &);				//copy constructor. I: Node class. O: Nothing
		~node();					//destructor

//FUNCTIONs:
		int get_card_number(node * head);		//Getter function to get the number at the node passed in. I: head. O: head->number
		node *& go_next();				//Next function. I: Nothing. O: Node
		node *& go_previous();				//Previous function. I: Nothing. O: Node

	protected:
		node * next;
		node * previous;

};


