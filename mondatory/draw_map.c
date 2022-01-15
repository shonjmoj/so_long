/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <ounejjarmehdi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:15:33 by elounejj          #+#    #+#             */
/*   Updated: 2022/01/15 11:54:14 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img(t_game *game, int i, int j, void *img)
{
	mlx_put_image_to_window(game->ptr, game->window, img, j * 32, i * 32);
}

void	draw_floor(t_game *game, void *img)
{
	int	i;
	int	j;

	i = 0;
	window_size(game);
	while (i < game->height)
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

void	draw_assets(t_game *game, void *img, char asset)
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
				draw_img(game, i, j, img);
			j++;
		}
		i++;
	}
}

void	render_game(t_game *game)
{
	game->floor = mlx_xpm_file_to_image(game->ptr, \
			"../Assets/Texture/floor.xpm", &game->width, &game->height);
	game->walls = mlx_xpm_file_to_image(game->ptr, \
			"../Assets/Texture/wall.xpm", &game->width, &game->height);
	game->door = mlx_xpm_file_to_image(game->ptr, \
			"../Assets/Texture/Door.xpm", &game->width, &game->height);
	game->collec = mlx_xpm_file_to_image(game->ptr, \
			"../Assets/Texture/COLEC.xpm", &game->width, &game->height);
	game->player = mlx_xpm_file_to_image(game->ptr, \
			"../Assets/Texture/Player.xpm", &game->width, &game->height);
}

void	render_assets(t_game *game)
{
	draw_floor(game, game->floor);
	draw_assets(game, game->walls, '1');
	draw_assets(game, game->door, 'E');
	draw_assets(game, game->collec, 'C');
	draw_assets(game, game->player, 'P');
}
