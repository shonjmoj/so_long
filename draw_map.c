/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <ounejjarmehdi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:15:33 by elounejj          #+#    #+#             */
/*   Updated: 2022/01/13 16:08:27 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_position(t_game *game, int *x, int *y, char asset)
{
	int	i;
	int	j;

	i = 0;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
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

void draw_img(t_game *game, int i, int j, void *img)
{
	mlx_put_image_to_window(game->ptr, game->window, img, j * 32, i * 32);
}

void	draw_floor(t_game *game, void *img)
{
	int	i;
	int	j;

	i = 0;
	window_size(game);
	while(i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			draw_img(game, i, j, img);
			j++;
		}
		i++;
	}
}
