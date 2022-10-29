#include "../../inc/push_swap.h"

static int is_marge_3to2_command(char commandA, char commandB, char commandC)
{
    if ((commandA == COMMAND_PB && commandB == COMMAND_RA &&
            commandC == COMMAND_PA))
        return (COMMAND_SA);
    if ((commandA == COMMAND_PA && commandB == COMMAND_RB &&
            commandC == COMMAND_PB))
        return (COMMAND_SB);
    return (0);
}

static void marge_3to2_command(t_command *command, int *refactor_flag)
{
    int i;
    int flag;

    i = 0;
    while (i < command->len - 3)
    {
        flag = is_marge_3to2_command((command->list)[i], (command->list)[i + 1],
                                     (command->list)[i + 2]);
        if (flag)
        {
            *refactor_flag = 1;
            command->list[i] = flag;
            if (command->len > i + 3)
                ft_strcpy(&(command->list[i + 2]), &(command->list[i + 3]), command->len - i - 3);
            command->len -= 1;
        }
        ++i;
    }
}

static int is_marge_double_command(char commandA, char commandB)
{
    if ((commandA == COMMAND_RA && commandB == COMMAND_RB) ||
            (commandA == COMMAND_RB && commandB == COMMAND_RA))
        return (COMMAND_RR);
    if ((commandA == COMMAND_RRA && commandB == COMMAND_RRB) ||
            (commandA == COMMAND_RRB && commandB == COMMAND_RRA))
        return (COMMAND_RRR);
    return (0);
}

static void marge_double_command(t_command *command, int *refactor_flag)
{
    int i;
    int flag;

    i = 0;
    while (i < command->len - 1)
    {
        flag = is_marge_double_command((command->list)[i], (command->list)[i + 1]);
        if (flag)
        {
            *refactor_flag = 1;
            command->list[i] = flag;
            if (command->len > i + 2)
                ft_strcpy(&(command->list[i + 1]), &(command->list[i + 2]), command->len - i - 2);
            command->len -= 1;
        }
        ++i;
    }
}

static int is_double_nop(char commandA, char commandB)
{
    return ((commandA == COMMAND_PA && commandB == COMMAND_PB) ||
            (commandA == COMMAND_PB && commandB == COMMAND_PA) ||
            (commandA == COMMAND_RA && commandB == COMMAND_RRA) ||
            (commandA == COMMAND_RRA && commandB == COMMAND_RA) ||
            (commandA == COMMAND_RB && commandB == COMMAND_RRB) ||
            (commandA == COMMAND_RRB && commandB == COMMAND_RB));
}

static void delete_double_nop(t_command *command, int *flag)
{
    int i;

    i = 0;
    while (i < command->len - 1)
    {
        if (is_double_nop((command->list)[i], (command->list)[i + 1]))
        {
            *flag = 1;
            if (command->len > i + 2)
                ft_strcpy(&(command->list[i]), &(command->list[i + 2]), command->len - i - 2);
            command->len -= 2;
            if (i > 0)
                --i;
        }
        else
            ++i;
    }
}

void refactor_command(t_command *command)
{
    int flag;

    flag = 1;
    while (flag)
    {
        flag = 0;
        delete_double_nop(command, &flag);
        marge_double_command(command, &flag);
        marge_3to2_command(command, &flag);
    }
}
