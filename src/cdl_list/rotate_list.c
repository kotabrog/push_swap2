#include "../../inc/push_swap.h"

int rotate_list(t_cdl_list **list)
{
    t_cdl_list *temp;

    if ((*list)->v == NULL || ((*list)->next)->v == NULL)
        return (ERROR);
    temp = pop_element(list);
    push_back_element(*list, temp);
    return (SUCCESS);
}

int rotate_two_list(t_cdl_list **list1, t_cdl_list **list2)
{
    if (rotate_list(list1) || rotate_list(list2))
        return (ERROR);
    return (SUCCESS);
}

int rotate_reverse_list(t_cdl_list **list)
{
    t_cdl_list *temp;

    if ((*list)->v == NULL || ((*list)->next)->v == NULL)
        return (ERROR);
    temp = pop_back_element(*list);
    push_element(list, temp);
    return (SUCCESS);
}

int rotate_reverse_two_list(t_cdl_list **list1, t_cdl_list **list2)
{
    if (rotate_reverse_list(list1) || rotate_reverse_list(list2))
        return (ERROR);
    return (SUCCESS);
}
