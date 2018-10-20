#include"graph.h"
#include<iostream>
using namespace std;
graph::graph(int n)

{
    adjMat = new int[n*n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            *(adjMat+i*n+j) = -1;
        }
    }
    numNodes = n;
    infCost = 0;
    mstCost = 0;
    maxCost = 0;
    
}										// Number of nodes have to be passed and and a graph with no edges will be constructed by this
//=====Getters======
int graph::getNumNodes()
{
    return numNodes;
}									//returns the number of nodes in the graph
int graph::getEdge(int i, int j)
{
    return *(adjMat+i*numNodes+j);
}							//Returns cost of edge between ith and jth node of graph otherwise returns false. This info is stored in adjacency matrix of the graph.
//=====Setters=====
void graph::setEdge(int i,int j, int val)
{
    *(adjMat+i*numNodes+j) = val;
    *(adjMat+j*numNodes+i) = val;
}				//set the edge between the ith and jth vertex as the val by modifying the adjacency matrix
void graph::findMaxCost()
{
    maxCost = *adjMat;
    for(int i=0;i<numNodes;i++)
    {
        for(int j=0;j<numNodes;j++)
        {
            if(getEdge(i,j)>maxCost)
            {
//                cout<<"\nOld maxcost: "<<maxCost<<"\n";
                maxCost = getEdge(i,j);
//                cout<<"\nNew maxCost: "<<maxCost<<endl;
            }
//            else
//                cout<<"\nStill the same old maxCost: "<<maxCost<<endl;
        }
    }
    infCost = maxCost+2;    // since maxCost+1 is the cost of missing edges and infCost is for vertex already in U.
}
void graph::displayMST()
{
    for(int i=0;i<2*(numNodes-1);i=i+2)
    {
        cout<<"("<<*(mst+i)+1<<","<<*(mst+i+1)+1<<")\n";
    }
}
int graph::getInfCost()
{
    return infCost;
}
int graph::getMaxCost()
{
    return maxCost;
}


