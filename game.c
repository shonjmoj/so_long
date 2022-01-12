#include "so_long.h"

void	draw_assets(t_game *game, void *img, char asset)
{
	int	i;
	int	j;

	i = 0;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if (game->map[i][j] == asset)
				draw_img(game, i, j, img);
			j++;
		}
		i++;
	}
}

int main() {
	t_game	game;
	int width;
	int height;
	void	*img;
	void	*walls;
	void	*door;
	void	*colec;
	void	*player;

	game.map = check_map("map.ber");
	game.ptr = mlx_init();
	window_size(&game);
	game.window= mlx_new_window(game.ptr, game.width * 32, game.height * 32, "so_long");
	img = mlx_xpm_file_to_image(game.ptr, "Assets/Texture/floor.xpm", &width, &height);
	walls = mlx_xpm_file_to_image(game.ptr, "Assets/Texture/wall.xpm", &width, &height);
	door = mlx_xpm_file_to_image(game.ptr, "Assets/Texture/Door.xpm", &width, &height);
	colec = mlx_xpm_file_to_image(game.ptr, "Assets/Texture/COLEC.xpm", &width, &height);
	player = mlx_xpm_file_to_image(game.ptr, "Assets/Texture/Player.xpm", &width, &height);
	draw_map(&game, img);
	draw_assets(&game, walls, '1');
	draw_assets(&game, door, 'E');
	draw_assets(&game, colec, 'C');
	draw_assets(&game, player, 'P');
	mlx_hook(game.window, 2, 0, deal_key, &game);
	mlx_hook(game.window, 17, 0, red_cross, &game);
	mlx_loop(game.ptr);
}