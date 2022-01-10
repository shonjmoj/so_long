#ifndef  SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1000

#include "mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

enum {
	KEY_ESC = 53,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13
};

char	*get_next_line(int fd);
char	*ft_free(char **adr_str);
char	*get_line(ssize_t readr, char **str_input);
void	ft_join_and_free(char **str, void *buf);
int		check_map_ext(char* filname);
char	*get_map_caracters(char *map);

#endif
