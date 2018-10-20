#include<iostream>

#include"kruskalADTs.h"
#include"graph.h"
#include"PQ_entry.h"

// function definitions for class PQ_entry
// ------------------------------------------
PQ_entry::PQ_entry()
{
}
PQ_entry::PQ_entry(int ver1, int ver2, int cost)
{
    v1 = ver1;
    v2 = ver2;
    cost_priority = cost;
}
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
	// this numnodes is the size of PQ
    numNodes = g.getNumNodes();
    numNodes = numNodes*(numNodes-1);
	contents = new PQ_entry[numNodes];
}
void priorityQueue::makeNull()
{
    last = 0;
}
void priorityQueue::insertInPQ(PQ_entry x)
{
    int i;
    PQ_entry temp;
    if (last>numNodes)
    {
        std::cout<<"Priority queue is full!!!";
    }
    else
    {
        last = last+1;
        contents[last].setPriority(x.getPriority()); // add entry at the last
        contents[last].setVertices(x.getV1(),x.getV2());
        i = last;
        while((i>1) && ((contents[i].getPriority()) < (contents[i/2].getPriority())) )     // till added child is greater than parent exchange
        {
            temp.setPriority(contents[i].getPriority());
            temp.setVertices(contents[i].getV1(),contents[i].getV2());

            contents[i].setPriority(contents[i/2].getPriority());
            contents[i].setVertices(contents[i/2].getV1(),contents[i/2].getV2());

            contents[i/2].setPriority(temp.getPriority());
            contents[i/2].setVertices(temp.getV1(),temp.getV2());
            i = i/2;
        }
    }
}
PQ_entry priorityQueue::deleteMin()
{
    int i,j;
    PQ_entry tempEntry;
    PQ_entry minimumEntry;
    if(last == 0)
        std::cout<<"Priority queue is empty\n";
    else
    {
        minimumEntry.setPriority(contents[1].getPriority());
        minimumEntry.setVertices(contents[1].getV1(),contents[1].getV2());

        contents[1].setPriority(contents[last].getPriority());
        contents[1].setVertices(contents[last].getV1(),contents[last].getV2());


        // place last node to the first node
        last = last-1;
        i = 1;  // i is the current position of the old last element
        while (i<=(last/2))
        {
            if( (contents[2*i].getPriority() < contents[2*i+1].getPriority()) || (2*i == last) )
            {
                j = 2*i;
            }
            else
            {
                j = 2*i+1;
            }
            if (contents[i].getPriority()>contents[j].getPriority())    // if the parent node is greater than smaller of two child nodes or if it is the last node
            {
                tempEntry.setPriority(contents[i].getPriority());
                tempEntry.setVertices(contents[i].getV1(),contents[i].getV2());

                contents[i].setPriority(contents[j].getPriority());
                contents[i].setVertices(contents[j].getV1(),contents[j].getV2());

                contents[j].setPriority(tempEntry.getPriority());
                contents[j].setVertices(tempEntry.getV1(),tempEntry.getV2());
                i = j;
            }
            else
                {
                    return minimumEntry;
                }
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
mfset::mfset(int numSets, int numElements){}
void mfset::initial(int setName, int x)
{
    elements[x].setSETname(setName);
    elements[x].setNextElementIndex(-1);    // since in array 0 is a valid, so using -1
    setHeaders[setName].setNumElements(1);
    setHeaders[setName].setFirstElementIndex(x);
}

void mfset::mergeSets(int setA, int setB)
{
    int i;
    if (setHeaders[setA].getNumElements() > setHeaders[setB].getNumElements())
    {

        // A is lager set, so merge B into A
        i = setHeaders[setB].getFirstElementIndex();
        while(elements[i].getNextElementIndex() != -1)
        {
            elements[i].setSETname(setA);
            i = elements[i].getNextElementIndex();
        }
        // append A tp end of B and call the result A
        elements[i].setSETname(setA);
        elements[i].setNextElementIndex(setHeaders[setA].getFirstElementIndex());


        setHeaders[setA].setFirstElementIndex(setHeaders[setB].getFirstElementIndex());
        setHeaders[setA].setNumElements(setHeaders[setA].getNumElements()+setHeaders[setB].getNumElements());

        // nullifying setB
        setHeaders[setB].setNumElements(0);
        setHeaders[setB].setFirstElementIndex(-1);
    }
    else
    {
        // B is lager set, so merge A into B
        i = setHeaders[setA].getFirstElementIndex();
        while(elements[i].getNextElementIndex() != -1)
        {
            elements[i].setSETname(setB);
            i = elements[i].getNextElementIndex();
        }
        // append A tp end of B and call the result B
        elements[i].setSETname(setB);
        elements[i].setNextElementIndex(setHeaders[setB].getFirstElementIndex());

        setHeaders[setB].setFirstElementIndex(setHeaders[setA].getFirstElementIndex());   // set firstelement index of B as that of B since we are appending at the front
        setHeaders[setB].setNumElements(setHeaders[setB].getNumElements()+setHeaders[setA].getNumElements());
        // nullifying setB
        setHeaders[setA].setNumElements(0);
        setHeaders[setA].setFirstElementIndex(-1);
    }
}

int mfset::findSet(int x)
{
    return elements[x].getSETname();
}
