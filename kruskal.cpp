#include"graph.h"
#include"kruskalADTs.h"
#include"kruskal.h"

graph kruskal(graph g)
{
	g.mst = new int[2*(g.getNumNodes()-1)];         // set T of edges in MST
    int currConnectedComponents,next=0;
    priorityQueue q(g);
    q.makeNull();
    currConnectedComponents = g.getNumNodes();
    mfset m(currConnectedComponents,currConnectedComponents);

    for(int i=0;i<g.getNumNodes();i++)
    {
        m.initial(next,i);
        next++;
    }

  for(int i=0;i<g.getNumNodes();i++)
    {
        for(int j=i+1;j<g.getNumNodes();j++)
        {
            if((g.getEdge(i,j)!= -1) && (g.getEdge(i,j)!=0))    // for all edges in E
            {
                PQ_entry x(i,j,g.getEdge(i,j));         // make a PQ_entry
                q.insertInPQ(x);                        // insert that entry in PQ
            }
        }
    }

    g.mstCost = 0;
    int mstIndex=0;

    while(currConnectedComponents>1)
    {
        PQ_entry y;
        y = q.deleteMin();

        int Cu = m.findSet(y.getV1());
        int Cv = m.findSet(y.getV2());
        if (Cu != Cv)
        {
            m.mergeSets(Cu,Cv);         // Cu and Cv are set names
            *(g.mst+mstIndex) = y.getV1();
            g.mst[mstIndex+1] = y.getV2();
            g.mstCost = g.mstCost+y.getPriority();
            mstIndex = mstIndex + 2;
            currConnectedComponents--;
        }
    }
    return g;
}
