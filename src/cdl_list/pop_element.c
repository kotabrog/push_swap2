#include "../../inc/push_swap.h"

t_cdl_list *pop_element(t_cdl_list **list)
{
    t_cdl_list *out;

    if ((*list)->v == NULL)
        return (NULL);
    out = *list;
    ((*list)->next)->prev = (*list)->prev;
    ((*list)->prev)->next = (*list)->next;
    *list = (*list)->next;
    return (out);
}

t_cdl_list *pop_back_element(t_cdl_list *list)
{
    t_cdl_list *out;

    if (list->v == NULL)
        return (NULL);
    out = (list->prev)->prev;
    (((list->prev)->prev)->prev)->next = (list->prev);
    (list->prev)->prev = out->prev;
    return (out);
}
