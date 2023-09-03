NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = convert.c convert1.c ft_convert_base.c ft_convert_base1.c \
	  is_char.c ft_itoa.c ft_putstr.c ft_unsigned_itoa.c \
	  ft_usll_itoa.c start_support.c start.c register_options.c print_result.c ft_strlcpy.c
OBJ = $(SRC:.c=.o)

 %.o: %.c
	$(CC) -c $< $(CFLAGS)

 $(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

 all: $(NAME)

 clean:
	rm -f $(OBJ) $(OBJB)

 fclean: clean
	rm -f $(NAME)

 re: fclean all

.PHONY: all, bonus, clean, fclean, re
