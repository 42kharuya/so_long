#include "../includes/so_long.h"

t_all	init_struct_all(t_vars *vars, t_map *map, t_img *img)
{
	t_all	all;

	all.vars = vars;
	all.map_info = map;
	all.img_info = img;
	return (all);
}
