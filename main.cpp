#include <iostream>
#include <fstream>                              // for reading graph from file
#include <chrono>                               // for calculating runtime of a function

#include "graph.h"                              // for graph ADT
#include "prims.h"                              // for Prim's function
#include "kruskal.h"                            // for Kruskal's function

using namespace std;
using namespace std::chrono;                    // for runtime

graph createGraphFromFile(char st[],int n)      // function to create graph from a file
{
    int i,j;                                    // loop variables
    graph g(n);                                 // creates a graph object
    int *MYadjMat=new int[n*n];                 // used to get the cost of edges directly from adjacency matrix in file
    ifstream graphFile(st);                     // file input object
    if(!graphFile)                              // if cannot open file, then
        {
            cout<<"Cannot open file!!";         // prints this error message
            return g;                           // returns graph object
        }
     for(i=0;i<n;i++)                           // loop to read from file and store in a matrix
     {
         for(j=0;j<n;j++)
         {
             graphFile>>*(MYadjMat+i*n+j);
         }
     }
     graphFile.close();                         // closes the input file
     for(i=0;i<n;i++)                           // loop to set edges of graphh with the values stored in adjacency matrix
     {
         for(j=0;j<n;j++)
         {
            g.setEdge(i,j,*(MYadjMat+i*n+j));
         }
     }
    return g;                                   // returns graph object
}

int main()
{
    int n0;                                             // number of vertices in graph
    char filename[30];                                  // name of file
    cout <<"Enter number of vertices in the graph: ";   // takes n0 as input
    cin>>n0;

    cout<<"Enter file to read the graph from: ";        // takes filename as input
    cin>>filename;

    graph g = createGraphFromFile(filename,n0);         // makes a graph g from file with n0 number of vertices and returns in g
    graph gKruskal = createGraphFromFile(filename,n0);  // makes a graph g from file with n0 number of vertices and returns in gKruskal.
                                                        // another graph is made as we will change the cost of edges for prim's whereas Kruskal requires original graph

    g.findMaxCost();                                    // finds maximum cost edge in g
    for(int i=0;i<n0;i++)                               // replaces the cost by (maxCost+1) if cost of an edge is 0 or -1
    {
        for(int j=0;j<n0;j++)
        {
            if(g.getEdge(i,j) == 0 || g.getEdge(i,j)== -1)
            g.setEdge(i,j,g.getMaxCost()+1);
        }
    }
    // code for finding mst by prim's and calculating runtime of prim's
    auto primsTimerStart = high_resolution_clock::now();        // uses high resolution clock to get accurate time and starts it
    g = prims(g);                                               // calculates minimum spanning tree from prims and returns an instance of graph ADT
    auto primsTimerStop= high_resolution_clock::now();          // stops the clock
    auto primsDuration = duration_cast<milliseconds>(primsTimerStop-primsTimerStart);  // calculates duration between two time points and casts it into milliseconds

    cout<<"Prim's algorithm MST (total cost: "<<g.mstCost<<"; runtime: "<<primsDuration.count()<<"ms)\n";    // displays MST pbtained from prim's algorithm
    g.displayMST();

    // Code for finding MST by Kruskal's algorithm and displaying it along with runtime
    auto kruskalTimerStart = high_resolution_clock::now();      // stores the current timepoint
    gKruskal = kruskal(gKruskal);                               // finds MST by Kruskal which returns it as a graph object
    auto kruskalTimerStop = high_resolution_clock::now();       // again stores the current timepoint
    auto kruskalDuration = duration_cast<milliseconds>(kruskalTimerStop-kruskalTimerStart);       // calculates difference between two to find duration
    // dispkay MST returned by Kruskal's a;gorithm
    cout<<"Kruskal's algorithm MST (total cost: "<<gKruskal.mstCost<<"; runtime: "<<kruskalDuration.count()<<"ms)\n";
    gKruskal.displayMST();

    return 0;
}
