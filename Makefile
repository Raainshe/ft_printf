CC = cc # Coqpiler flags that moulinette uses/42.

CC_FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a 

SRC_FILES = ft_gethex.c\
			ft_printf.c\
			ft_putchar_fdp.c\
			ft_putnbr_fdp.c\
			ft_putstr_fdp.c\
			ft_toupperp.c\
			ft_print_unsigned.c\
			ft_get_address.c

OBJ_FILES = $(SRC_FILES:%.c=%.o)  # We convert our SOURCE files to OBJECT files.

# Rule to make sure to compile each .c file into a .o file.
%.o: %.c #ADD $(DEPENDENCIES) if we use HEADER files.This function is used so the "Make" only recompiles the files if something has been modified or updated.
	$(CC) $(CC_FLAGS) -c $< -o $@ 

# Rule to create the executable from object files.
$(NAME): $(OBJ_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)

# Default target: this is what runs when you just type `make`.
all: $(NAME)

#$< Is the source file representative and $@ is the object file representative.
# Clean up: remove object files and the executable file/program.
clean:
	rm -f $(OBJ_FILES) 

fclean: clean #This command calls "clean" function and also makes sure the program file is also removed/cleaned.
	rm -f $(NAME)

re: fclean all #This command calls "fclean" to clean all files and then "all" to recompile everything again.


# Phony targets: these don't correspond to actual files.
.PHONY: all clean fclean re
