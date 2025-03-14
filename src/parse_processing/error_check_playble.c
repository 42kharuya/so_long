#include "../../includes/so_long.h"

void	error_check_playble(char **map_visitable)
{
	int	i;
	int	j;

	i = -1;
	while (map_visitable[++i] != NULL)
	{
		j = -1;
		while (map_visitable[i][++j] != '\0')
		{
			if (map_visitable[i][j] == 'C')
				error_check_print(PLAYBLE_COLLECTIVE_ERROR);
			if (map_visitable[i][j] == 'E')
				error_check_print(PLAYBLE_EXIT_ERROR);
		}
	}
	return ;
}