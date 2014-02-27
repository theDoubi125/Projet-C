#ifndef CHAINED_LIST_H_INCLUDED
#define CHAINED_LIST_H_INCLUDED

union ListContent
{
    int i; double d;
};

struct ChainedList
{
    ListContent content;
    ChainedList *next;
};

ChainedList addToChainedList(ListContent val, ChainedList *l);

void printChainedList(ChainedList *l);

#endif // CHAINED_LIST_H_INCLUDED
