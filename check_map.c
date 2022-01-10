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