#include "../../includes/so_long.h"

void	error_check_playble(t_map map)
{
	int	i;
	int	j;

	i = -1;
	while (map.map_v[++i] != NULL)
	{
		j = -1;
		while (map.map_v[i][++j] != '\0')
		{
			if (map.map_v[i][j] == 'C')
			{
				ft_free_map(map.map);
				ft_free_map(map.map_v);
				print_message_parse_error(PLAYBLE_COLLECTIVE_ERROR);
			}
			if (map.map_v[i][j] == 'E')
			{
				ft_free_map(map.map);
				ft_free_map(map.map_v);
				print_message_parse_error(PLAYBLE_EXIT_ERROR);
			}
		}
	}
	return ;
}
