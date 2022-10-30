#include "../inc/push_swap.h"

static int best_1_move(t_two_stack *target)
{
    int flag;

    flag = operate_and_add_command(target, COMMAND_RA);
    return (flag);
}

static int best_2_move(t_two_stack *target, int next_value)
{
    int flag;

    flag = 0;
    if (*(target->list1->v) != next_value)
        flag = operate_and_add_command(target, COMMAND_SA);
    flag = flag || operate_and_add_command(target, COMMAND_RA);
    flag = flag || operate_and_add_command(target, COMMAND_RA);
    return (flag);
}

int best_move_atob(t_two_stack *target, int num, int *next_value)
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
