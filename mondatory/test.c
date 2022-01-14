#include "so_long.h"

int count_collectibles(t_game *game)
{
	int i;
	int j;

	i = 0;
	game->collectible = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
			{
				game->collectible++;
			}
			j++;
		}
		i++;
	}
	return (game->collectible);
}

int main()
{
	t_game game;
	game.map = check_map("map.ber");
	// position(&game, game.player_x, game.player_y);
	printf("c = %d", count_collectibles(&game));
}