# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./minilibx -L./libft -L./ft_printf -lmlx -lXext -lX11 -lm
INCLUDE = -I./inc -I./minilibx -I./ft_printf -I./libft

# Directorios
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib

# Archivos fuente y objeto
SRC_FILES = main.c draw.c utils.c
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

# Nombre del ejecutable
NAME = fractol

.PHONY: all clean fclean re

# Regla principal
all: $(OBJ_DIR) $(NAME)

# Crear directorio de objetos
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Regla para compilar el ejecutable
$(NAME): $(OBJ_FILES)
	@make -C minilibx
	@make -C ft_printf
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@ $(LDFLAGS) -lft -lftprintf

# Regla para compilar archivos .c a .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Limpiar archivos compilados
clean:
	rm -rf $(OBJ_DIR)
	@make -C minilibx clean
	@make -C ft_printf clean
	@make -C libft clean

fclean: clean
	rm -f $(NAME)

re: fclean all

