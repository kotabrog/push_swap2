#include "../inc/push_swap.h"

static int split_push_a(t_two_stack *target, int num, int *next_value);

static int rotate_reverse_b_and_push_a(t_two_stack *target, int num, int *next_value)
{
    int flag;
    int i;

    flag = 0;
    i = num;
    while (!flag && i-- > 0)
    {
        flag = operate_and_add_command(target, COMMAND_RRB);
        while (!flag && num - i > 0 && *(target->list2->v) == *next_value)
        {
            flag = operate_and_add_command(target, COMMAND_PA);
            flag = flag || operate_and_add_command(target, COMMAND_RA);
            *next_value += + 1;
            num -= 1;
        }
    }
    flag = split_push_a(target, num, next_value);
    return (flag);
}

static int split_push_b(t_two_stack *target, int num, int *next_value)
{
    int count[2];
    int split_point;
    int flag;

    count[0] = 0;
    count[1] = 0;
    split_point = *next_value + num / 2;
    flag = 0;
    while (!flag && num-- > 0)
    {
        if (*(target->list1->v) == *next_value)
        {
            flag = operate_and_add_command(target, COMMAND_RA);
            *next_value += + 1;
            while (!flag && count[0] > 0 && *(target->list2->v) == *next_value)
            {
                flag = operate_and_add_command(target, COMMAND_PA);
                flag = flag || operate_and_add_command(target, COMMAND_RA);
                *next_value += + 1;
                count[0] -= 1;
            }
        }
        else if (*(target->list1->v) < split_point)
        {
            flag = operate_and_add_command(target, COMMAND_PB);
            count[0] += 1;
        }
        else
        {
            flag = operate_and_add_command(target, COMMAND_PB);
            flag = flag || operate_and_add_command(target, COMMAND_RB);
            count[1] += 1;
        }
    }
    if (count[0] > 0)
        flag = split_push_a(target, count[0], next_value);
    if (!flag && count[1] > 0)
        flag = rotate_reverse_b_and_push_a(target, count[1], next_value);
    return (flag);
}


static int split_push_a(t_two_stack *target, int num, int *next_value)
{
    int count[2];
    int split_point;
    int flag;

    count[0] = 0;
    count[1] = 0;
    split_point = *next_value + num / 2;
    flag = 0;
    while (!flag && num-- > 0)
    {
        if (*(target->list2->v) == *next_value)
        {
            flag = operate_and_add_command(target, COMMAND_PA);
            flag = flag || operate_and_add_command(target, COMMAND_RA);
            *next_value += + 1;
            while (!flag && count[0] > 0 && *(target->list1->v) == *next_value)
            {
                flag = operate_and_add_command(target, COMMAND_RA);
                *next_value += + 1;
                count[0] -= 1;
            }
        }
        else if (*(target->list2->v) < split_point)
        {
            flag = operate_and_add_command(target, COMMAND_PA);
            count[0] += 1;
        }
        else
        {
            flag = operate_and_add_command(target, COMMAND_RB);
            count[1] += 1;
        }
    }
    if (count[0] > 0)
        flag = split_push_b(target, count[0], next_value);
    if (!flag && count[1] > 0)
        flag = rotate_reverse_b_and_push_a(target, count[1], next_value);
    return (flag);
}

static int split_push_b_first(t_two_stack *target)
{
    int i;
    int split_point;
    int flag;
    int num;

    num = len_list(target->list1);
    i = num;
    split_point = num / 3;
    flag = 0;
    while (!flag && i-- > 0)
    {
        if (*(target->list1->v) < split_point)
            flag = operate_and_add_command(target, COMMAND_PB);
        else if (*(target->list1->v) < split_point * 2)
        {
            flag = operate_and_add_command(target, COMMAND_PB);
            flag = flag || operate_and_add_command(target, COMMAND_RB);
        }
        else if (i != 0)
            flag = operate_and_add_command(target, COMMAND_RA);
    }
    if (split_push_a(target, split_point, &flag))
        return (ERROR);
    if (split_push_a(target, split_point, &flag))
        return (ERROR);
    if (split_push_b(target, num - split_point * 2, &flag))
        return (ERROR);
    return (SUCCESS);
}

static int init_two_stack(t_two_stack *target, t_cdl_list *list,
                          t_command *command)
{
    target->list1 = list;
    target->command = command;
    if (make_element(&(target->list2), NULL))
        return (ERROR);
    return (SUCCESS);
}

int qs_push_swap(t_cdl_list *list, t_command *command)
{
    t_two_stack target;

    if (init_two_stack(&target, list, command))
        return (ERROR);
    if (split_push_b_first(&target))
        return (ERROR);
    return (SUCCESS);
}