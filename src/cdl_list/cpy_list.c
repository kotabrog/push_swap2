#include "../../inc/push_swap.h"

t_cdl_list *cpy_list(t_cdl_list *list)
{
    t_cdl_list *out;

    if (make_new_element(&out, NULL))
        return (NULL);
    if (list->v == NULL)
        return (out);
    list = (list->prev)->prev;
    while (list->v)
    {
        if (push_int(&out, *(list->v)))
        {
            free_list(&out);
            return (NULL);
        }
        list = list->prev;
    }
    return (out);
}
