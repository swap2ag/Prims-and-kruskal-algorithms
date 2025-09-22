#include <iostream>
#include <fstream>                              // for reading graph from file

#include "graph.h"                              // for graph ADT
#include "prims.h"                              // for Prim's function
#include "kruskal.h"                            // for Kruskal's function

#if defined (_WIN32)
#include <windows.h>
#elif defined (__linux__)
#include <time.h>
#else
#include <chrono>                               // for calculating runtime of a function
using namespace std::chrono;
#endif

#if defined (_WIN32)
long long PerformanceCounter()
{
    LARGE_INTEGER timeCtr;
    ::QueryPerformanceCounter(&timeCtr);
    return timeCtr.QuadPart;
}
// -----------------------------------------
long long PerformanceFrequency()
{
    LARGE_INTEGER timeCtr;
    ::QueryPerformanceFrequency(&timeCtr);
    return timeCtr.QuadPart;
}
#endif

using namespace std;

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
    cout << "Enter number of vertices in the graph: ";   // takes n0 as input
    cin >> n0;

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
#if defined (_WIN32)
    auto primsTimerStart = PerformanceCounter();
#elif defined (__linux__)
    clock_t primsTimerStart = clock();
#else
    auto primsTimerStart = high_resolution_clock::now();                                // uses high resolution clock to get accurate time and starts it
#endif

    g = prims(g);                                                                       // calculates minimum spanning tree from prims and returns an instance of graph ADT

#if defined (_WIN32)
    auto primsTimerStop = PerformanceCounter();
#elif defined (__linux__)
    clock_t primsTimerStop = clock();
#else
    auto primsTimerStop = high_resolution_clock::now();                                  // stops the clock
#endif

#if defined (_WIN32)
    long long frequency = PerformanceFrequency();
    double primsDuration = ((primsTimerStop - primsTimerStart) * 1000.0) / frequency;
#elif defined (__linux__)
    double primsDuration = (double)(primsTimerStop - primsTimerStart) / CLOCKS_PER_SEC*1000;
#else
    auto primsDuration = duration_cast<milliseconds>(primsTimerStop-primsTimerStart);   // calculates duration between two time points and casts it into milliseconds
#endif

    // display MST returned by Prim's algorithm
#if defined (_WIN32) || defined (__linux__)
    cout << "Prim's algorithm MST (total cost: " << g.mstCost << "; runtime: " << primsDuration << "ms)\n";
#else
    cout << "Prim's algorithm MST (total cost: " << g.mstCost << "; runtime: " << primsDuration.count() << "ms)\n";
#endif

    g.displayMST();
#if defined (__linux__)
    // Code for finding MST by Kruskal's algorithm and displaying it along with runtime
    auto kruskalTimerStart = clock();   // stores the current timepoint
    gKruskal = kruskal(gKruskal);       // finds MST by Kruskal which returns it as a graph object
    auto kruskalTimerStop = clock();    // again stores the current timepoint
    double kruskalDuration = (double)(kruskalTimerStop - kruskalTimerStart) / CLOCKS_PER_SEC*1000;

    cout << "Kruskal's algorithm MST (total cost: " << gKruskal.mstCost << "; runtime: " << kruskalDuration << "ms)\n";
    // display MST returned by Kruskal's algorithm
    gKruskal.displayMST();
#endif

    return 0;
}
