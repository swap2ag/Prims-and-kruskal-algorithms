#include"kruskalADTs.h"
#include"graph.h"
#include"PQ_entry.h"
#include<iostream>
using namespace std;
// function definitions for class PQ_entry
// ------------------------------------------
PQ_entry::PQ_entry()
{
    return;
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

    contents = new PQ_entry[g.getNumNodes()+1];
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
//    cout<<"last is: "<<last<<endl;
//    cout<<"Contents of PQ after entering insertinPQ()-------->>>>\n";
//    for(int i=1;i<=last;i++)
//    {
//        cout<<"contents of "<<i<<"th element: "<<"v1: "<<contents[i].getV1()<<" v2: "<<contents[i].getV2()<<" cost: "<<contents[i].getPriority()<<"\n";
//    }
    if (last>=numNodes)
    {
        std::cout<<"Priority queue is full!!!";
        return;
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
//    cout<<"\ndeleteMIn begins\n";
//    cout<<"last is: "<<last<<endl;
    if(last == 0)
        std::cout<<"Priority queue is empty";
    else
    {
//        cout<<"\nEntered else\n";
        minimumEntry.setPriority(contents[1].getPriority());
        minimumEntry.setVertices(contents[1].getV1(),contents[1].getV2());
//            minimumEntry = contents;    // points to the base of contents so that every time after pushing down all, minimum element is returned.
//        cout<<"\nminentry pointing to first entry in contents\n";
//      cout<<"contents of minimum entry: "<<"v1: "<<minimumEntry.getV1()<<" v2: "<<minimumEntry.getV2()<<" cost: "<<minimumEntry.getPriority()<<"\n";
//  cout<<"contents of last: "<<"v1: "<<contents[last].getV1()<<" v2: "<<contents[last].getV2()<<" cost: "<<contents[last].getPriority()<<"\n";
//        cout<<"initially contents of pQ: \n";
//        for(i=1;i<=last;i++)
//        {
//            cout<<"contents of "<<i<<"th element: "<<"v1: "<<contents[i].getV1()<<" v2: "<<contents[i].getV2()<<" cost: "<<contents[i].getPriority()<<"\n";
//        }
        contents[1].setPriority(contents[last].getPriority());
        contents[1].setVertices(contents[last].getV1(),contents[last].getV2());


        // place last node to the first node
//        cout<<"contents of first ele: "<<contents[1]<<endl;
        last = last-1;
//         cout<<"later on: ";
//        for(i=1;i<=last;i++)
//        {
//            cout<<"contents of "<<i<<"th element: "<<"v1: "<<contents[i].getV1()<<" v2: "<<contents[i].getV2()<<" cost: "<<contents[i].getPriority()<<"\n";
//        }
        i = 1;  // i is the current position of the old last element
        while (i<=(last/2))
        {
            if( (contents[2*i].getPriority() < contents[2*i+1].getPriority()) || (2*i == last) )
            {
                j = 2*i;
//                cout<<"\nj: "<<j<<" replacing with left element\n";
            }
            else
            {
                j = 2*i+1;
//                cout<<"\nj: "<<j<<"replacing with right element\n";
            }
            if (contents[i].getPriority()>contents[j].getPriority())    // if the parent node is greater than smaller of two child nodes or if it is the last node
            {
//                cout<<"\nmoving entry to be deleted upwards\n";
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
//                    cout<<"\nminimum entry's v1: "<<minimumEntry.getV1()<<"\n minimum entry's v2: "<<minimumEntry.getV2()<<"\n";
                    return minimumEntry;
                }
        }

    }
//    cout<<"\nminimum entry's v1: "<<minimumEntry.getV1()<<"\n minimum entry's v2: "<<minimumEntry.getV2()<<"\n";
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
//    setHeaders = new sets[numSets];
//    elements = new setElement[numElements];
//    for (int i=0;i<numElements;i++)
//    {
//        elements[i].setSETname(i);
//        elements[i].setNextElementIndex(-1);
//        setHeaders[i].setFirstElementIndex(i);
//        setHeaders[i].setNumElements(1);
//    }
//    cout<<"displaying MFSET after initialising object of MFSET";
//    displayMFSET(6);
}
void mfset::initial(int setName, int x)
{
    elements[x].setSETname(setName);
    elements[x].setNextElementIndex(-1);    // since in array 0 is a valid, so using -1
    setHeaders[setName].setNumElements(1);
    setHeaders[setName].setFirstElementIndex(x);
//    cout<<"\nAfter initialising mfset is: ";
//    displayMFSET(6);
//    cout<<"\n.....exiting initial()...\n";
}

void mfset::mergeSets(int setA, int setB)
{
//    cout<<"\nMerge starts \n";
//    cout<<"Entered merge: \n with setA: "<<setA<<" and SetB: "<<setB<<"\nand index of first element of B: ";

//    cout<<setHeaders[setB].getFirstElementIndex()<<endl<<"-------------------"<<endl;
    int i;
    if (setHeaders[setA].getNumElements() > setHeaders[setB].getNumElements())
    {
//        cout<<"\nA is larger set, so entered if of merge() amd will merge B into A.\n";
        // A is lager set, so merge B into A
        i = setHeaders[setB].getFirstElementIndex();
//        cout<<"\nfirst element index of B: "<<i<<endl;
        while(elements[i].getNextElementIndex() != -1)
        {
            elements[i].setSETname(setA);
//            displayMFSET(6);
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
//        cout<<"\nfirst element index of A: "<<i<<endl;
        while(elements[i].getNextElementIndex() != -1)
        {
            elements[i].setSETname(setB);
//            displayMFSET(6);
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
//    cout<<endl;
//    cout<<"Displaying MFSET in the merge function\n";
//    displayMFSET(6);
//    cout<<"\n MERGE ENDS!!!";
}

int mfset::findSet(int x)
{
    return elements[x].getSETname();
}
