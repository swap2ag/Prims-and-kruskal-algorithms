#include"graph.h"
#include"prims.h"

graph prims(graph g)
{
    int i,j,k,minimum;
    int index=0;          // for mst
    int n = g.getNumNodes();
    int* lowcost = new int [n];
    int *closest = new int[n];
    g.mst = new int[2*(n-1)];

    *closest = 0;   // since it is of no use
    *lowcost = 0;   // since it is of no use
    for(i=1;i<n;i++)
    {
        *(lowcost+i) = g.getEdge(i,0);
        *(closest+i) = 0;
    }
    for (i=1;i<n;i++)
    {
        minimum = *(lowcost+1);
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

        index = index+2;
        g.mstCost = g.mstCost + g.getEdge(k,closest[k]);

        *(lowcost+k) = g.getInfCost();
        for(j=1;j<n;j++)
        {
            if(g.getEdge(k,j)<*(lowcost+j) && (lowcost[j]<g.getInfCost()))
               {
                   *(lowcost+j) = g.getEdge(k,j);
                   *(closest+j) = k;
               }
        }
    }
    return g;
}
