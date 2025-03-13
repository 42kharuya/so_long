#include "../../includes/so_long.h"

void	error_check(t_map map_info, char *path)
{
	error_check_rectangular(map_info.map);
	error_check_path_extension(path);
	error_check_element(map_info.map);
	error_check_surrounded(map_info.map, map_info.horizontal, map_info.vertical);
}