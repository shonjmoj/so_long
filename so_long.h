/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <ounejjarmehdi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:47:05 by elounejj          #+#    #+#             */
/*   Updated: 2022/01/11 19:54:20 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1000

# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

enum {
	KEY_ESC = 53,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13
};

char	*get_ext(char *filename);
int		first_and_last(char *str);
char	*get_next_line(int fd);
char	*ft_free(char **adr_str);
char	*get_line(ssize_t readr, char **str_input);
void	ft_join_and_free(char **str, void *buf);
int		check_map_ext(char *filname);
char	*get_map_caracters(char *map);
int		raise_error(void);
void	free_tab(char **tab);
int		line_all_ones(char *line);

#endif
