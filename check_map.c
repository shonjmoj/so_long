#include "so_long.h"

static char *get_ext(char *filename)
{
	int i;
	int j;
	char *ext;

	i = 0;
	ext = NULL;
	j = ft_strlen(filename);
	while (filename[j - 1] >= 0)
	{
		if (filename[j - 1] == '.')
		{
			j--;
			break;
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

int check_map_ext(char *filname)
{
	char *ext;

	ext = get_ext(filname);
	if (ft_strncmp(".ber", ext, ft_strlen(".ber")) == 0)
	{
		free(ext);
		return (1);
	}
	free(ext);
	return (0);
}

char *get_map_caracters(char *map)
{
	char *line;
	char *caracters;
	int i;
	int fd_map;

	i = 0;
	line = NULL;
	fd_map = open(map, O_RDONLY);
	caracters = NULL;
	if (!check_map_ext(map))
		return NULL;
	line = get_next_line(fd_map);
	while (line)
	{
		if (!caracters)
			caracters = ft_strdup(line);
		else
			ft_join_and_free(&caracters, line);
		free(line);
		line = get_next_line(fd_map);
	}
	free(line);
	return (caracters);
}

int check_map_caracters(char *caracters)
{
	if (ft_strchr(caracters, 'P') && ft_strchr(caracters, 'C') && ft_strchr(caracters, 'E'))
		return (1);
	return (0);
}

int check_map_rectangular(char *map)
{
	char **arr;
	int i;
	int j;
	char *caractere;

	caractere = get_map_caracters(map);
	arr = ft_split(caractere, '\n');
	j = 0;
	i = ft_strlen(arr[0]);
	while (arr[j] != NULL)
		j++;
	if (i <= j)
	{
		free_tab(arr);
		free(caractere);
		raise_error();
	}
	free_tab(arr);
	free(caractere);
	return (1);
}

int	first_and_last(char *str)
{
	int	i;
	int	first;
	int last;

	i = 0;
	first = str[0];
	last = str[ft_strlen(str) - 1];
	if (first == '1' && last == '1')
		return (1);
	return (0);
}

int check_map_walls(char *map)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	arr = ft_split(map, '\n');
	while(arr[i])
	{
		if (!first_and_last(arr[i]))
		{
			free_tab(arr);
			// raise_error();
			return (0);
		}
		i++;
	}
	free_tab(arr);
	return (1);
}

int main()
{
	int i = 0;
	printf("%d", check_map_walls("map.ber"));
}