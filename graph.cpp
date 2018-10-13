#include<iostream>
class match{											//ADT that stores a match scenario Home team vs Away team with its color(or day)
	int homeTeam,awayTeam,color;						
		
	public:
		int getHomeTeam();								//returns an integer which represents the homeTeam of the match
		int getAwayTeam();								//returns an integer which represents the awayTeam of the match
		int getColor();									//Returns the integer that represents color assigned by greedy graph coloring.
		void setHomeTeam(int homeTeam);					//set the home team of the match as the homeTeam
		void setAwayTeam(int awayTeam);					////sets the away team of the match as awayTeam
		void setTeams(int homeTeam,int awayTeam);		//set both the home and away teams of the match
		void setColor(int color);						//sets the color of the match to int color. This function will be used in greedy graph coloring.
		match(){										// constructor to initialize the match ADT. Similar to makenull() function.
			homeTeam = 0;
			awayTeam = 0;
			color = -1;			// default color to no-color
		}
};
int match::getHomeTeam()
{
	return homeTeam;									//homeTeam of the match
}
int match::getAwayTeam()
{
	return awayTeam;									//return awayTeam of the match
}
int match::getColor()
{
	return color;										//returns the color assigned by the greedy algorithm to the match
}
void match::setHomeTeam(int homeTeam)
{
	this->homeTeam = homeTeam;							//set the home team of the match as the homeTeam
}
void match::setAwayTeam(int awayTeam)
{
	this->awayTeam = awayTeam;							//sets the away team of the match as awayTeam
}
void match::setColor(int color)
{
	this->color = color;								//sets the color of the match to int color. This function will be used in greedy graph coloring.
}
void match::setTeams(int homeTeam,int awayTeam)
{
	setHomeTeam(homeTeam);								//set both the home and away teams of the match
	setAwayTeam(awayTeam);
}

class graph
{
	match *v;											//A pointer based array of Match ADTs
	bool *adjMat;										//Corresponding adjacency matrix which represents the graph
	int numNodes;										//Number of nodes in the graph
	public:
	graph(int n);										// Number of nodes have to be passed and and a graph with no edges will be constructed by this 
	//=====Getters======
	match* getv(int m);									//returns the pointer to mth match
	int getNumNodes();									//returns the number of nodes in the graph
	bool getEdge(int i, int j);							//Return true if edge is present between ith and jth node of graph otherwise return false. This info is stored in adjacency matrix of the graph.
	//=====Setters=====
	void setEdge(int i,int j, int val);					//set the edge between the ith and jth vertex as the val by modifying the adjacency matrix
	void setV(int m,int homeTeam,int awayTeam);			//set the home teams and away teams as homeTeam and awayTeam respectively of the mth node of the graph
	void setVcolor(int m,int color);					//set the color as the color of the mth vertex of the graph. This will be also used by greedy graph coloring
};




// ----- Member Function definitions ----------------


graph::graph(int n)
{
	numNodes = n;										
	adjMat = new bool[numNodes*numNodes];				//create a bool array of (number of nodes) X (number of nodes) to store adjacency matrix
	v = new match[numNodes];							//makes a pointer v to array of matches.
}

match* graph::getv(int m)
{
	return &v[m];										//returns the pointer to mth match
}

bool graph::getEdge(int i, int j)
{
	return *(adjMat+i*numNodes+j);						//Return 1 if edge is present between ith and jth node of graph otherwise return 0
}

int graph::getNumNodes()
{
	return numNodes;									//return the number of nodes in the graph
}
void graph::setV(int m,int homeTeam,int awayTeam)
{
	v[m].setTeams(homeTeam,awayTeam);					//set the home teams and away teams as homeTeam and awayTeam respectively of the mth node of the graph
}

void graph::setVcolor(int m,int color)
{
	v[m].setColor(color);								//set the color as the color of the mth vertex of the graph
}

void graph::setEdge(int i,int j,int val)
{
	*(adjMat+i*numNodes+j) =  val;						//assign the value,'val' to the ith row and jth coloumn of adjacency matrix

}

