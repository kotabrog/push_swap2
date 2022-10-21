#include "../../inc/push_swap.h"

int add_command(t_command *command, char one_command)
{
    char *temp;

    if (command->capacity == command->len)
    {
        if (ft_malloc(&temp, sizeof(char), command->capacity + COMMAND_SIZE))
            return (ERROR);
        ft_strcpy(temp, command->list, command->capacity);
        free(command->list);
        command->list = temp;
        command->capacity += COMMAND_SIZE;
    }
    (command->list)[command->len] = one_command;
    command->len += 1;
    return (SUCCESS);
}
