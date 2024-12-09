SRC = main.c
OBJ = $(SRC:.c=.o)
NAME = fractol
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft/ --silent
	$(CC) $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(MAKE) -C ./libft/ clean --silent
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C ./libft/ fclean --silent
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)
