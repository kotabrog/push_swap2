#include "../../inc/push_swap.h"

int make_two_stack(t_two_stack **two_stack, t_cdl_list *list1,
                   t_cdl_list *list2, t_command *command)
{
    if (ft_malloc(two_stack, sizeof(t_two_stack), 1))
        return (ERROR);
    if (list1 == NULL && make_element(&list1, NULL))
        return (ERROR);
    if (list2 == NULL && make_element(&list2, NULL))
        return (ERROR);
    if (command == NULL && make_command(&command))
        return (ERROR);
    (*two_stack)->list1 = list1;
    (*two_stack)->list2 = list2;
    (*two_stack)->command = command;
    return (SUCCESS);
}
