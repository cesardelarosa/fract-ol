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

CC = cc
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
	    echo "[fractol] The mandatory version is already compiled."; \
	else \
	    $(MAKE) re_mandatory; \
	fi

bonus:
	@if [ -f $(MODE_FILE) ] && [ "$$(cat $(MODE_FILE))" = "bonus" ]; then \
	    echo "[fractol] The bonus version is already compiled."; \
	else \
	    $(MAKE) re_bonus; \
	fi

re_mandatory: $(OBJ_DIR) $(MANDATORY_OBJ) $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx.a
	@echo "$(BLUE)[fractol] Linking and generating the MANDATORY executable...$(NC)"
	$(CC) $(CFLAGS) $(MANDATORY_OBJ) -o $(NAME) $(LDFLAGS)
	@echo "mandatory" > $(MODE_FILE)
	@echo "$(GREEN)[fractol] MANDATORY compilation completed$(NC)"

re_bonus: $(OBJ_DIR) $(BONUS_OBJ) $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx.a
	@echo "$(BLUE)[fractol] Linking and generating the BONUS executable...$(NC)"
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(NAME) $(LDFLAGS)
	@echo "bonus" > $(MODE_FILE)
	@echo "$(GREEN)[fractol] BONUS compilation completed$(NC)"

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR) complete

$(MINILIBX_DIR)/libmlx.a:
	$(MAKE) -C $(MINILIBX_DIR)

$(OBJ_DIR):
	@echo "$(BLUE)[fractol] Creating objects directory...$(NC)"
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)[fractol] Compiling $<...$(NC)"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)[fractol] Compiling bonus $<...$(NC)"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "$(RED)[fractol] Cleaning object files...$(NC)"
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	@echo "$(RED)[fractol] Removing executable and mode file...$(NC)"
	rm -f $(NAME)
	rm -f $(MODE_FILE)

re: fclean all

.PHONY: all mandatory bonus re_mandatory re_bonus clean fclean re
