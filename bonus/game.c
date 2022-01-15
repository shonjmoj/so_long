/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <ounejjarmehdi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:55:02 by elounejj          #+#    #+#             */
/*   Updated: 2022/01/15 12:10:32 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(void)
{
	t_game	game;

	g_move = 0;
	game.map = check_map("map.ber");
	game.ptr = mlx_init();
	window_size(&game);
	game.player_x = 0;
	game.player_y = 0;
	game.collected = 0;
	game.sum_of_collects = count_collectibles(&game);
	game.window = mlx_new_window(game.ptr, \
								game.width * 32, game.height * 32, "so_long");
	render_game(&game);
	render_assets(&game);
	get_position(&game, &game.player_x, &game.player_y, 'P');
	get_position(&game, &game.exit_x, &game.exit_y, 'E');
	mlx_hook(game.window, 2, 0, key_handler, &game);
	mlx_hook(game.window, 17, 0, red_cross, &game);
	mlx_loop(game.ptr);
}
