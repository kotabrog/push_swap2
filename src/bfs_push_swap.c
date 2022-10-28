#include "../inc/push_swap.h"

static int update_bfs_command(t_command *command)
{
    int i;

    i = 0;
    while (i < command->len && command->list[i] == COMMAND_RRR)
        ++i;
    if (i < command->len)
    {
        command->list[i] += 1;
        while (i-- > 0)
            command->list[i] = COMMAND_SA;
    }
    else
    {
        if (add_command(command, COMMAND_SA))
            return (ERROR);
        while (i-- > 0)
            command->list[i] = COMMAND_SA;
    }
    return (SUCCESS);
}

static int init_two_stack(t_two_stack *target, t_cdl_list *list)
{
    target->list1 = cpy_list(list);
    if (target->list1 == NULL)
        return (ERROR);
    if (make_element(&(target->list2), NULL))
        return (ERROR);
    return (SUCCESS);
}

int bfs_push_swap(t_cdl_list *list, t_command *command)
{
    t_two_stack target;
    int continue_flag;

    target.command = command;
    continue_flag = 1;
    while (continue_flag)
    {
        if (init_two_stack(&target, list))
            return (ERROR);
        if (update_bfs_command(target.command))
            return (ERROR);
        if (!operate_commands(&target))
        {
            if (len_list(target.list2) == 0 && is_sorted_list(target.list1))
                continue_flag = 0;
        }
        free_list(&(target.list1));
        free_list(&(target.list2));
    }
    return (SUCCESS);
}
