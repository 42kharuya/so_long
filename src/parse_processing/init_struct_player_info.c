#include "../../includes/so_long.h"

static int	search_p_location_y(char **map)
{
	int	i;
	int	j;
	int	y;

	i = -1;
	y = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				y = i;
				return (y);
			}
		}
	}
	return (y);
}

static int	search_p_location_x(char **map)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	x = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				x = j;
				return (x);
			}
		}
	}
	return (x);
}

t_player	init_struct_p_info(char **map)
{
	t_player	p_info;
	int			x;
	int			y;

	x = search_p_location_x(map);
	y = search_p_location_y(map);
	p_info.x = x;
	p_info.y = y;
	return (p_info);
}
