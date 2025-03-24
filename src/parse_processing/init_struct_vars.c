#include "../../includes/so_long.h"

t_vars	init_struct_vars(t_map map_info)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, map_info.horizontal * 64, map_info.vertical * 64, "so_long");
	return (vars);
}
