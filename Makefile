NAME = fdf

SRC = fdf.c event_func.c generator_funcs.c draw.c

SRC_DIR = src/

OBJ = $(SRC:.c=.o)

LIB = libs/libft/

MLX = libs/minilibx/

OPTS = -Wall -Werror -Wextra

all:
	@make -C $(LIB)
	@gcc -c $(addprefix $(SRC_DIR), $(SRC)) $(OPTS) -Iincludes -Ilibs/libft/includes
	@gcc -g -o $(NAME) $(OBJ) $(LIB)libftprintf.a $(MLX)libmlx.a -lXext -lX11
#	@gcc -g -o $(NAME) $(OBJ) $(LIB)libftprintf.a $(MLX)libmlx.a -framework OpenGL -framework AppKit

$(NAME): all

clean:
	@make clean -C $(LIB)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)

re: fclean all
