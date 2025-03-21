#include "../../includes/so_long.h"

char	**init_struct_map_info_map(char *map_path, int vertical)
{
	int		fd;
	int		i;
	char	**map;

	map = (char **)ft_calloc(sizeof(char *), vertical + 1);
	if (!map)
		error_check_parse_print(MALLOC_ERROR);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error_check_parse_print(OPEN_ERROR);
	i = 0;
	while (i < vertical)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[vertical] = NULL;
	if (close(fd) == -1)
		error_check_parse_print(CLOSE_ERROR);
	return (map);
}

int	init_struct_map_info_vertical(char *map_path)
{
	int		fd;
	int		vertical;
	char	*str;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error_check_parse_print(OPEN_ERROR);
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
		error_check_parse_print(CLOSE_ERROR);
	return (vertical);
}

int	init_struct_map_info_collectible(char **map)
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

char	**init_struct_map_info_map_visitable_init(t_map map_info)
{
	int i;
	char **map_visitable;

	map_visitable = (char **)malloc(sizeof(char *) * (map_info.vertical + 1));
	if (!map_visitable)
	{
		ft_free_map(map_info.map);
		error_check_parse_print(MALLOC_ERROR);
	}
	i = 0;
	while (i < map_info.vertical)
	{
		map_visitable[i] = ft_substr(map_info.map[i], 0, ft_strlen(map_info.map[i]));
		if (!map_visitable[i])
		{
			ft_free_map(map_info.map);
			error_check_parse_print(MALLOC_ERROR);
		}
		i++;
	}
	map_visitable[i] = NULL;
	return (map_visitable);
}

void	init_struct_map_info_map_visitable(char **map_visitable, int x, int y)
{
	if (map_visitable[y][x] == '1')
		return ;
	else
		map_visitable[y][x] = 'V';
	if (map_visitable[y - 1][x] != 'V')
		init_struct_map_info_map_visitable(map_visitable, x, y - 1);
	if (map_visitable[y + 1][x] != 'V')
		init_struct_map_info_map_visitable(map_visitable, x, y + 1);
	if (map_visitable[y][x - 1] != 'V')
		init_struct_map_info_map_visitable(map_visitable, x - 1, y);
	if (map_visitable[y][x + 1] != 'V')
		init_struct_map_info_map_visitable(map_visitable, x + 1, y);
	return ;
}
