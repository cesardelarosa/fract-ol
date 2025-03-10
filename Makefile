NAME = fractol

INCLUDE_DIR = include
SRC_DIR = src
BONUS_DIR = bonus
OBJ_DIR = obj
LIBFT_DIR = libft
MINILIBX_DIR = minilibx

MANDATORY_SRC = main.c hooks.c parser.c draw.c math.c
MANDATORY_OBJ = $(MANDATORY_SRC:%.c=$(OBJ_DIR)/%.o)

BONUS_SRC = main_bonus.c hooks_bonus.c parser_bonus.c draw_bonus.c math_bonus.c math2_bonus.c info_bonus.c color_bonus.c
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
	@if [ ! -f $(NAME) ] || [ ! -f $(MODE_FILE) ] || [ "$$(cat $(MODE_FILE))" != "mandatory" ] || [ "$$(find $(SRC_DIR) -name '*.c' -newer $(NAME))" != "" ]; then \
	    $(MAKE) re_mandatory; \
	else \
	    printf "[fractol] The mandatory version is already compiled.\n"; \
	fi

bonus:
	@if [ ! -f $(NAME) ] || [ ! -f $(MODE_FILE) ] || [ "$$(cat $(MODE_FILE))" != "bonus" ] || [ "$$(find $(BONUS_DIR) -name '*.c' -newer $(NAME))" != "" ]; then \
	    $(MAKE) re_bonus; \
	else \
	    printf "[fractol] The bonus version is already compiled.\n"; \
	fi

re_mandatory: $(OBJ_DIR) $(MANDATORY_OBJ) $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx.a
	@printf "$(BLUE)[fractol] Linking and generating the MANDATORY executable...$(NC)\n"
	$(CC) $(CFLAGS) $(MANDATORY_OBJ) -o $(NAME) $(LDFLAGS)
	@printf "mandatory\n" > $(MODE_FILE)
	@printf "$(GREEN)[fractol] MANDATORY compilation completed$(NC)\n"

re_bonus: $(OBJ_DIR) $(BONUS_OBJ) $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx.a
	@printf "$(BLUE)[fractol] Linking and generating the BONUS executable...$(NC)\n"
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(NAME) $(LDFLAGS)
	@printf "bonus\n" > $(MODE_FILE)
	@printf "$(GREEN)[fractol] BONUS compilation completed$(NC)\n"

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR) complete

$(MINILIBX_DIR)/libmlx.a:
	$(MAKE) -C $(MINILIBX_DIR)

$(OBJ_DIR):
	@printf "$(BLUE)[fractol] Creating objects directory...$(NC)\n"
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "$(YELLOW)[fractol] Compiling $<...$(NC)\n"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c | $(OBJ_DIR)
	@printf "$(YELLOW)[fractol] Compiling bonus $<...$(NC)\n"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@printf "$(RED)[fractol] Cleaning object files...$(NC)\n"
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	@printf "$(RED)[fractol] Removing executable and mode file...$(NC)\n"
	rm -f $(NAME)
	rm -f $(MODE_FILE)

re: fclean all

.PHONY: all mandatory bonus re_mandatory re_bonus clean fclean re
