SRCS =	ft_itoa_fd.c \
		ft_printf.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_strlen.c \
		ft_write_hex_l_fd.c \
		ft_write_hex_up_fd.c \
		ft_itoa_u_fd.c \
		ft_print_ptr_fd.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean 