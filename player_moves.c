/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <ounejjarmehdi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:38:19 by elounejj          #+#    #+#             */
/*   Updated: 2022/01/13 16:09:31 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_moves(int key, t_game *game)
{
	if (key == KEY_D && game->map[game->player_x][game->player_y + 1] != '1')
	{
		draw_img(game, game->player_x, game->player_y, game->floor);
		draw_img(game, game->player_x, ++game->player_y, game->player);
	}
	else if (key == KEY_A && game->map[game->player_x][game->player_y - 1] != '1')
	{
		draw_img(game, game->player_x, game->player_y, game->floor);
		draw_img(game, game->player_x, --game->player_y, game->player);
	}
	else if (key == KEY_S && game->map[game->player_x + 1][game->player_y] != '1')
	{
		draw_img(game, game->player_x, game->player_y, game->floor);
		draw_img(game, ++game->player_x, game->player_y, game->player);
	}
	else if (key == KEY_W && game->map[game->player_x - 1][game->player_y] != '1')
	{
		draw_img(game, game->player_x, game->player_y, game->floor);
		draw_img(game, --game->player_x, game->player_y, game->player);
	}
	printf("c = %d\n", game->collectible);
	return (0);
}


int key_handler(int key, t_game *game)
{
	if (key == KEY_ESC || key == KEY_Q)
	{
		mlx_destroy_window(game->ptr, game->window);
		exit(0);
	}
	player_moves(key, game);
	return (0);
}