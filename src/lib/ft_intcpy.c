#include "../../inc/push_swap.h"

void int_cpy(int *p, const int *s, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        p[i] = s[i];
        ++i;
    }
}
