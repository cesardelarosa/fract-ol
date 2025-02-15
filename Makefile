NAME = fractol

INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
MINILIBX_DIR = minilibx

SRC_FILES = main.c hooks.c parser.c draw.c fractals.c
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L $(LIBFT_DIR) -L $(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -lft
INCLUDE = -I $(INCLUDE_DIR) -I $(MINILIBX_DIR) -I $(LIBFT_DIR)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_FILES)
	@make -C $(LIBFT_DIR) all printf
	@make -C $(MINILIBX_DIR)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
