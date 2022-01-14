CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = mondatory/so_long.a

SRC = mondatory/errors.c \
		mondatory/get_next_line.c \
		mondatory/check_map_utils.c \
		mondatory/check_map_utils2.c \
		mondatory/check_map.c \
		mondatory/draw_map.c \
		mondatory/player_moves.c

# BNS = bonus/errors.c \ 
# 		bonus/get_next_line.c \
# 		bonus/check_map_utils.c \
# 		bonus/check_map_utils2.c \
# 		bonus/check_map.c \
# 		bonus/draw_map.c \
# 		bonus/player_moves.c

# SO_LONG
# 	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit game.c

OBJ = ${SRC:.c=.o}
# B_OBJ = ${BNS:.c=.o}

$(NAME) : $(OBJ)
	cd libft && make
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

%.o : %.c so_long.h
	$(CC) $(CFLAGS) -o $@ -c $<


clean :
	cd libft && make clean
	rm -rf $(OBJ)

fclean : clean
	cd libft && make fclean
	rm -rf so_long mondatory/a.out $(NAME)

re : fclean all