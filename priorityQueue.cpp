#include"priorityQueue.h"
#include"graph.h"
#include"PQ_entry.h"
#include<iostream>

// function definitions for class PQ_entry
// ------------------------------------------
int PQ_entry::getPriority()
{
    return cost_priority;
}
int PQ_entry::getV1()
{
    return v1;
}
int PQ_entry::getV2()
{
    return v2;
}
void PQ_entry::setPriority(int x)
{
    cost_priority = x;
}
void PQ_entry::setVertices(int x1,int x2)
{
    v1 = x1;
    v2 = x2;
}

// --------------------------------------------

priorityQueue::priority_queue(graph g)
{
    numNodes = g.getNumNodes();
    contents = new PQ_entry[numNodes];
    // need to add entries in this from the graph.
}
void priorityQueue::makeNull()
{
    last = 0;
}
void priorityQueue::insertInPQ(PQ_entry x)
{
    int i;
    PQ_entry temp;
    if (last>=numNodes)
    {
        std::cout<<"Priority queue is full!!!";
        return;
    }
    else
    {
        last = last+1;
        *(contents+last) = x; // add entry at the last
        i = last;
        while((i>0) && ((contents[i].getPriority()) < (contents[i/2].getPriority())) )     // till added child is greater than parent exchange
        {
            temp = *(contents+i);
            *(contents+i) = *(contents+(i/2));
            *(contents+(i/2)) = temp;
        }
    }
}
PQ_entry* priorityQueue::deleteMin()
{
    int i,j;
    PQ_entry tempEntry;
    PQ_entry *minimumEntry;
    if(last == 0)
        std::cout<<"Priority queue is empty";
    else
    {
        minimumEntry = new PQ_entry;
        minimumEntry = contents;    // points to the base of contents so that every time after pushing down all, minimum element is returned.
        contents[0] = contents[last];// place last node to the first node
        last = last-1;
        i = 0;  // i is the current position of the old last element
        while (i<=(last/2))
        {
            if( (contents[2*i].getPriority() < contents[2*i+1].getPriority()) || (2*i == last) )
            {
                j = 2*i;
            }
            else
                j = 2*i+1;
            if (contents[i].getPriority()>contents[j].getPriority())    // if the parent node is greater than smaller of two child nodes or if it is the last node
            {
                tempEntry = contents[i];
                contents[i] = contents[j];
                contents[j] = tempEntry;
                i = j;
            }
            else
                return minimumEntry;
        }

    }
    return minimumEntry;
}
