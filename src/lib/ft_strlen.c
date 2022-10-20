#include "../../inc/push_swap.h"

size_t ft_strlen(const char *s)
{
    size_t i;

    if (s == NULL)
        return (0);
    i = 0;
    while (s[i])
        ++i;
    return (i);
}
