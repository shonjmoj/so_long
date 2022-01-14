/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <ounejjarmehdi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:38:19 by elounejj          #+#    #+#             */
/*   Updated: 2022/01/14 16:17:31 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int player_moves(int key, t_game *game, void *asset)
{
	if (key == KEY_D && game->map[game->player_x][game->player_y + 1] != '1')
	{
		printf("%d\n", ++g_move);
		draw_img(game, game->player_x, game->player_y, asset);
		draw_img(game, game->player_x, ++game->player_y, game->player);
	}
	else if (key == KEY_A && game->map[game->player_x][game->player_y - 1] != '1')
	{
		printf("%d\n", ++g_move);
		draw_img(game, game->player_x, game->player_y, asset);
		draw_img(game, game->player_x, --game->player_y, game->player);
	}
	player_moves2(key, game, asset);
	return (0);
}
int player_moves2(int key, t_game *game, void *asset)
{
	if (key == KEY_S && game->map[game->player_x + 1][game->player_y] != '1')
	{
		printf("%d\n", ++g_move);
		draw_img(game, game->player_x, game->player_y, asset);
		draw_img(game, ++game->player_x, game->player_y, game->player);
	}
	else if (key == KEY_W && game->map[game->player_x - 1][game->player_y] != '1')
	{
		printf("%d\n", ++g_move);
		draw_img(game, game->player_x, game->player_y, asset);
		draw_img(game, --game->player_x, game->player_y, game->player);
	}
	return (0);
}

int	collecting(t_game *game)
{
	if (game->map[game->player_x][game->player_y] == 'C')
	{
		game->collected++;
		game->map[game->player_x][game->player_y] = '0';
	}
	return (0);
}

int key_handler(int key, t_game *game)
{
	
	collecting(game);
	if (key == KEY_ESC || key == KEY_Q || (game->player_x == game->exit_x && game->player_y == game->exit_y && game->collected == game->C))
	{
		mlx_destroy_window(game->ptr, game->window);
		exit(0);
	}
	if (game->player_x == game->exit_x && game->player_y == game->exit_y && game->collected != game->C)
		player_moves(key, game, game->door);
	player_moves(key, game, game->floor);
	return (0);
}