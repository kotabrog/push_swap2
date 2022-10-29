NAME := push_swap

SOURCES_FOLDER = src/
SOURCES =	main.c \
			check_argment.c \
			check_int.c \
			quick_sort.c \
			bfs_push_swap.c \
			qs_push_swap.c \
			lib/ft_malloc.c \
			lib/ft_intcpy.c \
			lib/ft_isdigit.c \
			lib/ft_strcpy.c \
			lib/ft_strlen.c \
			cdl_list/make_element.c \
			cdl_list/int.c \
			cdl_list/push_element.c \
			cdl_list/len.c \
			cdl_list/put_list.c \
			cdl_list/cpy_list.c \
			cdl_list/free.c \
			cdl_list/pop_and_push.c \
			cdl_list/pop_element.c \
			cdl_list/rotate_list.c \
			cdl_list/swap_list.c \
			cdl_list/is_sorted.c \
			cdl_list/check_value.c \
			command/make_command.c \
			command/add_command.c \
			command/cpy_command.c \
			command/free_command.c \
			command/put_command.c \
			command/refactor_command.c \
			two_stack/make_two_stack.c \
			two_stack/operate.c \

SOURCES_PREFIXED = $(addprefix $(SOURCES_FOLDER), $(SOURCES))

INCLUDES_FOLDER = inc/
INCLUDES =	push_swap.h

INCLUDES_PREFIXED = $(addprefix $(INCLUDES_FOLDER), $(INCLUDES))

OBJECTS_FOLDER = obj/
OBJECT = $(SOURCES:.c=.o)
OBJECTS = $(addprefix $(OBJECTS_FOLDER), $(OBJECT))
DEPENDENCIES = $(OBJECTS:.o=.d)

CC := gcc
CFLAGS := -Wall -Wextra -Werror

$(OBJECTS_FOLDER)%.o: $(SOURCES_FOLDER)%.c
	@mkdir -p $(OBJECTS_FOLDER)
	@mkdir -p $(OBJECTS_FOLDER)lib
	@mkdir -p $(OBJECTS_FOLDER)cdl_list
	@mkdir -p $(OBJECTS_FOLDER)command
	@mkdir -p $(OBJECTS_FOLDER)two_stack
	@echo "Compiling : $<"
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES_FOLDER)

$(NAME): $(OBJECTS)
	@echo "Create    : $(NAME)"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

all: $(NAME)

-include $(DEPENDENCIES)

clean:
	@rm -rf $(OBJECTS_FOLDER)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re format
