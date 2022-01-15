CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = mondatory/so_long.a

BONUS = bonus/so_long_bonus.a

SRC = mondatory/errors.c \
		mondatory/get_next_line.c \
		mondatory/check_map_utils.c \
		mondatory/check_map_utils2.c \
		mondatory/check_collects.c \
		mondatory/key_handler.c \
		mondatory/check_map.c \
		mondatory/draw_map.c \
		mondatory/player_moves.c

BNS = bonus/errors.c \
		bonus/get_next_line.c \
		bonus/check_map_utils.c \
		bonus/check_map_utils2.c \
		bonus/check_collects.c \
		bonus/key_handler.c \
		bonus/check_map.c \
		bonus/draw_map.c \
		bonus/player_moves.c

OBJ = ${SRC:.c=.o}
B_OBJ = ${BNS:.c=.o}

$(NAME) : $(OBJ)
	cd libft && make
	ar rcs $(NAME) $(OBJ)

$(BONUS) : $(B_OBJ)
	cd libft && make
	ar rcs $(BONUS) $(OBJ)

all : $(NAME)

%.o : %.c so_long.h so_long_bonus.h
	$(CC) $(CFLAGS) -o $@ -c $<

bonus : $(NAME) $(B_OBJ)
	ar rcs $(BONUS) $(B_OBJ)

clean :
	cd libft && make clean
	rm -rf $(OBJ) $(B_OBJ)

fclean : clean
	cd libft && make fclean
	rm -rf so_long mondatory/a.out bonus/a.out $(NAME) $(BONUS)

re : fclean all