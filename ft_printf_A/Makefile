CC = cc
CC_FLAGS = -Wall -Wextra -Werror

SRCS = 	ft_printf.c ft_put_format.c ft_put_ulitity.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
