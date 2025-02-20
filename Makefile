NAME = fractol
INCLUDE_DIR = include
SRC_DIR = src
BONUS_DIR = bonus
OBJ_DIR = obj
LIBFT_DIR = libft
MINILIBX_DIR = minilibx

MANDATORY_SRC = main.c hooks.c parser.c draw.c math.c
MANDATORY_OBJ = $(MANDATORY_SRC:%.c=$(OBJ_DIR)/%.o)

BONUS_SRC = main_bonus.c hooks_bonus.c parser_bonus.c draw_bonus.c math_bonus.c math2_bonus.c
BONUS_OBJ = $(BONUS_SRC:%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L $(LIBFT_DIR) -L $(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -lft
INCLUDE = -I $(INCLUDE_DIR) -I $(MINILIBX_DIR) -I $(LIBFT_DIR)
MODE_FILE = .mode

GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
RED = \033[0;31m
NC = \033[0m

all: mandatory

mandatory:
	@if [ -f $(MODE_FILE) ] && [ "$$(cat $(MODE_FILE))" = "mandatory" ]; then \
	    echo "[fractol] La versión mandatory ya está compilada."; \
	else \
	    $(MAKE) re_mandatory; \
	fi

bonus:
	@if [ -f $(MODE_FILE) ] && [ "$$(cat $(MODE_FILE))" = "bonus" ]; then \
	    echo "[fractol] La versión bonus ya está compilada."; \
	else \
	    $(MAKE) re_bonus; \
	fi

re_mandatory: $(OBJ_DIR) $(MANDATORY_OBJ) $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx.a
	@echo "$(BLUE)[fractol] Linkeando y generando el ejecutable MANDATORY...$(NC)"
	$(CC) $(CFLAGS) $(MANDATORY_OBJ) -o $(NAME) $(LDFLAGS)
	@echo "mandatory" > $(MODE_FILE)
	@echo "$(GREEN)[fractol] Compilación MANDATORY completada$(NC)"

re_bonus: $(OBJ_DIR) $(BONUS_OBJ) $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx.a
	@echo "$(BLUE)[fractol] Linkeando y generando el ejecutable BONUS...$(NC)"
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(NAME) $(LDFLAGS)
	@echo "bonus" > $(MODE_FILE)
	@echo "$(GREEN)[fractol] Compilación BONUS completada$(NC)"

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR) complete

$(MINILIBX_DIR)/libmlx.a:
	$(MAKE) -C $(MINILIBX_DIR)

$(OBJ_DIR):
	@echo "$(BLUE)[fractol] Creando directorio de objetos...$(NC)"
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)[fractol] Compilando $<...$(NC)"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)[fractol] Compilando bonus $<...$(NC)"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "$(RED)[fractol] Limpiando objetos...$(NC)"
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	@echo "$(RED)[fractol] Eliminando ejecutable y archivo de modo...$(NC)"
	rm -f $(NAME)
	rm -f $(MODE_FILE)

re: fclean all

.PHONY: all mandatory bonus re_mandatory re_bonus clean fclean re
