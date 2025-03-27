/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:23:35 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/27 15:23:37 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	get_dst_x(int p_x, int vector)
{
	int	dst_x;

	dst_x = 0;
	if (vector == W)
		dst_x = p_x;
	else if (vector == A)
		dst_x = p_x - 1;
	else if (vector == S)
		dst_x = p_x;
	else if (vector == D)
		dst_x = p_x + 1;
	return (dst_x);
}

static int	get_dst_y(int p_y, int vector)
{
	int	dst_y;

	dst_y = 0;
	if (vector == W)
		dst_y = p_y - 1;
	else if (vector == A)
		dst_y = p_y;
	else if (vector == S)
		dst_y = p_y + 1;
	else if (vector == D)
		dst_y = p_y;
	return (dst_y);
}

void	window_move(t_all *all, int vector, int p_x, int p_y)
{
	char	**map;
	int		dst_x;
	int		dst_y;

	dst_x = get_dst_x(p_x, vector);
	dst_y = get_dst_y(p_y, vector);
	map = all->map_info->map;
	if (map[dst_y][dst_x] == '1'
		|| (map[dst_y][dst_x] == 'E' && (all->map_info->c_count) > 0))
		return ;
	else if (map[dst_y][dst_x] == 'C')
		(all->map_info->c_count)--;
	else if (map[dst_y][dst_x] == 'E' && (all->map_info->c_count) == 0)
	{
		map[dst_y][dst_x] = map[p_y][p_x];
		map[p_y][p_x] = '0';
		print_message_success(all);
	}
	map[dst_y][dst_x] = map[p_y][p_x];
	map[p_y][p_x] = '0';
	all->map_info->p_info.x = dst_x;
	all->map_info->p_info.y = dst_y;
	window_set_element(*(all->img_info), *(all->map_info));
	mlx_put_image_to_window(all->vars->mlx, all->vars->win,
		all->img_info->img, 0, 0);
}
