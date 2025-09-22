/*
    This file contains the definition of function for Kruskal's algorithm which takes a graph instance as input and returns it as output after creating MST
*/
#include <iostream>

#include "graph.h"
#include "kruskalADTs.h"
#include "kruskal.h"

graph kruskal(graph g)
{
    g.mst = new int[2*(g.getNumNodes()-1)];             // mst is an array and contains nodes in MST. For each edge, 2 vertices are there and thus 2 memory locations in MST.
    int currConnectedComponents,next=0;                 // current connected components
    priorityQueue q(g);                                 // declare a priority queue object
    q.makeNull();                                       // makes it NULL
    currConnectedComponents = g.getNumNodes();          // initially, all vertices are in different components
    mfset m(currConnectedComponents,currConnectedComponents);   // declares an MST

    for(int i=0;i<g.getNumNodes();i++)                  // initially add all elements to different sets
    {
        m.initial(next,i);
        next++;
    }

    for(int i=0;i<g.getNumNodes();i++)                  // add all edges present in graph in priority queue
    {
        for(int j=i+1;j<g.getNumNodes();j++)
        {
            if((g.getEdge(i,j)!= -1) && (g.getEdge(i,j)!=0))    // for all edges in E
            {
                PQ_entry x(i,j,g.getEdge(i,j));         // make a PQ_entry
                q.insertInPQ(x);                        // insert that entry in PQ
            }
        }
    }

    g.mstCost = 0;                                      // initialize mstCost as 0
    int mstIndex=0;                                     // initialize index of first element of mst

    while(currConnectedComponents>1)                    // till 1 connected component(ie full MST forms) remains
    {
        PQ_entry y;
        y = q.deleteMin();                              // delete the lowest cost edge from priority queue

        int Cu = m.findSet(y.getV1());                  // find the set to which first vertex of this lowest cost belongs to
        int Cv = m.findSet(y.getV2());                  // find the set to which second vertex of this lowest cost belongs to
        if (Cu != Cv)                                   // if both the sets are not same, then insert these vertices in MST
        {
            m.mergeSets(Cu,Cv);                         // Cu and Cv are set names
            *(g.mst+mstIndex) = y.getV1();              // inserts the vertex1 into MST
            g.mst[mstIndex+1] = y.getV2();              // insert the vertex 2 into MST
            g.mstCost = g.mstCost+y.getPriority();      // update the total cost of MST
            mstIndex = mstIndex + 2;                    // increment index of MST so as to store next elements
            currConnectedComponents--;                  // decrement the number of connected components since two components have merged into one
        }
    }
    // cout<<"\nKruskal's successfully over....\n";
    return g;
}

