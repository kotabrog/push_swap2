#include "../../inc/push_swap.h"

int is_sorted_list(t_cdl_list *list)
{
    int temp;

    if (list->v == NULL)
        return (1);
    temp = *(list->v);
    list = list->next;
    while (list->v)
    {
        if (temp > *(list->v))
            return (0);
        temp = *(list->v);
        list = list->next;
    }
    return (1);
}
