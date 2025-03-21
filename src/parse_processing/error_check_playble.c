#include "../../includes/so_long.h"

void	error_check_playble(t_map map_info)
{
	int	i;
	int	j;

	i = -1;
	while (map_info.map_visitable[++i] != NULL)
	{
		j = -1;
		while (map_info.map_visitable[i][++j] != '\0')
		{
			if (map_info.map_visitable[i][j] == 'C')
			{
				ft_free(&map_info);
				error_check_parse_print(PLAYBLE_COLLECTIVE_ERROR);
			}
			if (map_info.map_visitable[i][j] == 'E')
			{
				ft_free(&map_info);
				error_check_parse_print(PLAYBLE_EXIT_ERROR);
			}
		}
	}
	return ;
}