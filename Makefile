CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./inc -I./minilibx -I./libft -I./ft_printf

LIB_DIRS = libft ft_printf minilibx
LIBS = -L./minilibx -L./libft -L./ft_printf -lmlx -lft -lftprintf -lXext -lX11 -lm

SRC_DIR = src
BONUS_DIR = bonus
OBJ_DIR = obj
OBJ_SRC_DIR = $(OBJ_DIR)/src
OBJ_BONUS_DIR = $(OBJ_DIR)/bonus

SRCS = main.c draw.c utils.c
OBJS = $(SRCS:%.c=$(OBJ_SRC_DIR)/%.o)

BONUS_SRCS = main_bonus.c draw_bonus.c
BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJ_BONUS_DIR)/%.o)

NAME = fractol
BONUS_NAME = fractol_bonus

all: $(LIBS) $(NAME)

$(LIBS): $(LIB_DIRS)
	@for dir in $(LIB_DIRS); do \
		$(MAKE) -C $$dir || exit 1; \
	done

$(NAME): $(OBJS) $(LIB_DIRS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIB_DIRS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) $(LIBS)

$(OBJ_SRC_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_SRC_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c | $(OBJ_BONUS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_SRC_DIR) $(OBJ_BONUS_DIR):
	mkdir -p $@

$(LIB_DIRS):
	make -C $@

clean:
	rm -rf $(OBJ_DIR)
	@make -C libft clean
	@make -C ft_printf clean
	@make -C minilibx clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@make -C libft fclean
	@make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re bonus
