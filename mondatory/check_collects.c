/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <ounejjarmehdi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:41:48 by elounejj          #+#    #+#             */
/*   Updated: 2022/01/15 11:57:49 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectibles(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
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
