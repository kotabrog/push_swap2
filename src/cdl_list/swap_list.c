#include "../../inc/push_swap.h"

int swap_list(t_cdl_list **list)
{
    t_cdl_list *temp_first;
    t_cdl_list *temp_second;

    if ((*list)->v == NULL || ((*list)->next)->v == NULL)
        return (ERROR);
    temp_first = pop_element(list);
    temp_second = pop_element(list);
    push_element(list, temp_first);
    push_element(list, temp_second);
    return (SUCCESS);
}

int swap_two_list(t_cdl_list **list1, t_cdl_list **list2)
{
    if (swap_list(list1) || swap_list(list2))
        return (ERROR);
    return (SUCCESS);
}
