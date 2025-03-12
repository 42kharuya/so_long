#include "sample.h"

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;

	(void)argc;
	(void)argv;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 360, "Hello world!");
	mlx_string_put(mlx, mlx_win, 100, 100, 0xFFFFFF00, "Hello world!");
	mlx_loop(mlx);
	return (0);
}
