NAME = cub3D

CC = gcc

CFLAGS = -O3 -Wall -Wextra -Werror

MLX = libmlx

LIBFT = libft/libft.a

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = cub3D.h

FUNCTIONS =	main \
			key \
			key_dop \
			player \
			parser \
			parser_dop \
			raycasting \
			raycasting_dop \
			screen \
			sprite \
			sprite_sort \
			sprite_malloc \
			texture \
			utilities \
			error \
			start_game \
			gnl/get_next_line \
			gnl/get_next_line_utils \

OBJ = $(patsubst %,%.o,$(FUNCTIONS))

SRC = $(patsubst %,%.c,$(FUNCTIONS))

.PHONY: all clean fclean re

all: $(NAME)
$(NAME):	$(OBJ)
			make -C ./libmlx
			make -C ./libft
			$(CC) -o $(NAME) -L $(MLX) $(LXFLAGS) $(LIBFT) $(OBJ)

clean:
	rm -rf $(OBJ) $(B_OBJ)
	rm -f screen.bmp

fclean: clean

			@make clean -C ./libmlx
			@make clean -C ./libft
			$(RM) libft.a
			$(RM) libmlx.a
			rm -f $(NAME)

re: fclean all
