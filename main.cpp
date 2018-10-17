#include <iostream>
#include<fstream>
//#include<time.h>
#include <chrono>

#include "graph.h"
#include"prims.h"
using namespace std;
using namespace std::chrono;


int getVertex()
{
    int vertex;
    cin>>vertex;
    return vertex;
}
void displayGraph(graph g)
{
    cout<<endl;
    int n = g.getNumNodes();
    for (int i =0 ;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<g.getEdge(i,j)<<" ";
        cout<<"\n";
    }
}
graph createGraphManually(graph g)
{
    int n0 = g.getNumNodes();
    int srcVertex, destVertex,cost;

 while(1)
    {
        cout<<"Enter source vertex[0 to abort entering]: ";
        srcVertex = getVertex();
        if(srcVertex == 0)
            break;
        else if(srcVertex > n0 || srcVertex<0)
            {
                while(srcVertex>n0 || srcVertex<0)
                {
                    cout<<"Enter valid vertex [1 to "<<n0<<" ]\n";
                    srcVertex = getVertex();
                }
            }
            cout<<"Enter destination vertex[0 to abort entering]:";
        destVertex = getVertex();
        if(destVertex == 0)
            break;
        else if(destVertex > n0 || destVertex<0)
            {
                while(destVertex>n0 || destVertex<0)
                {
                    cout<<"Enter valid vertex [1 to "<<n0<<" ]\n";
                    destVertex = getVertex();
                }
            }
        cout<<"Enter the weight of edge between them[0 or -1 to represent no edge]: ";
        cin>>cost;
        g.setEdge(srcVertex-1,destVertex-1,cost);
        cout<<endl;
    }
    return g;
}
/*
graph createDefaultGraph(graph g)
{
    g.setEdge(0,1,6);
    g.setEdge(0,2,1);
    g.setEdge(0,3,5);

    g.setEdge(1,0,6);
    g.setEdge(1,2,5);
    g.setEdge(1,4,3);

    g.setEdge(2,0,1);
    g.setEdge(2,1,5);
    g.setEdge(2,3,5);
    g.setEdge(2,4,6);
    g.setEdge(2,5,4);

    g.setEdge(3,0,5);
    g.setEdge(3,2,5);
    g.setEdge(3,5,2);

    g.setEdge(4,1,3);
    g.setEdge(4,2,6);
    g.setEdge(4,5,6);
    g.setEdge(5,2,4);
    g.setEdge(5,3,2);
    g.setEdge(5,4,6);

    return g;
}
*/
//---UNDER DEVELOPMENT---- need to enter
graph createGraphFromFile(char st[],graph g,int n)
{
    int i,j;

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
    clock_t start_t, end_t,total_t;


    cout <<"Enter number of vertices in the graph: ";
    cin>>n0;
    graph g(n0);
// ------------------------------
//  g = createDefaultGraph(g);
//  g = createGraph(g);
  g = createGraphFromFile("new_input.txt",g,n0);
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
    displayGraph(g);
    auto start = high_resolution_clock::now();
//    start_t = clock();
    g = prims(g);

//    end_t = clock();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
//    cout << "Time taken by function: "<< duration.count() << " nanoseconds" << endl;
//    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC*1000;
    cout<<"Prim's algorithm MST (total cost: "<<g.mstCost<<"; runtime: "<<duration.count()<<"ns)\n";
    g.displayMST();
    return 0;
}
