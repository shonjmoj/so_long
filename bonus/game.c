#include "so_long.h"

int count_collectibles(t_game *game)
{
	int i;
	int j;
	int count;
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

void draw_assets(t_game *game, void *img, char asset)
{
	int i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == asset)
				draw_img(game, i, j, img);
			j++;
		}
		i++;
	}
}

void render_game(t_game *game, int width, int height)
{
	game->floor = mlx_xpm_file_to_image(game->ptr, "Assets/Texture/floor.xpm", &game->width, &game->height);
	game->walls = mlx_xpm_file_to_image(game->ptr, "Assets/Texture/wall.xpm", &game->width, &game->height);
	game->door = mlx_xpm_file_to_image(game->ptr, "Assets/Texture/Door.xpm", &game->width, &game->height);
	game->collec = mlx_xpm_file_to_image(game->ptr, "Assets/Texture/COLEC.xpm", &game->width, &game->height);
	game->player = mlx_xpm_file_to_image(game->ptr, "Assets/Texture/Player.xpm", &game->width, &game->height);
}

void render_assets(t_game *game)
{
	draw_floor(game, game->floor);
	draw_assets(game, game->walls, '1');
	draw_assets(game, game->door, 'E');
	draw_assets(game, game->collec, 'C');
	draw_assets(game, game->player, 'P');
}

int main()
{
	t_game game;

	g_move = 0;
	game.map = check_map("map.ber");
	game.ptr = mlx_init();
	window_size(&game);
	game.player_x = 0;
	game.player_y = 0;
	game.collected = 0;
	game.C = count_collectibles(&game);
	game.window = mlx_new_window(game.ptr, game.width * 32, game.height * 32, "so_long");
	render_game(&game, game.width, game.height);
	render_assets(&game);
	get_position(&game, &game.player_x, &game.player_y, 'P');
	get_position(&game, &game.exit_x, &game.exit_y, 'E');
	get_position(&game, &game.collectible_x, &game.collectible_y, 'C');
	mlx_hook(game.window, 2, 0, key_handler, &game);
	mlx_hook(game.window, 17, 0, red_cross, &game);
	mlx_loop(game.ptr);
	// printf("c = %d || x = %d || y = %d\n", game.collectible, game.player_x, game.player_y);
}