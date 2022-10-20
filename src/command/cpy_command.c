#include "../../inc/push_swap.h"

int cpy_command(t_command *src, t_command **dest)
{
    if (*dest == NULL && make_command(dest))
        return (ERROR);
    if ((*dest)->capacity < src->capacity)
    {
        ft_free((*dest)->list);
    }
}
