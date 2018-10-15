#include"graph.h"
#include<iostream>
#include"prims.h"

using namespace std;
void dispArrays(int *lowcost,int *closest,int n)
{
    int i;
    cout<<"Closest: ";
    for(i=0;i<n;i++)
        cout<<*(closest+i)<<" ";
    cout<<"\nlowcost: \n";
    for(i=0;i<n;i++)
        cout<<*(lowcost+i)<<" ";
    cout<<endl;
}
graph prims(graph g)
{
    int i,j,k,minimum;
    int index=0;          // for mst
    int n = g.getNumNodes();
    int* lowcost = new int [n];
    int *closest = new int[n];
    g.mst = new int[3*(n-1)];

    *closest = 0;   // since it is of no use
    *lowcost = 0;   // since it is of no use
    for(i=1;i<n;i++)
    {
        *(lowcost+i) = g.getEdge(i,0);
        *(closest+i) = 0;
    }
    dispArrays(lowcost,closest,n);
    cout<<"\nPrim's Algorithm MST: \n";
    for (i=1;i<n;i++)
    {
        minimum = *(lowcost+i);
        k = 1;
        for(j=2;j<n;j++)
        {
            if(*(lowcost+j) <minimum)
            {
                minimum = *(lowcost+j);
                k = j;
            }
        }
        *(g.mst+index) = k;
        *(g.mst+index+1) = *(closest+k);
        *(g.mst+index+2) = g.getEdge(k,closest[k]);
        index = index+3;
//        cout<<k<<" "<<*(closest+k)<<endl;
        g.mstCost = g.mstCost + g.getEdge(k,closest[k]);
        *(lowcost+k) = INF_COST;
        for(j=1;j<n;j++)
        {
            if(g.getEdge(k,j)<*(lowcost+j) && (lowcost[j]<INF_COST))
               {
                   *(lowcost+j) = g.getEdge(k,j);
                   *(closest+j) = k;
               }
        }
    }
    dispArrays(lowcost,closest,n);
    return g;
}
