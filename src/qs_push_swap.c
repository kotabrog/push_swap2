#include "../inc/push_swap.h"

static int split_push_a(t_two_stack *target, int num, int *next_value);
static int split_push_b(t_two_stack *target, int num, int *next_value);

static int rotate_reverse_b_and_push_a(t_two_stack *target, int num,
                                       int *next_value, int rotated)
{
    int count[2];
    int split_point;
    int flag;

    count[0] = 0;
    count[1] = 0;
    split_point = *next_value + (num + rotated) / 2;
    flag = 0;
    while (!flag && rotated-- > 0)
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
        else if (!is_any_less_value_list(target->list2, rotated + 1, split_point))
            break;
        else
        {
            if (len_list(target->list2) >= 2)
                flag = operate_and_add_command(target, COMMAND_RB);
            num += 1;
        }
    }
    count[1] = rotated + 1;
    while (!flag && num-- > 0)
    {
        flag = operate_and_add_command(target, COMMAND_RRB);
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
            count[1] += 1;
    }
    if (count[0] > 0)
        flag = split_push_b(target, count[0], next_value);
    if (!flag && count[1] > 0)
        flag = split_push_a(target, count[1], next_value);
    return (flag);
}

static int split_push_b(t_two_stack *target, int num, int *next_value)
{
    int count[3];
    int split_point;
    int flag;

    if (num <= 0)
        return (SUCCESS);
    else if (num <= 4)
        return (best_move_atob(target, num, next_value));
    count[0] = 0;
    count[1] = 0;
    count[2] = 0;
    split_point = *next_value + num / 2 + 2;
    flag = 0;
    while (!flag && num-- > 0)
    {
        if (count[0] == 0 && num + 1 <= 4 &&
                is_all_less_value_list(target->list1, num + 1, *next_value + num + 1))
        {
            flag = best_move_atob(target, num + 1, next_value);
            break;
        }
        else if (*(target->list1->v) == *next_value)
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
            if (count[0] == 0)
                count[2] += 1;
            else
            {
                if (len_list(target->list2) >= 2)
                    flag = flag || operate_and_add_command(target, COMMAND_RB);
                count[1] += 1;
            }
        }
    }
    if (count[0] > 0)
        flag = split_push_a(target, count[0], next_value);
    if (!flag && (count[1] > 0 || count[2] > 0))
        flag = rotate_reverse_b_and_push_a(target, count[1], next_value, count[2]);
    return (flag);
}


static int split_push_a(t_two_stack *target, int num, int *next_value)
{
    int count[2];
    int split_point;
    int flag;
    // int next_flag;

    if (num <= 0)
        return (SUCCESS);
    else if (num <= 4)
        return (best_move_btoa(target, num, next_value));
    count[0] = 0;
    count[1] = 0;
    split_point = *next_value + num / 2 + 1;
    flag = 0;
    // next_flag = 0;
    while (!flag && num-- > 0)
    {
        if (count[0] == 0 && num + 1 <= 4 &&
                is_all_less_value_list(target->list2, num + 1, *next_value + num + 1))
        {
            flag = best_move_btoa(target, num + 1, next_value);
            num = -1;
            break;
        }
        else if (*(target->list2->v) == *next_value)
        {
            flag = operate_and_add_command(target, COMMAND_PA);
            flag = flag || operate_and_add_command(target, COMMAND_RA);
            *next_value += + 1;
            while (!flag && count[0] > 0 && *(target->list1->v) == *next_value)
            {
                flag = operate_and_add_command(target, COMMAND_RA);
                *next_value += + 1;
                count[0] -= 1;
                if (!flag && count[0] >= 2 && *(target->list1->next->v) == *next_value)
                    flag = operate_and_add_command(target, COMMAND_SA);
            }
        }
        // else if (*(target->list2->v) == *next_value + 1 &&
        //         num >= 1 &&
        //         *(target->list2->next->v) != *next_value &&
        //         is_any_less_value_list(target->list2, num + 1, *next_value + 1))
        // {
            
        // }
        else if (*(target->list2->v) < split_point)
        {
            flag = operate_and_add_command(target, COMMAND_PA);
            count[0] += 1;
        }
        else if (!is_any_less_value_list(target->list2, num + 1, split_point))
            break;
        else
        {
            if (len_list(target->list2) >= 2)
                flag = operate_and_add_command(target, COMMAND_RB);
            count[1] += 1;
        }
    }
    num += 1;
    if (count[0] > 0)
        flag = split_push_b(target, count[0], next_value);
    if (!flag && count[1] + num > 0)
        flag = rotate_reverse_b_and_push_a(target, count[1], next_value, num);
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
            if (len_list(target->list2) >= 2)
                flag = flag || operate_and_add_command(target, COMMAND_RB);
        }
        else if (is_any_less_value_list(target->list1, i + 1, split_point * 2))
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