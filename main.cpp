#include <iostream>
#include "graph.h"

using namespace std;
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
void createGraph(graph g)
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
        cout<<"Enter the weight of edge between them: ";
        cin>>cost;
        g.setEdge(srcVertex-1,destVertex-1,cost);
    }
}
int main()
{
    int n0;

    cout <<"Enter number of vertices in the graph: ";
    cin>>n0;
    graph g(n0);
    createGraph(g);
//    createDefaultGraph(g);
    displayGraph(g);
    return 0;
}
