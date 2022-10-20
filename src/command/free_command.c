#include "../../inc/push_swap.h"

void free_command(t_command **command)
{
    if (*command == NULL)
        return ;
    ft_free(&((*command)->list));
    ft_free(command);
}
