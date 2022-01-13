/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <ounejjarmehdi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:47:05 by elounejj          #+#    #+#             */
/*   Updated: 2022/01/13 16:44:19 by elounejj         ###   ########.fr       */
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

int	g_move;

typedef struct s_game {
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectible;
	int		collectible_x;
	int		collectible_y;
	int		exit_x;
	int		exit_y;
	void	*window;
	void	*ptr;
	void	*walls;
	void	*door;
	void	*collec;
	void	*player;
	void	*floor;
}	t_game;

enum {
	KEY_ESC = 53,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_Q = 12
};

char	*get_ext(char *filename);
int		first_and_last(char *str);
char	*get_next_line(int fd);
char	*ft_free(char **adr_str);
char	*get_line(ssize_t readr, char **str_input);
void	ft_join_and_free(char **str, void *buf);
int		check_map_ext(char *filname);
char	*get_map_caracters(char *map);
char	*raise_error(void);
void	free_tab(char **tab);
int		line_all_ones(char *line, char one);
int		found(char *s, char c);
int		tab_length(char **arr);
int		check_length_walls(char **map);
char	**check_map(char *map);
void	draw_img(t_game *game, int i, int j, void *img);
int		player_moves(int key, t_game *game);
int		red_cross(t_game *game);
void	window_size(t_game *game);
void	draw_floor(t_game *game, void *img);
void	draw_assets(t_game *game, void *img, char asset);
void	render_assets(t_game *game);
void	get_position(t_game *game, int *x, int *y, char asset);
int		count_collectibles(t_game *game);
int		key_handler(int key, t_game *game);

#endif
