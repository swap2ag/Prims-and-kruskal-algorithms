#ifndef KRUSKALADTS_INCLUDE
#define KRUSKALADTS
#include"graph.h"
//#define MAXSIZE 200
// we will use partially ordered tree implementation of priority queue as DELETEMIN() AND INSERT() are O(log(n)) in it.

// priority_queue ADT
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
    priorityQueue(graph g);
    void makeNull();
    void insertInPQ(PQ_entry x);
    PQ_entry* deleteMin();
};

// MFSET ADT
class sets
{
    int numElements;
    int firstElementIndex;
public:
    // getters
    int getNumElements();
    int getFirstElementIndex();
    // setters
    void setNumElements(int n);
    void setFirstElementIndex(int elementIndex);
};
class setElement
{
    int setName;            // to which this element belongs
    int nextElementIndex;   // index of next element belonging to same set as this one
public:
    // getters
    int getSETname();
    int getNextElementIndex();
    // setters
    void setSETname(int x);
    void setNextElementIndex(int index);
};

class mfset
{
public:
    sets* setHeaders;
    setElement* elements;
    mfset(int numSets, int numElements);
    void initial(int setName, int x);
    void mergeSets(int setAIndex, int setBIndex);
    int findSet(int x); // returns the set to which x belongs
};

#endif // KRUSKALADTS_INCLUDE
