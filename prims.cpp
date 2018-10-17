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
    g.mst = new int[2*(n-1)];

    *closest = 0;   // since it is of no use
    *lowcost = 0;   // since it is of no use
    for(i=1;i<n;i++)
    {
        *(lowcost+i) = g.getEdge(i,0);
        *(closest+i) = 0;
    }
//    dispArrays(lowcost,closest,n);
    for (i=1;i<n;i++)
    {
        minimum = *(lowcost+1);
//        cout<<"\nValue of minimum initially: "<<minimum;
        k = 1;
        for(j=2;j<n;j++)
        {
            if(*(lowcost+j) <minimum)
            {
                minimum = *(lowcost+j);
                k = j;
//                cout<<"\nNew minimum at "<<k<<": "<<minimum<<"\n";
            }
//            else
//                cout<<"Same old minimum at "<<k<<": "<<minimum<<"\n";
        }
//        cout<<"Minimum after for loop: "<<minimum<<"\n";
        *(g.mst+index) = k;
        *(g.mst+index+1) = *(closest+k);
        index = index+2;
//        cout<<k<<" "<<*(closest+k)<<endl;

        g.mstCost = g.mstCost + g.getEdge(k,closest[k]);
        *(lowcost+k) = g.getInfCost();
//        dispArrays(lowcost,closest,n);
        for(j=1;j<n;j++)
        {
            if(g.getEdge(k,j)<*(lowcost+j) && (lowcost[j]<g.getInfCost()))
               {
                   *(lowcost+j) = g.getEdge(k,j);
                   *(closest+j) = k;
//                   cout<<"\ninside if: ";
//                   dispArrays(lowcost,closest,n);
               }
        }
    }
//    dispArrays(lowcost,closest,n);
    return g;
}
