NAME = fdf

SRC = fdf.c event_func.c generator_funcs.c draw.c ft_save_map.c \
	  transform_img.c rotate.c translate.c scale.c tester.c

SRC_DIR = src/

OBJ = $(SRC:.c=.o)

LIB = libs/libft/

MLX = libs/minilibx/

OPTS = -Wall -Werror -Wextra

ifeq "$(shell uname -s)" "Darwin"
	MLX_LIB := -lmlx -framework OpenGL -framework AppKit
else
	MLX_LIB := $(MLX)libmlx.a -lXext -lX11 -lm
endif

all:
	@make -C $(LIB)
	@gcc -c $(addprefix $(SRC_DIR), $(SRC)) $(OPTS) -Iincludes -I$(LIB)includes -I$(MLX)
	@gcc -g -o $(NAME) $(OBJ) $(LIB)libftprintf.a $(MLX_LIB)

$(NAME): all

clean:
	@make clean -C $(LIB)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)

re: fclean all
