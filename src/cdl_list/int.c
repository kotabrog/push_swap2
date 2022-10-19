#include "../../inc/push_swap.h"

int int_to_element(t_cdl_list **list, int v)
{
    int *p;

    if (ft_malloc(&p, sizeof(int), 1))
        return (ERROR);
    *p = v;
    if (make_element(list, p))
    {
        free(p);
        return (ERROR);
    }
    return (SUCCESS);
}

int push_int(t_cdl_list **list, int v)
{
    t_cdl_list *element;

    if (int_to_element(&element, v))
        return (ERROR);
    push_element(list, element);
    return (SUCCESS);
}
