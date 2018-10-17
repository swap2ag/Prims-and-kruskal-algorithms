#ifndef PRIORITYQUEUE_INCLUDE
#define PRIORITYQUEUE
#include"PQ_entry.h"
#define MAXSIZE 200
// we will use partially ordered tree implementation of priority queue as DELETEMIN() AND INSERT() are O(log(n)) in it.
class priority_queue
{
    PQ_entry *contents;
    int last;
public:
    priority_queue()
    {
        contents = new PQ_entry[MAXSIZE];
    }
  void makeNull();
  void insertInPQ(PQ_entry x);
};

#endif // PRIORITYQUEUE_INCLUDE
