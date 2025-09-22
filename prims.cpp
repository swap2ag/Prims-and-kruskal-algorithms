/*
    This file contains the implementation of prim's algorithm
*/
#include"graph.h"
#include"prims.h"

graph prims(graph g)
{
    int i,j,k,minimum;
    int index=0;                                // index for mst array
    int n = g.getNumNodes();
    int* lowcost = new int [n];                 // create an array for which lowcost[i] stores the lowest cost to ith vertex in V-U from U
    int *closest = new int[n];                  // create an array for which closest[i] stores the node in U closest to node i in V-U
    g.mst = new int[2*(n-1)];

    *closest = 0;                               // since it is of no use, so setting to 0 (although not required as never accessed)
    *lowcost = 0;                               // since it is of no use, so setting to 0 (although not required as never accessed)
    for(i=1;i<n;i++)
    {
        *(lowcost+i) = g.getEdge(i,0);          // since initially first node is in MST, so initialize lowcost with the costs between all nodes and first node
        *(closest+i) = 0;                       // set first node as the closest element to all other nodes
    }
    for (i=1;i<n;i++)                           // find the minimum cost edge to all vertices in V-U and add the lowest cost edge to MST
    {
        minimum = *(lowcost+1);                 // let first cost be the lowest
        k = 1;
        for(j=2;j<n;j++)                        // traverse through all costs
        {
            if(*(lowcost+j) <minimum)
            {
                minimum = *(lowcost+j);
                k = j;
            }
        }
        *(g.mst+index) = k;                                 // add vertex1 to mst
        *(g.mst+index+1) = *(closest+k);                    // add vertex2 to mst

        index = index+2;                                    // since, mst array's 2 entries define a pair of vertices, so increment it by 2
        g.mstCost = g.mstCost + g.getEdge(k,closest[k]);    // update the cost of MST

        *(lowcost+k) = g.getInfCost();                      // assign infinity cost to the pair of vertices that have been placed in U recently
        for(j=1;j<n;j++)                                    // Update lowestcost to all vertices in V-U
        {
            if(g.getEdge(k,j)<*(lowcost+j) && (lowcost[j]<g.getInfCost()))
               {
                   *(lowcost+j) = g.getEdge(k,j);
                   *(closest+j) = k;
               }
        }
    }
    return g;                                               // return graph instance
}

