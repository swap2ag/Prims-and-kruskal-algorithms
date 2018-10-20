#include <iostream>
#include <fstream>
#include <windows.h>

#include "graph.h"
#include "prims.h"
#include "kruskal.h"
using namespace std;
//using namespace std::chrono;
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
//    clock_t start_t, end_t,total_t;


    cout <<"Enter number of vertices in the graph: ";
    cin>>n0;
    cout<<"Enter file to read the graph from: ";
    cin>>filename;
    graph g = createGraphFromFile(filename,n0);
    graph gKruskal = createGraphFromFile(filename,n0);
//    cout<<"After reading from file: \n";
//    displayGraph(gKruskal);
//    g = createGraphFromFile("new_inputDefault.txt",g,n0);
    g.findMaxCost();
//    cout<<"\n\n\n======== Max cost: "<<g.getMaxCost();

    for(int i=0;i<n0;i++)
    {
        for(int j=0;j<n0;j++)
        {
            if(g.getEdge(i,j) == 0 || g.getEdge(i,j)== -1)
            g.setEdge(i,j,g.getMaxCost()+1);
        }
    }
//    cout<<"\ninfinity cost: "<<g.getInfCost();
// ------------------------------
//    cout<<"g is: \n";
//    displayGraph(g);
//    cout<<"\ngKruskal is: \n";
//    displayGraph(gKruskal);
//// ---------------
    // Record start time
    long long start = PerformanceCounter();

//    auto start = high_resolution_clock::now();
//    start_t = clock();
    g = prims(g);
//    end_t = clock();
    long long finish = PerformanceCounter();
    long long frequency = PerformanceFrequency();
    double timeElapsed = ((finish - start) * 1000.0) / frequency;

//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stop - start);
////    cout << "Time taken by function: "<< duration.count() << " nanoseconds" << endl;
//    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC*1000;
//    cout<<"Prim's algorithm MST (total cost: "<<g.mstCost<<"; runtime: "<<duration.count()<<"ns)\n";
    cout<<"Prim's algorithm MST (total cost: "<<g.mstCost<<"; runtime: "<<timeElapsed<<"ms)\n";
    g.displayMST();

    long long startKruskalCounter = PerformanceCounter();
//    cout<<"performance counter activated\n";
//    start_t = clock();
//    start = high_resolution_clock::now();
    gKruskal = kruskal(gKruskal);
//    stop = high_resolution_clock::now();
//    duration = duration_cast<milliseconds>(stop - start);
//    end_t = clock();
//    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC*1000;
    long long stopKruskalCounter = PerformanceCounter();
    long long Kruskalfrequency = PerformanceFrequency();
    double timeElapsedKruskal = ((stopKruskalCounter-startKruskalCounter)*1000.0) / Kruskalfrequency;
    cout<<"Kruskal's algorithm MST (total cost: "<<gKruskal.mstCost<<"; runtime: "<<timeElapsedKruskal<<"ms)\n";
    gKruskal.displayMST();

    return 0;
}

