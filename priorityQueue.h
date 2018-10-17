#ifndef PRIORITYQUEUE_INCLUDE
#define PRIORITYQUEUE
#include"graph.h"
//#define MAXSIZE 200
// we will use partially ordered tree implementation of priority queue as DELETEMIN() AND INSERT() are O(log(n)) in it.
class PQ_entry
{
    int v1;
    int v2;
    int cost_priority;
public:
    // getters
    int getPriority();
    int getV1();
    int getV2();
    // setters
    void setPriority(int x);
    void setVertices(int x1,int x2);
};

class priorityQueue
{
    PQ_entry *contents;
    int last;
    int numNodes;
public:
    priority_queue(graph g);
    void makeNull();
    void insertInPQ(PQ_entry x);
    PQ_entry* deleteMin();
};

class mfsetADT
{

};
#endif // PRIORITYQUEUE_INCLUDE
