NAME = libftprintf.a
SRCS = ./src/ft_printf.c \
		./src/ft_putchar.c \
		./src/ft_putbase.c \
		./src/ft_putnbr.c \
		./src/ft_putptr.c \
		./src/ft_putstr.c
		
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c includes/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re