#include "chained_list.h"
#include "stdio.h"

ChainedList addToChainedList(ListContent val, ChainedList *l)
{
    ChainedList list = {val, l};
    return list;
}

void printChainedList(ChainedList *l)
{
    printf("%d ", l->content.i);
    if(l->next != NULL)
        printChainedList(l->next);
}
