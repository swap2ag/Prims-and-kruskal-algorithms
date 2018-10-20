#ifndef GRAPH_INCLUDE
#define GRAPH_INCLUDE

class graph
{

	int *adjMat;										//Corresponding adjacency matrix which represents the graph
	int numNodes;										//Number of nodes in the graph
    int infCost,maxCost;
	public:
        int *mst;
        int mstCost;
        graph(int n);                                            // Number of nodes have to be passed and and a graph with no edges will be constructed by this
        //=====Getters======
        int getNumNodes();
        int getEdge(int i, int j);          // Returns cost of edge between ith and jth node of graph otherwise returns false. This info is stored in adjacency matrix of the graph.
        int getInfCost();
        int getMaxCost();
        //=====Setters=====
        void setEdge(int i,int j, int val);
        void findMaxCost();
        void displayMST();
};

#endif // GRAPH_INCLUDE

