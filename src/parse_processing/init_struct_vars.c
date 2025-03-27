/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:23:12 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/27 15:23:14 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_vars	init_vars(t_map map)
{
	t_vars	vars;
	int		size_x;
	int		size_y;

	vars.mlx = mlx_init();
	size_x = map.horizontal * 64;
	size_y = map.vertical * 64;
	vars.win = mlx_new_window(vars.mlx, size_x, size_y, "so_long");
	return (vars);
}
