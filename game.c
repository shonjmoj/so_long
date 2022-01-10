#include "so_long.h"


int deal_key(int key, void *param)
{
	if (key == KEY_A)
		ft_putendl_fd("A", 0);
	else if (key == KEY_W)
		ft_putendl_fd("W", 0);
	else if (key == KEY_S)
		ft_putendl_fd("S", 0);
	else if (key == KEY_D)
		ft_putendl_fd("D", 0);
	else if (key == KEY_ESC)
	{
		free(param);
		exit(0);
	}
	return (0);
}

int main() {
	void	*ptr;
	void	*window;


	ptr = mlx_init();
	window = mlx_new_window(ptr, 1000, 500, "so_long");
	mlx_pixel_put(ptr, window ,1000, 500, 0xFFFFFF);
	mlx_key_hook(window , deal_key, (void *)0);
	mlx_loop(ptr);
}