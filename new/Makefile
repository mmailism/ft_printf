# NAME = libftprintf.a
# CC = cc
# CFLAGS = -Wall -Wextra -Werror

# SRCS =	ft_printf.c \
# 		printf.c \ 
# 		ft_libft.c

# OBJS = $(SRCS:.c=.o)

# all: $(NAME)

# $(NAME): $(OBJS)
# 	ar -rcs $(NAME) $(OBJS)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c -o $(SRCS)

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean $(NAME)

# .PHONY: all, clean, fclean, re
NAME = libftprintf.a

sources = ft_printf.c print.c ft_libft.c

sources_o = ft_printf.o print.o ft_libft.o

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(sources_o)
	ar -crs $(NAME) $(sources_o)

functions_o: $(sources) 
	$(CC) -c -o $(sources)

clean: ;
	rm -f $(sources_o)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all, clean, fclean, re