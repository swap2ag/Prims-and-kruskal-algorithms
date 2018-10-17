#include"PQ_entry.h"

int PQ_entry::getPriority()
{
    return priority;
}
int PQ_entry::getID()
{
    return id;
}
void PQ_entry::setPriority(int x)
{
    priority = x;
}
void PQ_entry::setID(int x)
{
    id = x;
}
