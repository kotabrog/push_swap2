#include "../../inc/push_swap.h"

int make_command(t_command **command)
{
    if (ft_malloc(command, sizeof(t_command), 1))
        return (ERROR);
    if (ft_malloc(&((*command)->list), sizeof(char), COMMAND_SIZE))
    {
        ft_free(command);
        return (ERROR);
    }
    (*command)->capacity = COMMAND_SIZE;
    (*command)->len = 0;
    return (SUCCESS);
}
