#include "../../inc/push_swap.h"

static char **make_put_command_array(void)
{
    char **command_array;

    if (ft_malloc(&command_array, sizeof(char *), 13))
        return (NULL);
    command_array[COMMAND_SA] = "sa";
    command_array[COMMAND_SB] = "sb";
    command_array[COMMAND_SS] = "ss";
    command_array[COMMAND_PA] = "pa";
    command_array[COMMAND_PB] = "pb";
    command_array[COMMAND_RA] = "ra";
    command_array[COMMAND_RB] = "rb";
    command_array[COMMAND_RR] = "rr";
    command_array[COMMAND_RRA] = "rra";
    command_array[COMMAND_RRB] = "rrb";
    command_array[COMMAND_RRR] = "rrr";
    return (command_array);
}

int print_commands(t_command *command)
{
    int i;
    char **command_array;
    char *temp;

    command_array = make_put_command_array();
    if (command_array == NULL)
        return (ERROR);
    i = 0;
    while (i < command->len)
    {
        temp = command_array[(int)(command->list)[i]];
        write(1, temp, ft_strlen(temp));
        write(1, "\n", 1);
        ++i;
    }
    free(command_array);
    return (SUCCESS);
}
