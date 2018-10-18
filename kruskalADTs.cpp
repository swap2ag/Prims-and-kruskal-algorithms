#include"kruskalADTs.h"
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

priorityQueue::priorityQueue(graph g)
{
    numNodes = g.getNumNodes();
    contents = new PQ_entry[numNodes];
    // need to add entries in this from the graph.
    return;
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
    PQ_entry *minimumEntry = NULL;
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


// --------------- MERGEFIND SET ADT definition -----------------------
int sets::getNumElements()
{
    return numElements;
}
int sets::getFirstElementIndex()
{
    return firstElementIndex;
}
void sets::setNumElements(int n)
{
    numElements = n;
}
void sets::setFirstElementIndex(int elementIndex)
{
    firstElementIndex = elementIndex;
}
// setElement class member functions definitions
// getters
int setElement::getSETname()
{
    return setName;
}
int setElement::getNextElementIndex()
{
    return nextElementIndex;
}
// setters
void setElement::setSETname(int x)
{
    setName = x;
}
void setElement::setNextElementIndex(int index)
{
    nextElementIndex = index;
}

// --------- MFSET member function definitions -------
mfset::mfset(int numSets, int numElements)
{
    // created
    setHeaders = new sets[numSets];
    elements = new setElement[numElements];
}
void mfset::initial(int setName, int x)
{
    elements[x].setSETname(setName);
    elements[x].setNextElementIndex(-1);    // since in array 0 is a valid, so using -1
    setHeaders[setName].setNumElements(1);
    setHeaders[setName].setFirstElementIndex(x);
}

void mfset::mergeSets(int setAIndex, int setBIndex)
{
    int i = 0;
    if (setHeaders[setAIndex].getNumElements() > setHeaders[setBIndex].getNumElements())
    {
        // A is lager set, so merge B into A
        i = setHeaders[setBIndex].getFirstElementIndex();
        while(elements[i].getNextElementIndex() != -1)
        {
            elements[i].setSETname(setAIndex);
            i = elements[i].getNextElementIndex();
        }
        // append A tp end of B and call the result A
        elements[i].setSETname(setAIndex);
        elements[i].setNextElementIndex(setHeaders[setAIndex].getFirstElementIndex());
        setHeaders[setAIndex].setFirstElementIndex(setHeaders[setBIndex].getFirstElementIndex());
        setHeaders[setAIndex].setNumElements(setHeaders[setAIndex].getNumElements()+setHeaders[setBIndex].getNumElements());
        // nullifying setB
        setHeaders[setBIndex].setNumElements(0);
        setHeaders[setBIndex].setFirstElementIndex(-1);
    }
    else
    {
        // B is lager set, so merge A into B
        i = setHeaders[setAIndex].getFirstElementIndex();
        while(elements[i].getNextElementIndex() != -1)
        {
            elements[i].setSETname(setBIndex);
            i = elements[i].getNextElementIndex();
        }
        // append A tp end of B and call the result B
        elements[i].setSETname(setBIndex);
        elements[i].setNextElementIndex(setHeaders[setBIndex].getFirstElementIndex());

        setHeaders[setBIndex].setFirstElementIndex(setHeaders[setAIndex].getFirstElementIndex());   // set firstelement index of B as that of B since we are appending at the front
        setHeaders[setBIndex].setNumElements(setHeaders[setBIndex].getNumElements()+setHeaders[setAIndex].getNumElements());
        // nullifying setB
        setHeaders[setAIndex].setNumElements(0);
        setHeaders[setAIndex].setFirstElementIndex(-1);
    }
}

int mfset::findSet(int x)
{
    return elements[x].getSETname();
}
