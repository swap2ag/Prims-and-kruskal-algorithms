#ifndef PQ_ENTRY_INCLUDE
#define PQ_ENTRY_INCLUDE
class PQ_entry
{
    int id;
    int priority;
public:
    // getters
    int getPriority();
    int getID();
    // setters
    void setPriority(int x);
    void setID(int x);
};

// initial() places process with id p on the queue
/*
void initial(int P)
{
    processtype process;

    process.id = P;
    process.priority = -currenttime();
    INSERT(process,WAITING_QUEUE);
}

// select allocates a time slice to process with highest priority
void select()
{
    int begintime, endtime;
    processtype process;
    process = DELETEMIN(WAITING_QUEUE);
    // RETURNS a pointer to the deleted element
    begintime = currenttime();
    execute(process.id);
    endtime = currenttime();
    process.priority = process.priority+100*(endtime-begintime);    // adjust priority to incorporate amount of time used.
    INSERT(process,WAITING_QUEUE);  //put selected process back on queue with new priority
}
*/

#endif // PQ_ENTRY_INCLUDE
