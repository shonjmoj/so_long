/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <ounejjarmehdi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:15:33 by elounejj          #+#    #+#             */
/*   Updated: 2022/01/12 17:20:42 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int deal_key(int key)
{
	if (key == KEY_A)
		ft_putendl_fd("A", 0);
	else if (key == KEY_W)
		ft_putendl_fd("W", 0);
	else if (key == KEY_S)
		ft_putendl_fd("S", 0);
	else if (key == KEY_D)
		ft_putendl_fd("D", 0);
	else if (key == KEY_ESC || key == KEY_Q)
		exit(0);
	return (0);
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

void	draw_map(t_game *game, void *img)
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
