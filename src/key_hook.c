/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:23:21 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/27 15:23:22 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_all *all)
{
	int	p_x;
	int	p_y;

	p_x = all->map_info->p_info.x;
	p_y = all->map_info->p_info.y;
	if (keycode == ESC)
		return (ft_free(all));
	else if (keycode == W || keycode == ALLOW_UP)
		window_move(all, W, p_x, p_y);
	else if (keycode == A || keycode == ALLOW_LEFT)
		window_move(all, A, p_x, p_y);
	else if (keycode == S || keycode == ALLOW_DOWN)
		window_move(all, S, p_x, p_y);
	else if (keycode == D || keycode == ALLOW_RIGHT)
		window_move(all, D, p_x, p_y);
	return (0);
}
