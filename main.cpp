#include <iostream>
#include <fstream>      // for reading graph from file
#include <chrono>

#include "graph.h"
#include "prims.h"
#include "kruskal.h"

using namespace std;
using namespace std::chrono;

graph createGraphFromFile(char st[],int n)
{
    int i,j;
    graph g(n);
    int *MYadjMat=new int[n*n];
    ifstream graphFile(st);
    if(!graphFile)
        {
            cout<<"Cannot open file!!";
            return g;
        }
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
             graphFile>>*(MYadjMat+i*n+j);
         }
     }
     graphFile.close();
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
            g.setEdge(i,j,*(MYadjMat+i*n+j));
         }
     }
    return g;
}

int main()
{
    int n0;
    char filename[30];
    cout <<"Enter number of vertices in the graph: ";
    cin>>n0;

    cout<<"Enter file to read the graph from: ";
    cin>>filename;

    graph g = createGraphFromFile(filename,n0);
    graph gKruskal = createGraphFromFile(filename,n0);

    g.findMaxCost();
    for(int i=0;i<n0;i++)
    {
        for(int j=0;j<n0;j++)
        {
            if(g.getEdge(i,j) == 0 || g.getEdge(i,j)== -1)
            g.setEdge(i,j,g.getMaxCost()+1);
        }
    }

    auto start = high_resolution_clock::now();
    g = prims(g);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout<<"Prim's algorithm MST (total cost: "<<g.mstCost<<"; runtime: "<<duration.count()<<"ms)\n";
    g.displayMST();


    start = high_resolution_clock::now();
    gKruskal = kruskal(gKruskal);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);

    cout<<"Kruskal's algorithm MST (total cost: "<<gKruskal.mstCost<<"; runtime: "<<duration.count()<<"ms)\n";
    gKruskal.displayMST();

    return 0;
}
