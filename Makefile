SRC_c = src/client.c
SRC_s = src/server.c
SRC_atoi = src/ft_atoi.c
SRC_c_bonus = src/client_bonus.c 
SRC_s_bonus = src/server_bonus.c

OBJ_c = $(SRC_c:.c=.o)
OBJ_s = $(SRC_s:.c=.o)
OBJ_c_bonus = $(SRC_c_bonus:.c=.o)
OBJ_s_bonus = $(SRC_s_bonus:.c=.o)
OBJ_ATOI = $(SRC_atoi:.c=.o)

NAME_server = server
NAME_server_bonus = server_bonus
NAME_client = client
NAME_client_bonus = client_bonus

LIBFTPRINTF = ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC
INCLUDES = -I include/
RM = rm -f

all: $(NAME_server) $(NAME_client)

$(LIBFTPRINTF):
	@make -C ft_printf

$(NAME_server): $(OBJ_s) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_s) $(LIBFTPRINTF) -o $(NAME_server)

$(NAME_client): $(OBJ_c) $(OBJ_ATOI) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_c) $(OBJ_ATOI) $(LIBFTPRINTF) -o $(NAME_client)

bonus: $(NAME_server_bonus) $(NAME_client_bonus)

$(NAME_server_bonus): $(OBJ_s_bonus) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_s_bonus) $(LIBFTPRINTF) -o $(NAME_server_bonus)

$(NAME_client_bonus): $(OBJ_c_bonus) $(OBJ_ATOI) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_c_bonus) $(OBJ_ATOI) $(LIBFTPRINTF) -o $(NAME_client_bonus)

clean:
	@make clean -C ft_printf
	$(RM) $(OBJ_s) $(OBJ_c) $(OBJ_c_bonus) $(OBJ_s_bonus) $(OBJ_ATOI)

fclean: clean
	@make fclean -C ft_printf
	$(RM) $(NAME_server) $(NAME_client) $(NAME_server_bonus) $(NAME_client_bonus)

re: fclean all

.PHONY: all bonus clean fclean re
