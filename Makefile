COMPILE := @gcc -g -o $(NAME) $(OBJ) $(LIB)libftprintf.a $(MLX_LIB)

ifeq "$(shell uname -o)" "i1	"

NAME = fdf:

SRC = fdf.c event_func.c generator_funcs.c draw.c ft_save_map.c \
	  transform_img.c rotate.c translate.c scale.c tester.c

SRC_DIR = src/

OBJ = $(SRC:.c=.o)

LIB = libs/libft/

MLX = libs/minilibx/

OPTS = -Wall -Werror -Wextra

all:
	@make -C $(LIB)
	@gcc -c $(addprefix $(SRC_DIR), $(SRC)) $(OPTS) -Iincludes -I$(LIB)includes -I$(MLX)
#	@gcc -g -o $(NAME) $(OBJ) $(LIB)libftprintf.a $(MLX)libmlx.a -lXext -lX11 -lm
	@gcc -g -o $(NAME) $(OBJ) $(LIB)libftprintf.a -lmlx -framework OpenGL -framework AppKit

$(NAME): all

clean:
	@make clean -C $(LIB)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)

re: fclean all
