NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	ft_printf.c ft_print_format.c ft_libft.c ft_print_hex.c ft_ulitity.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all, clean, fclean, re