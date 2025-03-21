#include "../includes/so_long.h"

void	ft_free_map(char **map)
{
	int i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i] != NULL)
		free (map[i++]);
	free(map);
	return ;
}

void	ft_free(t_map *map_info)
{
	ft_free_map(map_info->map);
	ft_free_map(map_info->map_visitable);
}