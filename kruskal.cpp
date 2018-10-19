#include<iostream>
#include"kruskal.h"
#include"kruskalADTs.h"
#include"graph.h"
using namespace std;
graph kruskal(graph g)
{
//    g.mst = NULL;       // set T of edges in MST
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
//    cout<<"after for loop of initial()..................................\n";
//    m.displayMFSET(g.getNumNodes());

//    cout<<" =========================================================================================================================== \n";
//    cout<<"just before demon for loop -------------\\ \n";
//    m.displayMFSET(g.getNumNodes());
    for(int i=0;i<g.getNumNodes();i++)
    {
        for(int j=i+1;j<g.getNumNodes();j++)
        {
            if((g.getEdge(i,j)!= -1) && (g.getEdge(i,j)!=0))    // for all edges in E
            {
//                m.displayMFSET(g.getNumNodes());
                PQ_entry x(i,j,g.getEdge(i,j));         // make a PQ_entry
                q.insertInPQ(x);                        // insert that entry in PQ
            }
        }
//
    }

//    cout<<"\njust after for loop ----------------------------\n\n\n\n\n";
//    cout<<"\n\n\n\n\n";
//    m.displayMFSET(g.getNumNodes());
    g.mstCost = 0;
//    cout<<"Initial MST cost: "<<g.mstCost<<"\n";
    int mstIndex=0;

//    cout<<"just befor while loop: "<<endl;
    while(currConnectedComponents>1)
    {
//        cout<<"Inside while loop"<<endl;

//        cout<<"line 48 over\n";
        PQ_entry y;
//        cout<<"created y: ";
        y = q.deleteMin();
//        cout<<"deletemin ends\n";
//        cout<<"\ndetails of deleted element: \n";
//        cout<<"("<<y.getV1()<<","<<y.getV2()<<"): "<<y.getPriority();
        int Cu = m.findSet(y.getV1());
//        cout<<"\nCu is: "<<Cu<<endl;
        int Cv = m.findSet(y.getV2());
//        cout<<"Cv is: "<<Cv<<"\n";
//         m.displayMFSET(g.getNumNodes());
        if (Cu != Cv)
        {
//            cout<<"\nboth the vertices don't belong to same set, so, merging 2 sets\n";
//            cout<<"Inside if of while loop: \n";
//            cout<<"displaying before merge-------------------->\n";
//            m.displayMFSET(g.getNumNodes());

            m.mergeSets(Cu,Cv);         // Cu and Cv are set names
//            m.displayMFSET(g.getNumNodes());
//            cout<<"Sucessfully merged and displayed!!!!\n";
            *(g.mst+mstIndex) = y.getV1();
//            cout<<"getV1 over\n";
            g.mst[mstIndex+1] = y.getV2();
            g.mstCost = g.mstCost+y.getPriority();
//            cout<<"added mstcost over\n";

//            cout<<"new edge in MST: ("<<g.mst[mstIndex]<<", "<<g.mst[mstIndex+1]<<")-> "<<g.mstCost<<"\n";
            mstIndex = mstIndex + 2;
            currConnectedComponents--;
//            cout<<"Connected components: "<<currConnectedComponents<<"\n";
        }
//       cout<<"\nKruskal's successfully over....\n";
    }
    return g;
}
