/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <ounejjarmehdi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:50:10 by elounejj          #+#    #+#             */
/*   Updated: 2022/01/11 20:00:41 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_ext(char *filname)
{
	char	*ext;

	ext = get_ext(filname);
	if (ft_strncmp(".ber", ext, ft_strlen(".ber")) == 0)
	{
		free(ext);
		return (1);
	}
	free(ext);
	return (0);
}

int	check_map_caracters(char *characters)
{
	if (ft_strchr(characters, 'P') && ft_strchr(characters, 'C') \
									&& ft_strchr(characters, 'E'))
		return (1);
	return (0);
}

int	check_map_rectangular(char *map)
{
	char	**arr;
	int		i;
	int		j;
	char	*characters;

	characters = get_map_caracters(map);
	arr = ft_split(characters, '\n');
	j = 0;
	i = ft_strlen(arr[0]);
	while (arr[j] != NULL)
		j++;
	if (i <= j)
	{
		free_tab(arr);
		free(characters);
		raise_error();
	}
	free_tab(arr);
	free(characters);
	return (1);
}

int	check_map_walls(char *map)
{
	char	**arr;
	char	*characters;
	int		i;
	int		j;

	i = 0;
	characters = get_map_caracters(map);
	arr = ft_split(characters, '\n');
	while (arr[i])
	{
		if (!first_and_last(arr[i]))
		{
			free(characters);
			free_tab(arr);
			raise_error();
			return (0);
		}
		i++;
	}
	free(characters);
	free_tab(arr);
	return (1);
}

int	check_map(char *map)
{
	int		i;
	char	**arr;
	char	*characters;

	i = 0;
	characters = get_map_caracters(map);
	arr = ft_split(characters, '\n');
	while (arr[i])
		i++;
	if (!line_all_ones(arr[0]) && !line_all_ones(arr[i - 1]))
	{
		free(characters);
		free_tab(arr);
		raise_error();
	}
	free(characters);
	free_tab(arr);
	return (1);
}

// int main()
// {
// 	printf("%d",check_map("map.ber"));
// }