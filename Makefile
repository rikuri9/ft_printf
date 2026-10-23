NAME = libftprintf.a
SRCS = ft_printf.c \
		ft_putchar.c \
		ft_putbase.c \
		ft_putnbr.c \
		ft_putptr.c \
		ft_putstr.c
		
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re