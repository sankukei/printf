CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs

NAME        = ft_printf.a
SRCS        = ft_printf.c printf_utils.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

