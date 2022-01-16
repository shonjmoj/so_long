/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <ounejjarmehdi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:47:14 by elounejj          #+#    #+#             */
/*   Updated: 2022/01/15 15:52:26 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_moves(t_game *game, int moves)
{
	if (game->moves)
	{
		free(game->moves);
		draw_assets(game, game->walls, '1');
	}
	game->moves = ft_itoa(moves);
	mlx_string_put(game->ptr, game->window, 5, 5, 0xf9ff00, game->moves);
	return (game->moves);
}
