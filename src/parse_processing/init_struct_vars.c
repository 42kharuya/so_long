#include "../../includes/so_long.h"

t_vars	init_vars(t_map map)
{
	t_vars	vars;
	int		size_x;
	int		size_y;

	vars.mlx = mlx_init();
	size_x = map.horizontal * 64;
	size_y = map.vertical * 64;
	vars.win = mlx_new_window(vars.mlx, size_x, size_y, "so_long");
	return (vars);
}
