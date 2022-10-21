#include "../../inc/push_swap.h"

int cpy_command(t_command *src, t_command **dest)
{
    if (*dest == NULL && make_command(dest))
        return (ERROR);
    if ((*dest)->capacity < src->capacity)
    {
        ft_free((*dest)->list);
        if (ft_malloc((*dest)->list, sizeof(char), src->capacity))
            return (ERROR);
        (*dest)->capacity = src->capacity;
    }
    ft_strcpy((*dest)->list, src->list, src->len);
    (*dest)->len = src->len;
    return (SUCCESS);
}
