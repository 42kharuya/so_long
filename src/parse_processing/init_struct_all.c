#include "../includes/so_long.h"

t_all	init_struct_all(t_vars *vars, t_map *map_info, t_img *img_info)
{
	t_all	all;

	all.vars = vars;
	all.map_info = map_info;
	all.img_info = img_info;
	return (all);
}
