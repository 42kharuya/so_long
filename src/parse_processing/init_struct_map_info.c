#include "../../includes/so_long.h"

t_map	init_map_info(char *map_path)
{
	t_map	map_info;

	error_check_path_extension(map_path);
	map_info.vertical = init_map_info_vertical(map_path);
	map_info.map = init_map_info_map(map_path, map_info.vertical);
	error_check_rectangular(map_info.map);
	error_check_element(map_info.map);
	map_info.horizontal = ft_strlen(map_info.map[0]);
	error_check_surrounded(map_info);
	map_info.c_count = init_map_info_c(map_info.map);
	map_info.p_info = init_struct_p_info(map_info.map);
	map_info.map_v = init_map_info_map_v_init(map_info);
	init_map_info_map_v(map_info.map_v, map_info.p_info.x, map_info.p_info.y);
	error_check_playble(map_info);
	return (map_info);
}
