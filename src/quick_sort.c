#include "../inc/push_swap.h"

static void replacement_to_index(t_cdl_list *list, int *array)
{
    int i;

    while (list->v)
    {
        i = 0;
        while (array[i] != *(list->v))
            ++i;
        *(list->v) = i;
        list = list->next;
    }
}


static int move_half(int *list, int start, int end, int *temp)
{
    int i;
    int temp_end;
    int middle_index;

    i = start;
    temp_end = end;
    middle_index = (end - start) / 2 + start;
    while (i < temp_end)
    {
        if (list[i] < list[middle_index])
        {
            temp[start] = list[i];
            ++start;
        }
        else if (list[i] > list[middle_index])
        {
            temp[end - 1] = list[i];
            --end;
        }
        else if (i != middle_index)
            return (-1);
        ++i;
    }
    temp[start] = list[middle_index];
    return (start);
}

static int simple_quick_sort(int *list, int start, int end, int *temp)
{
    int middle_index;

    if (end - start <= 1)
        return (SUCCESS);
    middle_index = move_half(list, start, end, temp);
    if (middle_index == -1)
        return (ERROR);
    int_cpy(list + start, temp + start, end - start);
    if (simple_quick_sort(list, start, middle_index, temp))
        return (ERROR);
    if (simple_quick_sort(list, middle_index + 1, end, temp))
        return (ERROR);
    return (SUCCESS);
}

static void cpy_list_to_array(t_cdl_list *list, int *array)
{
    while (list->v)
    {
        *array = *(list->v);
        ++array;
        list = list->next;
    }
}

static int is_sorted_array(int *array, size_t n)
{
    size_t i;

    i = 1;
    while (i < n)
    {
        if (array[i - 1] >= array[i])
            return (ERROR);
        ++i;
    }
    return (SUCCESS);
}

int check_duplicate(t_cdl_list *list)
{
    int n;
    int *sorted;
    int *temp;

    n = len_list(list);
    temp = NULL;
    if (ft_malloc(&sorted, sizeof(int), n) || ft_malloc(&temp, sizeof(int), n))
    {
        free(temp);
        free(sorted);
        return (ERROR);
    }
    cpy_list_to_array(list, sorted);
    if (!simple_quick_sort(sorted, 0, n, temp))
        n = is_sorted_array(sorted, n);
    replacement_to_index(list, sorted);
    free(temp);
    free(sorted);
    return (n);
}
