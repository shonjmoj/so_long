/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <ounejjarmehdi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:44:40 by elounejj          #+#    #+#             */
/*   Updated: 2022/01/15 12:06:40 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_position(t_game *game, int *x, int *y, char asset)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == asset)
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
}

int	red_cross(t_game *game)
{
	mlx_destroy_window(game->ptr, game->window);
	exit(0);
}

int	key_handler(int key, t_game *game)
{
	collecting(game);
	if (key == KEY_ESC || key == KEY_Q || \
		(game->player_x == game->exit_x && \
		game->player_y == game->exit_y && \
		game->collected == game->sum_of_collects))
	{
		mlx_destroy_window(game->ptr, game->window);
		exit(0);
	}
	if (game->player_x == game->exit_x && \
		game->player_y == game->exit_y && \
		game->collected != game->sum_of_collects)
		player_moves(key, game, game->door);
	player_moves(key, game, game->floor);
	return (0);
}

void	window_size(t_game *game)
{
	game->height = 0;
	while (game->map[game->height])
	{
		game->width = 0;
		while (game->map[game->height][game->width])
			game->width++;
		game->height++;
	}
}
