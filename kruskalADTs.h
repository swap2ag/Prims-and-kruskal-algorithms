/*
 * This file includes the definitions of priority queue ADT and MFSET ADT required for Kruskal's algorithm
 * // I have used partially ordered tree implementation of priority queue as DELETEMIN() AND INSERT() are O(log(n)) in it.
*/

#ifndef KRUSKALADTS_INCLUDE

#define KRUSKALADTS
#include"graph.h"
#include<iostream>                                  // for displaying MFSET
using namespace std;

// priority_queue ADT
// each entry is of type PQ_entry
class PQ_entry
{
    int v1;                                         // first vertex
    int v2;                                         // second vertex
    int cost_priority;                              // cost of edge between the two vertices(also the priority in priority queue)
public:
    //==== Constructors ====
    PQ_entry();                                     // constructor that does nothing
    PQ_entry(int v1, int v2, int cost_priority);    // constructor that takes arguments and sets variables accordingly

    //==== getters ====
    int getPriority();                              // returns priority
    int getV1();                                    // returns first vertex
    int getV2();                                    // returns second vertex
    //==== setters ====
    void setPriority(int x);                        // sets priority
    void setVertices(int x1,int x2);                // sets vertices as x1 and x2 of an entry in queue
};

// below class defines a priority queue

class priorityQueue
{
    PQ_entry *contents;                             // contents is an array of priority queue entries (PQ_entry)
                                                    // I begin indexing from 1 in it although c++ starts from 0, so as to make implementation simpler
    int last;                                       // last is the index of last element in priority queue
    int numNodes;                                   // size of priority queue
public:
    //==== constructor ====
    priorityQueue(graph g);                         // g is passed so that size of priority queue is g.numNodes*(g.numNodes-1) at max.
    //==== MAKENULL function =====
    void makeNull();                                // sets last to 0
    void insertInPQ(PQ_entry x);                    // inserts an entry of type PQ_entry in priority queue
    PQ_entry deleteMin();                           // deletes the edge having minimum cost (highest priority) from the priority queue and returns the deleted entry
};

// MFSET ADT
// SET ADT for MFSET
class sets
{
    int numElements;                                // number of elements in a set
    int firstElementIndex;                          // index of first element of a set
public:
    //==== getters =====
    int getNumElements();                           // returns number of elements in a set
    int getFirstElementIndex();                     // returns index of first element in the set
    //==== setters =====
    void setNumElements(int n);                     // sets number of elements in a set
    void setFirstElementIndex(int elementIndex);    // sets index of first element in the set
};
// defintion of each element of a set
class setElement
{
    int setName;                                    // set to which this element belongs
    int nextElementIndex;                           // index of next element belonging to same set as this one
public:
    //==== getters ====
    int getSETname();                               // returns the set to which this element belongs
    int getNextElementIndex();                      // index of next element belonging to same set as this element
    //==== setters ====
    void setSETname(int x);                         // sets the set to which this element belongs
    void setNextElementIndex(int index);            // sets the index of next element of this element
};

class mfset
{
public:
    sets setHeaders[2000];                           // array of sets where each set contains number of elements in it and index of first element
    setElement elements[2000];                       // array of set elements where each element contains the name of set to which it belongs and and index of next element belonging to the same set
    //==== Constructor ====
    mfset(int numSets, int numElements);            // not required
    //==== functions that can be performed on MFSET ADT ====
    void initial(int setName, int x);               // initialises a set having name as setName with an element x of type setElement
    void mergeSets(int setA, int setB);             // merges elements of setA and setB
    int findSet(int x);                             // returns the set to which element x belongs
};

#endif // KRUSKALADTS_INCLUDE
