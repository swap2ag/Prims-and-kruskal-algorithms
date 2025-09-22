#ifndef GRAPH_INCLUDE
#define GRAPH_INCLUDE

class graph
{

	int *adjMat;                            // adjacency matrix to represent the graph
	int numNodes;                           // number of nodes in the graph
    int infCost,maxCost;                    // infCost denotes the cost to be treated as infinity (ie for those vertices that have been already included in U)
                                            // maxCost stores the maximum cost edge of the graph
	public:
        int *mst;                           // Minimum Spanning Tree is stored in mst array
        int mstCost;                        // tracks the cost of MST
        //=====Constructor==
        graph(int n);                       // Number of nodes have to be passed and and a graph with no edges will be constructed

        //=====Getters======
        int getNumNodes();                  // Returns number of nodes in graph
        int getEdge(int i, int j);          // Returns cost of edge between ith and jth node of graph which is in adjacency matrix
        int getInfCost();                   // Returns infCost variable
        int getMaxCost();                   // Returns maxCost variable

        //=====Setters=====
        void setEdge(int i,int j, int val); // sets val as the cost of edge between ith and jth vertices
        void findMaxCost();                 // finds maximum cost edge in graph
        void displayMST();                  // displays MST edges
};
#endif // GRAPH_INCLUDE

