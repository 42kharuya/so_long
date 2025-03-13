#include "../../includes/so_long.h"

static char **init_struct_map_info_map(char *map_path, int vertical)
{
	int		fd;
	int		i;
	char	**map;

	map = (char **)ft_calloc(sizeof(char *), vertical + 1);
	if (!map)
		error_check_print(MALLOC_ERROR);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error_check_print(OPEN_ERROR);
	i = 0;
	while (i < vertical)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[vertical] = NULL;
	if (close(fd) == -1)
		error_check_print(CLOSE_ERROR);
	return (map);
}

static int	init_struct_map_info_vertical(char *map_path)
{
	int		fd;
	int		vertical;
	char	*str;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error_check_print(OPEN_ERROR);
	vertical = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		free (str);
		vertical++;
	}
	if (close(fd) == -1)
		error_check_print(CLOSE_ERROR);
	return (vertical);
}

static int	init_struct_map_info_collectible(char **map)
{
	int	i;
	int	j;
	int	collectible;

	i = 0;
	collectible = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	return (collectible);
}

t_map	init_struct_map_info(char *map_path)
{
	t_map map_info;

	map_info = init_struct_initial();
	map_info.vertical = init_struct_map_info_vertical(map_path);
	map_info.map = init_struct_map_info_map(map_path, map_info.vertical);
	map_info.horizontal = ft_strlen(map_info.map[0]);
	map_info.collectible_count = init_struct_map_info_collectible(map_info.map);
	return (map_info);
}
