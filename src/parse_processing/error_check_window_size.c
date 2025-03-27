#include "../../includes/so_long.h"

void	error_check_vertical_size(int vertical)
{
	if (vertical > 32)
		print_message_parse_error(WINDOW_SIZE_ERROR);
	return ;
}

void	error_check_horizontal_size(int horizontal, char **map)
{
	if (horizontal > 60)
	{
		ft_free_map(map);
		print_message_parse_error(WINDOW_SIZE_ERROR);
	}
	return ;
}
