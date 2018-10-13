class graph
{

	bool *adjMat;										//Corresponding adjacency matrix which represents the graph
	int numNodes;										//Number of nodes in the graph
	public:
	graph(int n);										// Number of nodes have to be passed and and a graph with no edges will be constructed by this
	//=====Getters======
	match* getv(int m);									//returns the pointer to mth match
	int getNumNodes();									//returns the number of nodes in the graph
	int getEdge(int i, int j);							//Returns cost of edge between ith and jth node of graph otherwise returns false. This info is stored in adjacency matrix of the graph.
	//=====Setters=====
	void setEdge(int i,int j, int val);					//set the edge between the ith and jth vertex as the val by modifying the adjacency matrix
	void setV(int m,int homeTeam,int awayTeam);			//set the home teams and away teams as homeTeam and awayTeam respectively of the mth node of the graph
};

