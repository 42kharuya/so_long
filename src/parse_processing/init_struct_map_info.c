#include "../../includes/so_long.h"

t_map	init_struct_map_info(char *map_path)
{
	t_map map_info;

	error_check_path_extension(map_path);
	map_info.vertical = init_struct_map_info_vertical(map_path);
	map_info.map = init_struct_map_info_map(map_path, map_info.vertical);
	error_check_rectangular(map_info.map);
	error_check_element(map_info.map);
	map_info.horizontal = ft_strlen(map_info.map[0]);
	error_check_surrounded(map_info.map, map_info.horizontal, map_info.vertical);
	map_info.collectible_count = init_struct_map_info_collectible(map_info.map);
	map_info.player_info = init_struct_player_info(map_info.map);
	map_info.map_visitable = init_struct_map_info_map_visitable_init(map_info);
	init_struct_map_info_map_visitable(map_info.map_visitable, map_info.player_info.x, map_info.player_info.y);
	error_check_playble(map_info.map_visitable);
	return (map_info);
}
