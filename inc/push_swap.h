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
    int capacity;
    int len;
} t_command;

typedef struct s_two_stack {
    t_cdl_list *list1;
    t_cdl_list *list2;
    t_command *command;
} t_two_stack;


int check_argment(int argc, char **argv, t_cdl_list **list);
int	set_int_data(t_int_data **data);
int	set_int(char *s, t_int_data *data, t_num *num);
int check_duplicate(t_cdl_list *list);
int bfs_push_swap(t_cdl_list *list, t_command **command);

// lib
int ft_malloc(void *pointer, size_t type_size, size_t n);
int ft_free(void *pointer);
void int_cpy(int *p, const int *s, size_t n);
int ft_isdigit(int c);
size_t ft_strlen(const char *s);
void ft_strcpy(char *p, char const *s, size_t n);

// cdl_list
int make_element(t_cdl_list **element, void *v);
void push_element(t_cdl_list **list, t_cdl_list *element);
void push_back_element(t_cdl_list *list, t_cdl_list *element);
int int_to_element(t_cdl_list **list, int v);
int push_int(t_cdl_list **list, int v);
int len_list(t_cdl_list *list);
int put_list(t_cdl_list *list);
void free_list(t_cdl_list **list);
t_cdl_list *cpy_list(t_cdl_list *list);
t_cdl_list *pop_element(t_cdl_list **list);
t_cdl_list *pop_back_element(t_cdl_list *list);
int swap_list(t_cdl_list **list);
int swap_two_list(t_cdl_list **list1, t_cdl_list **list2);
int pop_and_push_list(t_cdl_list **giver, t_cdl_list **receiver);
int rotate_list(t_cdl_list **list);
int rotate_two_list(t_cdl_list **list1, t_cdl_list **list2);
int rotate_reverse_list(t_cdl_list **list);
int rotate_reverse_two_list(t_cdl_list **list1, t_cdl_list **list2);
int is_sorted_list(t_cdl_list *list);

// command
int make_command(t_command **command);
void free_command(t_command **command);
int print_commands(t_command *command);
int cpy_command(t_command *src, t_command **dest);
int add_command(t_command *command, char one_command);

// two_stack

int make_two_stack(t_two_stack **two_stack, t_cdl_list *list1,
                   t_cdl_list *list2, t_command *command);
int operate_command(t_cdl_list **list1, t_cdl_list **list2, char command);
int operate_commands(t_two_stack *target);


#endif
