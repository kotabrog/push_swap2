#include "../inc/push_swap.h"

int set_int_data(t_int_data **data)
{
    int digits;
    int num;

    if (ft_malloc(data, sizeof(t_int_data), 1))
        return (ERROR);
    num = INT_MAX;
    (*data)->int_max_over_ten = num / 10;
    (*data)->first_digit_of_int_max = num % 10;
    digits = 0;
    while (num != 0)
    {
        ++digits;
        num /= 10;
    }
    (*data)->number_of_digits = digits;
    return (SUCCESS);
}

static void reset_num(t_num *num)
{
    num->v = 0;
    num->digits = 0;
    num->sign = 1;
}

static int processing_int_min(t_num *num)
{
    num->v = INT_MIN;
    num->sign = 1;
    ++(num->digits);
    return (SUCCESS);
}

static int check_one(t_num *num, t_int_data *data, int c)
{
    if (!ft_isdigit(c))
        return (ERROR);
    c = c - '0';
    if (num->digits >= data->number_of_digits)
        return (ERROR);
    if (num->v == 0 && num->digits == 1)
        return (ERROR);
    if (num->digits == data->number_of_digits - 1)
    {
        if (num->v > data->int_max_over_ten)
            return (ERROR);
        if (num->v == data->int_max_over_ten)
        {
            if (num->sign == 1 && c > data->first_digit_of_int_max)
                return (ERROR);
            if (num->sign == -1 && c > data->first_digit_of_int_max + 1)
                return (ERROR);
            if (num->sign == -1 && c == data->first_digit_of_int_max + 1)
                return (processing_int_min(num));
        }
    }
    num->v = num->v * 10 + c;
    ++(num->digits);
    return (SUCCESS);
}

int set_int(char *s, t_int_data *data, t_num *num)
{
    reset_num(num);
    if (*s == '-')
    {
        num->sign = -1;
        s++;
    }
    while (*s)
    {
        if (check_one(num, data, *s))
            return (ERROR);
        ++s;
    }
    num->v *= num->sign;
    return (SUCCESS);
}
