NAME = libftprintf.a

HEADER = ./ft_printf.h

SRCS = ./ft_printf.c \
		./ft_printf_utils.c\

CFLAGS =  -Wall -Wextra -Werror -g

CC = gcc

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re