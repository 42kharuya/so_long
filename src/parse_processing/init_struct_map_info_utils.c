/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_map_info_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:22:57 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/27 15:22:59 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**init_map_info_map(char *map_path, int vertical)
{
	int		fd;
	int		i;
	char	**map;

	map = (char **)ft_calloc(sizeof(char *), vertical + 1);
	if (!map)
		print_message_func_error(MALLOC_ERROR);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		print_message_func_error(OPEN_ERROR);
	i = 0;
	while (i < vertical)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[vertical] = NULL;
	if (close(fd) == -1)
		print_message_func_error(CLOSE_ERROR);
	return (map);
}

int	init_map_info_vertical(char *map_path)
{
	int		fd;
	int		vertical;
	char	*str;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		print_message_func_error(OPEN_ERROR);
	vertical = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free (str);
		vertical++;
	}
	if (close(fd) == -1)
		print_message_func_error(CLOSE_ERROR);
	return (vertical);
}

int	init_map_info_c(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

char	**init_map_info_map_v_init(t_map map_info)
{
	int		i;
	char	**map_v;

	map_v = (char **)malloc(sizeof(char *) * (map_info.vertical + 1));
	if (!map_v)
	{
		ft_free_map(map_info.map);
		print_message_func_error(MALLOC_ERROR);
	}
	i = 0;
	while (i < map_info.vertical)
	{
		map_v[i] = ft_substr(map_info.map[i], 0, ft_strlen(map_info.map[i]));
		if (!map_v[i])
		{
			ft_free_map(map_info.map);
			print_message_func_error(MALLOC_ERROR);
		}
		i++;
	}
	map_v[i] = NULL;
	return (map_v);
}

void	init_map_info_map_v(char **map_v, int x, int y)
{
	if (map_v[y][x] == '1')
		return ;
	else
		map_v[y][x] = 'V';
	if (map_v[y - 1][x] != 'V')
		init_map_info_map_v(map_v, x, y - 1);
	if (map_v[y + 1][x] != 'V')
		init_map_info_map_v(map_v, x, y + 1);
	if (map_v[y][x - 1] != 'V')
		init_map_info_map_v(map_v, x - 1, y);
	if (map_v[y][x + 1] != 'V')
		init_map_info_map_v(map_v, x + 1, y);
	return ;
}
