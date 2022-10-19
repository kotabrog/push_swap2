#include "../../inc/push_swap.h"

int put_list(t_cdl_list *list)
{
    int i;

    i = 0;
    while (list->v)
    {
        printf("%d: %d\n", i, *(list->v));
        list = list->next;
        ++i;
    }
    return (i);
}
