#include "so_long.h"

static char	*get_ext(char *filename)
{
	int		i;
	int		j;
	char	*ext;

	i = 0;
	ext = NULL;
	j = ft_strlen(filename);
	while(filename[j - 1] >= 0)
	{
		if (filename[j - 1] == '.')
		{
			j--;
			break;
		}
		j--;
	}
	ext = malloc(sizeof(char) * (j + 2));
	while(filename[i + j])
	{
		ext[i] = filename[i + j];
		i++;
	}
	ext[i] = '\0';
	return (ext);
}

int	check_map_ext(char* filname)
{
	if (ft_strncmp(".ber", get_ext(filname), ft_strlen(".ber")) == 0)
		return (1);
	else
		return (0);
}

char	*get_map_caracters(char *map)
{
	char	*line;
	char	*caracters;
	int		i;
	int		fd_map;

	i = 0;
	line = NULL;
	fd_map = open(map, O_RDONLY);
	caracters = NULL;
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

int	check_map_caracters(char *caracters)
{
	if (ft_strchr(caracters, 'P') && ft_strchr(caracters, 'C') && ft_strchr(caracters, 'E'))
		return (1);
	return (0);
}

int main ()
{
	char *str = get_map_caracters("map.ber");
	printf("%s\n", str);
	free(str);
}