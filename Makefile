NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./minilibx -L./libft -L./ft_printf -lmlx -lXext -lX11 -lm
INCLUDE = -I./include -I./minilibx -I./ft_printf -I./libft

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = main.c draw.c
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_FILES)
	@make -C minilibx
	@make -C ft_printf
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@ $(LDFLAGS) -lft -lftprintf

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@make -C minilibx clean
	@make -C ft_printf clean
	@make -C libft clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
