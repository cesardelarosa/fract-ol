CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./minilibx -lmlx -framework OpenGL -framework AppKit
SRC = $(wildcard src/*.c)
INCLUDE = -I./include -I./minilibx
OBJ = $(SRC:.c=.o)
NAME = fractol

all: $(NAME) minilibx

minilibx:
	make -C minilibx

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	rm -f -C minilibx

.PHONY: all clean fclean re
