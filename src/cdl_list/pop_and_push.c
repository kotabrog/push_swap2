#include "../../inc/push_swap.h"

int pop_and_push_list(t_cdl_list **giver, t_cdl_list **receiver)
{
    t_cdl_list *temp;

    temp = pop_element(giver);
    if (temp == NULL)
        return (ERROR);
    push_element(receiver, temp);
    return (SUCCESS);
}
