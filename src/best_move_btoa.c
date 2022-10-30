#include "../inc/push_swap.h"

static int best_1_move(t_two_stack *target)
{
    int flag;

    flag = operate_and_add_command(target, COMMAND_PA);
    flag = flag || operate_and_add_command(target, COMMAND_RA);
    return (flag);
}

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

int best_3_move_btoa(t_two_stack *target, int next_value)
{
    int flag;

    if (*(target->list2->v) == next_value)
    {
        flag = operate_and_add_command(target, COMMAND_PA);
        flag = flag || operate_and_add_command(target, COMMAND_RA);
        return (flag || best_2_move(target, next_value + 1));
    }
    if (*(target->list2->v) == next_value + 2)
    {
        flag = operate_and_add_command(target, COMMAND_PA);
        flag = flag || best_2_move(target, next_value);
        return (flag || operate_and_add_command(target, COMMAND_RA));
    }
    if (*(target->list2->next->v) == next_value)
    {
        flag = best_2_move(target, next_value);
        flag = flag || operate_and_add_command(target, COMMAND_PA);
        return (flag || operate_and_add_command(target, COMMAND_RA));
    }
    flag = operate_and_add_command(target, COMMAND_PA);
    flag = flag || operate_and_add_command(target, COMMAND_PA);
    flag = flag || operate_and_add_command(target, COMMAND_SA);
    flag = flag || operate_and_add_command(target, COMMAND_PA);
    flag = flag || operate_and_add_command(target, COMMAND_RA);
    flag = flag || operate_and_add_command(target, COMMAND_RA);
    return (flag || operate_and_add_command(target, COMMAND_RA));
}

static int best_4_move(t_two_stack *target, int next_value)
{
    int flag;

    flag = operate_and_add_command(target, COMMAND_PA);
    if (*(target->list1->v) == next_value)
    {
        flag = flag || operate_and_add_command(target, COMMAND_RA);
        return (flag || best_3_move_btoa(target, next_value + 1));
    }
    flag = flag || operate_and_add_command(target, COMMAND_PA);
    if (*(target->list1->v) == next_value)
    {
        flag = flag || operate_and_add_command(target, COMMAND_RA);
        flag = flag || operate_and_add_command(target, COMMAND_PB);
        return (flag || best_3_move_btoa(target, next_value + 1));
    }
    if (*(target->list2->v) != next_value &&
            *(target->list1->v) > *(target->list1->next->v))
        flag = flag || operate_and_add_command(target, COMMAND_SS);
    flag = flag || operate_and_add_command(target, COMMAND_PA);
    if (*(target->list1->v) == next_value)
    {
        flag = flag || operate_and_add_command(target, COMMAND_RA);
        if (*(target->list1->next->v) == next_value + 1)
            flag = flag || operate_and_add_command(target, COMMAND_SA);
        else if (*(target->list2->v) == next_value + 1)
            flag = flag || operate_and_add_command(target, COMMAND_PA);
        flag = flag || operate_and_add_command(target, COMMAND_RA);
        if (*(target->list1->v) == next_value + 2)
            ;
        else if (*(target->list1->next->v) == next_value + 2)
            flag = flag || operate_and_add_command(target, COMMAND_SA);
        else
            flag = flag || operate_and_add_command(target, COMMAND_PA);
        flag = flag || operate_and_add_command(target, COMMAND_RA);
        if (*(target->list1->v) != next_value + 3)
            flag = flag || operate_and_add_command(target, COMMAND_PA);
        return (flag || operate_and_add_command(target, COMMAND_RA));
    }
    flag = flag || operate_and_add_command(target, COMMAND_PA);
    flag = flag || operate_and_add_command(target, COMMAND_RA);
    return (flag || best_3_move_atob(target, next_value + 1));
}

int best_move_btoa(t_two_stack *target, int num, int *next_value)
{
    int flag;

    flag = ERROR;
    if (num == 1)
        flag = best_1_move(target);
    else if (num == 2)
        flag = best_2_move(target, *next_value);
    else if (num == 3)
        flag = best_3_move_btoa(target, *next_value);
    else if (num == 4)
        flag = best_4_move(target, *next_value);
    *next_value += num;
    return (flag);
}
