#include "../../inc/push_swap.h"

int operate_and_add_command(t_two_stack *target, char command)
{
    if (add_command(target->command, command))
        return (ERROR);
    operate_command(&(target->list1), &(target->list2), command);
    return (SUCCESS);
}

int operate_command(t_cdl_list **list1, t_cdl_list **list2, char command)
{
    if (command == COMMAND_SA)
        return (swap_list(list1));
    else if (command == COMMAND_SB)
        return (swap_list(list2));
    else if (command == COMMAND_SS)
        return (swap_two_list(list1, list2));
    else if (command == COMMAND_PA)
        return (pop_and_push_list(list2, list1));
    else if (command == COMMAND_PB)
        return (pop_and_push_list(list1, list2));
    else if (command == COMMAND_RA)
        return (rotate_list(list1));
    else if (command == COMMAND_RB)
        return (rotate_list(list2));
    else if (command == COMMAND_RR)
        return (rotate_two_list(list1, list2));
    else if (command == COMMAND_RRA)
        return (rotate_reverse_list(list1));
    else if (command == COMMAND_RRB)
        return (rotate_reverse_list(list2));
    else if (command == COMMAND_RRR)
        return (rotate_reverse_two_list(list1, list2));
    return (ERROR);
}

int operate_commands(t_two_stack *target)
{
    int i;

    i = 0;
    while (i < target->command->len)
    {
        if (operate_command(&(target->list1), &(target->list2),
                            (target->command->list)[i]))
            return (ERROR);
        ++i;
    }
    return (SUCCESS);
}
