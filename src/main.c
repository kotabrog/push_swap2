#include "../inc/push_swap.h"

void put_result_and_exit(int mode)
{
    if (mode == ERROR)
        write(1, "KO\n", 3);
    exit(0);
}

int push_swap(t_cdl_list *list, t_command **command)
{
    if (is_sorted_list(list))
        return (SUCCESS);
    if (bfs_push_swap(list, command))
        return (ERROR);
    return (SUCCESS);
}

int main(int argc, char **argv)
{
    t_cdl_list *list;
    t_command *command;

    if (make_element(&list, NULL))
        put_result_and_exit(ERROR);
    if (check_argment(argc, argv, &list))
        put_result_and_exit(ERROR);
    if (make_command(&command))
        put_result_and_exit(ERROR);
    if (push_swap(list, &command))
        put_result_and_exit(ERROR);
    if (print_commands(command))
        put_result_and_exit(ERROR);
    // put_list(list);
}
