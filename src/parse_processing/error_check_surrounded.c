/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_surrounded.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:22:41 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/27 15:22:43 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	horizontal_check(char **map, int vertical)
{
	int	i;
	int	first_row;
	int	last_row;

	first_row = 0;
	i = -1;
	while (map[first_row][++i] != '\0')
	{
		if (map[first_row][i] != '1')
		{
			ft_free_map(map);
			print_message_parse_error(MAP_SURROUNDED_ERROR);
		}
	}
	last_row = vertical - 1;
	i = -1;
	while (map[last_row][++i] != '\0')
	{
		if (map[last_row][i] != '1')
		{
			ft_free_map(map);
			print_message_parse_error(MAP_SURROUNDED_ERROR);
		}
	}
	return ;
}

static void	vertical_check(char **map, int horizotal)
{
	int	i;
	int	first_column;
	int	last_column;

	first_column = 0;
	i = -1;
	while (map[++i] != NULL)
	{
		if (map[i][first_column] != '1')
		{
			ft_free_map(map);
			print_message_parse_error(MAP_SURROUNDED_ERROR);
		}
	}
	last_column = horizotal - 1;
	i = -1;
	while (map[++i] != NULL)
	{
		if (map[i][last_column] != '1')
		{
			ft_free_map(map);
			print_message_parse_error(MAP_SURROUNDED_ERROR);
		}
	}
	return ;
}

void	error_check_surrounded(t_map map)
{
	horizontal_check(map.map, map.vertical);
	vertical_check(map.map, map.horizontal);
}
