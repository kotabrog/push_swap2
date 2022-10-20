NAME := push_swap

SOURCES_FOLDER = src/
SOURCES =	main.c \
			check_argment.c \
			check_int.c \
			quick_sort.c \
			lib/ft_malloc.c \
			lib/ft_intcpy.c \
			lib/ft_isdigit.c \
			cdl_list/make_element.c \
			cdl_list/int.c \
			cdl_list/push_element.c \
			cdl_list/len.c \
			cdl_list/put_list.c \
			command/make_command.c \

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
