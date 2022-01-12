/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <ounejjarmehdi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:33:45 by elounejj          #+#    #+#             */
/*   Updated: 2022/01/12 13:14:22 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	tab_length(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	is_found(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	line_all_ones(char *line, char one)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != one)
			return (0);
		i++;
	}
	return (1);
}
