#include "../../inc/push_swap.h"

void free_list(t_cdl_list **list)
{
    t_cdl_list *temp;

    if (*list == NULL)
        return ;
    while ((*list)->v)
    {
        free((*list)->v);
        temp = *list;
        *list = (*list)->next;
        free(temp);
    }
    ft_free(list);
}
