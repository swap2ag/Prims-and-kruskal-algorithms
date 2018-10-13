#include <iostream>

using namespace std;

// class to represent each node of the list (lnode)
class lnode{
	unsigned short item;
	lnode * next;
public:
	// ---- Constructors -------
	lnode();							// constructor for lnode class
	lnode(int,lnode *);					// overloaded constructor for initializing node
	// ---- Setters ------------
	void setitem(int n);				// sets the item to n
	void setnext(lnode * ptr);			// sets ptr as the contents of the next pointer
	// ---- Getters ------------
	int getitem();						// returns the value of item of a lnode
	lnode * getnext();					// return the pointer to the next element of the lnode
};

// Function definitions
void lnode::setnext(lnode * p)
{
	next = p;
}
lnode::lnode(){
	item = 0;
	next = NULL;
}

lnode::lnode(int x, lnode * ptr)		//overloaded constructor
{
	item = x;
	next = ptr;
}

void lnode::setitem(int n)
{
	item = n;
	next=NULL;
}

int lnode::getitem()
{
	return item;
}

lnode * lnode::getnext()
{
	return next;
}

// class to create various lists having lnodes
class list{
public:
	
	lnode * head;									//points to the start of the list
	list();											//constructor to initialize list, similar to a makenull function
	void insert(lnode *p, int x);					//inserts a node after node p with value x
	lnode * lastNode();								//returns the pointer to the last element of the list

	
};







list::list()										//Similar to makenull(). Creates a head as a lnode and initializes it with
{													//item value 0 and next pointing to NULL
	head = new lnode();
	head->setitem(0);
	head->setnext(NULL);
}



void list::insert(lnode * p, int x)
{
	if (p != NULL)    								//checks if P is not NULL
	{
		lnode *temp = new lnode(x, p->getnext());	//creates a new node with required value x and sets its next to p's next. 
		p->setnext(temp);							//make p's next point to node just created
	}
	else
		cout << "NULL pointer detected!!!";			//if NULL is detected
}





lnode * list::lastNode()
{
	lnode * ptr = head;
	while (ptr->getnext() != NULL)						//make ptr pont to the next node untill it is the last node
	{
		ptr = ptr->getnext();
	}
	return ptr;
}

