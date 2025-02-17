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
SANITIZE = -g3 -fsanitize=address -fsanitize=undefined

GREEN = \033[0;32m
BLUE  = \033[0;34m
YELLOW = \033[1;33m
RED   = \033[0;31m
NC    = \033[0m

all: $(OBJ_DIR) $(NAME)
	@echo -e "$(GREEN)[fractol] Compilación completada$(NC)"

$(OBJ_DIR):
	@echo -e "$(BLUE)[fractol] Creando directorio de objetos...$(NC)"
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_FILES)
	@echo -e "$(BLUE)[fractol] Compilando Libft...$(NC)"
	make -C $(LIBFT_DIR) all
	@echo -e "$(BLUE)[fractol] Compilando MinilibX...$(NC)"
	make -C $(MINILIBX_DIR)
	@echo -e "$(BLUE)[fractol] Linkeando y generando el ejecutable...$(NC)"
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo -e "$(YELLOW)[fractol] Compilando $<...$(NC)"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo -e "$(RED)[fractol] Limpiando objetos...$(NC)"
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean

fclean: clean
	@echo -e "$(RED)[fractol] Eliminando ejecutable...$(NC)"
	rm -f $(NAME)

re: fclean all

check: CFLAGS += $(SANITIZE)
check: re
	@echo -e "$(BLUE)[fractol] Ejecutando norminette...$(NC)"
	norminette $(INCLUDE_DIR) $(SRC_DIR) $(LIBFT_DIR)

.PHONY: all clean fclean re sanitize
