#include "../inc/push_swap.h"

static int set_data_and_num(t_int_data **data, t_num **num)
{
    if (set_int_data(data))
        return (ERROR);
    if (ft_malloc(num, sizeof(t_num), 1))
    {
        ft_free(data);
        return (ERROR);
    }
    return (SUCCESS);
}

static int check_one_argment(char *s, t_int_data *data, t_num *num, \
                             t_cdl_list **list)
{
    if (set_int(s, data, num))
        return (ERROR);
    if (push_int(list, num->v))
        return (ERROR);
    return (SUCCESS);
}

int check_argment(int argc, char **argv, t_cdl_list **list)
{
    int i;
    t_int_data *data;
    t_num *num;

    if (set_data_and_num(&data, &num))
        return (ERROR);
    i = argc - 1;
    while (i > 0)
    {
        if (check_one_argment(argv[i], data, num, list))
            i = 0;
        --i;
    }
    free(data);
    free(num);
    if (i == -1 || check_duplicate(*list))
        return (ERROR);
    return (SUCCESS);
}
