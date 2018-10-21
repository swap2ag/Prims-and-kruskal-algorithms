/*
    This file contains the definitions for GRAPH ADT.
    I have used adjacency matrix representation for the graph.
*/
#include"graph.h"                               // includes declaration of graph ADT
#include<iostream>                              // for displayMST()
using namespace std;

graph::graph(int n)                             // n is number of nodes
{
    adjMat = new int[n*n];                      // creates adjacency matrix of size n*n
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            *(adjMat+i*n+j) = -1;               // initializes all elements to -1 (although not required)
        }
    }
    numNodes = n;                               // sets numNodes equal to n
    infCost = 0;                                // sets infinity cost, mstCost, maxCost to 0
    mstCost = 0;
    maxCost = 0;

}
//=====Getters======
int graph::getNumNodes()                        // returns the number of nodes in the graph
{
    return numNodes;
}
int graph::getEdge(int i, int j)                // returns the cost of edge between ith and jth vertices of graph
{
    return *(adjMat+i*numNodes+j);
}
//=====Setters=====
void graph::setEdge(int i,int j, int val)       //sets the edge between the ith and jth vertex as the val by modifying the adjacency matrix
{
    *(adjMat+i*numNodes+j) = val;
    *(adjMat+j*numNodes+i) = val;
}
void graph::findMaxCost()                       // finds maximum cost edge in graph
{
    maxCost = *adjMat;                          // assumes first cost as maximum
    for(int i=0;i<numNodes;i++)                 // then goes on finding maximum cost by comparing with all elements
    {
        for(int j=0;j<numNodes;j++)
        {
            if(getEdge(i,j)>maxCost)
            {
                maxCost = getEdge(i,j);
            }
        }
    }
    infCost = maxCost+2;                        // since maxCost+1 is the cost of missing edges and infCost is for vertex already in U, so infCost is maxCost+2
}
void graph::displayMST()                        // displays MST of the graph
{
    for(int i=0;i<2*(numNodes-1);i=i+2)         // since we store name of vertices in an array of name mst, so traversing it
    {
        cout<<"("<<*(mst+i)+1<<","<<*(mst+i+1)+1<<")\n";
    }
}
int graph::getInfCost()                         // returns infCost
{
    return infCost;
}
int graph::getMaxCost()                         // returns maxCost
{
    return maxCost;
}
