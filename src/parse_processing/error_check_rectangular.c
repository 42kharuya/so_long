/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_rectangular.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:22:37 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/27 15:22:38 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	error_check_rectangular(char **map)
{
	int		i;
	size_t	pre_length;

	i = 0;
	pre_length = ft_strlen(map[i]);
	i++;
	while (map[i])
	{
		if (ft_strlen(map[i]) != pre_length)
		{
			ft_free_map(map);
			print_message_parse_error(RECTANGULAR_ERROR);
		}
		i++;
	}
	return ;
}
