CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long.a

SRC = errors.c \
		get_next_line.c 

OBJ = ${SRC:.c=.o}

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
	rm -rf so_long a.out $(NAME)

re : fclean all