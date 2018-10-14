#include <iostream>
#include "graph.h"

using namespace std;
void displayGraph(graph g,int n)
{
    cout<<endl;
    for (int i =0 ;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<g.getEdge(i,j)<<" ";
        cout<<"\n";
    }
}

int main()
{
    int n0,srcVertex,destVertex,cost;

    cout <<"Enter number of vertices in the graph: ";
    cin>>n0;
    graph g(n0);

//    graph g(n);
    while(1)
    {
        cout<<"\nEnter valid vertices only [1 to "<<n0<<" ]\n";
        cout<<"Enter source vertex[enter 0 to abort entering]: ";
        cin>>srcVertex;
//        if(srcVertex > n0 || srcVertex<0)
//            cout<<"Enter valid vertex [1 to "<<n0<<" ]: ";
        if(srcVertex == 0)
            break;
        cout<<"Enter destination vertex: ";
        cin>>destVertex;
        if(destVertex == 0)
            break;
        cout<<"Enter the weight of edge between them: ";
        cin>>cost;
        g.setEdge(srcVertex-1,destVertex-1,cost);


    }
    displayGraph(g,n0);
    return 0;
}
