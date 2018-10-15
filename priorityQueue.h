#ifndef PRIORITYQUEUE_INCLUDE
#define PRIORITYQUEUE
#define maxsize 200\
// we will use partially ordered tree implementation of priority queue as DELETEMIN() AND INSERT() are O(log(n)) in it.
class priority_queue
{
    processtype *contents = new processtype[maxsize];
    int last;
public:
    void makeNull()
    {
        last = 0;
    }
};





class
#endif // PRIORITYQUEUE_INCLUDE
