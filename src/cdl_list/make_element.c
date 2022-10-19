#include "../../inc/push_swap.h"

int make_element(t_cdl_list **element, void *v)
{
    if (ft_malloc(element, sizeof(t_cdl_list), 1))
        return (ERROR);
    (*element)->v = v;
    (*element)->next = *element;
    (*element)->prev = *element;
    return (SUCCESS);
}
