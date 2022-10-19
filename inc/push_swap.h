#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>

# define SUCCESS 0
# define ERROR 1
# define BUFF_SIZE 1024
# define COMMAND_SIZE 64
# define COMMAND_NEXT 0
# define COMMAND_SA 2
# define COMMAND_SB 3
# define COMMAND_SS 4
# define COMMAND_PA 5
# define COMMAND_PB 6
# define COMMAND_RA 7
# define COMMAND_RB 8
# define COMMAND_RR 9
# define COMMAND_RRA 10
# define COMMAND_RRB 11
# define COMMAND_RRR 12


typedef struct s_cdl_list {
    int *v;
    struct s_cdl_list *next;
    struct s_cdl_list *prev;
} t_cdl_list;

typedef struct s_int_data {
    int number_of_digits;
    int int_max_over_ten;
    int first_digit_of_int_max;
} t_int_data;

typedef struct s_num {
    int v;
    int digits;
    int sign;
} t_num;

typedef struct s_command {
    char *list;
    int len;
    int point;
} t_command;


int check_argment(int argc, char **argv, t_cdl_list **list);
int	set_int_data(t_int_data **data);
int	set_int(char *s, t_int_data *data, t_num *num);
int check_duplicate(t_cdl_list *list);

// lib
int ft_malloc(void *pointer, size_t type_size, size_t n);
int ft_free(void *pointer);
void int_cpy(int *p, const int *s, size_t n);
int ft_isdigit(int c);

// cdl_list
int make_element(t_cdl_list **element, void *v);
void push_element(t_cdl_list **list, t_cdl_list *element);
void push_back_element(t_cdl_list *list, t_cdl_list *element);
int int_to_element(t_cdl_list **list, int v);
int push_int(t_cdl_list **list, int v);
int len_list(t_cdl_list *list);
int put_list(t_cdl_list *list);


#endif
