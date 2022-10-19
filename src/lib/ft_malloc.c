#include "../../inc/push_swap.h"

int ft_malloc(void *pointer, size_t type_size, size_t n)
{
    *(void **)pointer = malloc(type_size * n);
    return (!*(void **)pointer);
}

int ft_free(void *pointer)
{
    free(*(void **)pointer);
    *(void **)pointer = NULL;
    return (SUCCESS);
}
