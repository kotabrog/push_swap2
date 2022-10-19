#include "../inc/push_swap.h"

void put_result_and_exit(int mode)
{
    if (mode == ERROR)
        write(1, "KO\n", 3);
    exit(0);
}

int main(int argc, char **argv)
{
    t_cdl_list *list;

    if (make_element(&list, NULL))
        put_result_and_exit(ERROR);
    if (check_argment(argc, argv, &list))
        put_result_and_exit(ERROR);
    put_list(list);
}
