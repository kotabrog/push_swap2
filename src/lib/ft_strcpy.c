#include "../../inc/push_swap.h"

void ft_strcpy(char *p, char const *s, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        p[i] = s[i];
        i++;
    }
}
