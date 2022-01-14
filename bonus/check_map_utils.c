/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <ounejjarmehdi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:48:54 by elounejj          #+#    #+#             */
/*   Updated: 2022/01/12 13:14:45 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_ext(char *filename)
{
	int		i;
	int		j;
	char	*ext;

	i = 0;
	ext = NULL;
	j = ft_strlen(filename);
	while (filename[j - 1] >= 0)
	{
		if (filename[j - 1] == '.')
		{
			j--;
			break ;
		}
		j--;
	}
	ext = malloc(sizeof(char) * (j + 2));
	while (filename[i + j])
	{
		ext[i] = filename[i + j];
		i++;
	}
	ext[i] = '\0';
	return (ext);
}

int	check_map_ext(char *filname)
{
	char	*ext;

	ext = get_ext(filname);
	if (ft_strncmp(".ber", ext, ft_strlen(".ber")) != 0)
	{
		free(ext);
		return (0);
	}
	free(ext);
	return (1);
}

char	*get_map_caracters(char *map)
{
	char	*line;
	char	*characters;
	int		i;
	int		fd_map;

	i = 0;
	line = NULL;
	fd_map = open(map, O_RDONLY);
	characters = NULL;
	if (!check_map_ext(map))
		return (NULL);
	line = get_next_line(fd_map);
	while (line)
	{
		if (!characters)
			characters = ft_strdup(line);
		else
			ft_join_and_free(&characters, line);
		free(line);
		line = get_next_line(fd_map);
	}
	free(line);
	return (characters);
}

int	first_and_last(char *str)
{
	int	i;
	int	first;
	int	last;

	i = 0;
	first = str[0];
	last = str[ft_strlen(str) - 1];
	if (first == '1' && last == '1')
		return (1);
	return (0);
}

int	check_length_walls(char **map)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) > len || ft_strlen(map[i]) < len)
			return (0);
		i++;
	}
	return (1);
}
