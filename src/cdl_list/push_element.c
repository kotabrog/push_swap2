#include "../../inc/push_swap.h"

void push_element(t_cdl_list **list, t_cdl_list *element)
{
    element->next = *list;
    element->prev = (*list)->prev;
    ((*list)->prev)->next = element;
    (*list)->prev = element;
    *list = element;
}

void push_back_element(t_cdl_list *list, t_cdl_list *element)
{
    element->next = list->prev;
    element->prev = (list->prev)->prev;
    ((list->prev)->prev)->next = element;
    (list->prev)->prev = element;
}
