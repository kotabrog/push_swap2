#include "../../inc/push_swap.h"

int len_list(t_cdl_list *list)
{
    int i;

    i = 0;
    while (list->v)
    {
        list = list->next;
        ++i;
    }
    return (i);
}
