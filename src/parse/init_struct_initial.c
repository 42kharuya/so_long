#include "../../includes/so_long.h"

t_map	init_struct_initial(void)
{
	t_map	map_info;

	map_info.map = NULL;
	map_info.vertical = 0;
	map_info.horizontal = 0;
	return (map_info);
}