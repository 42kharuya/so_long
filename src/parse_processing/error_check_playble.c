/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_playble.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:22:32 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/27 15:22:34 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
