CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft.a

all :
	cd libft && make

clean : 
	cd libft && make clean
	rm -rf $(OBJ)

fclean : clean
	cd libft && make fclean
	rm -rf so_long a.out

re : fclean all