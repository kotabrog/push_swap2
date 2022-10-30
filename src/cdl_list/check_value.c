#include "../../inc/push_swap.h"

int is_any_less_value_list(t_cdl_list *list, int num, int split_point)
{
    while (num-- > 0)
    {
        if (*(list->v) < split_point)
            return (1);
        list = list->next;
    }
    return (0);
}

int is_all_less_value_list(t_cdl_list *list, int num, int split_point)
{
    while (num-- > 0)
    {
        if (*(list->v) >= split_point)
            return (0);
        list = list->next;
    }
    return (1);
}
