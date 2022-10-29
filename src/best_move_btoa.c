#include "../inc/push_swap.h"

static int best_2_move(t_two_stack *target, int next_value)
{
    int flag;
    int next_is_first;

    next_is_first = (*(target->list2->v) == next_value);
    flag = operate_and_add_command(target, COMMAND_PA);
    if (next_is_first)
        flag = flag || operate_and_add_command(target, COMMAND_RA);
    flag = flag || operate_and_add_command(target, COMMAND_PA);
    flag = flag || operate_and_add_command(target, COMMAND_RA);
    if (!next_is_first)
        flag = flag || operate_and_add_command(target, COMMAND_RA);
    return (flag);
}

static int best_1_move(t_two_stack *target)
{
    int flag;

    flag = operate_and_add_command(target, COMMAND_PA);
    flag = flag || operate_and_add_command(target, COMMAND_RA);
    return (flag);
}

int best_move_btoa(t_two_stack *target, int num, int *next_value)
{
    int flag;

    flag = ERROR;
    if (num == 1)
        flag = best_1_move(target);
    else if (num == 2)
        flag = best_2_move(target, *next_value);
    *next_value += num;
    return (flag);
}
