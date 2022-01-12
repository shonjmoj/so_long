#include "so_long.h"


int deal_key(int key, t_game *game)
{
	if (key == KEY_A)
		ft_putendl_fd("A", 0);
	else if (key == KEY_W)
		ft_putendl_fd("W", 0);
	else if (key == KEY_S)
		ft_putendl_fd("S", 0);
	else if (key == KEY_D)
		ft_putendl_fd("D", 0);
	else if (key == KEY_ESC || key == KEY_Q)
		exit(0);
	return (0);
}

int	red_cross(t_game *game)
{
	mlx_destroy_window(game->ptr, game->window);
	exit(0);
}


int main() {
	t_game	game;


	game.ptr = mlx_init();
	game.window= mlx_new_window(game.ptr, 1000, 500, "so_long");
	mlx_pixel_put(game.ptr, game.window ,1000, 500, 0xFFFFFF);
	mlx_hook(game.window, 2, 0, deal_key, &game);
	mlx_hook(game.window, 17, 0, red_cross, &game);
	mlx_loop(game.ptr);
}