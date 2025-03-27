/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:22:45 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/27 15:22:47 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_all	init_struct_all(t_vars *vars, t_map *map, t_img *img)
{
	t_all	all;

	all.vars = vars;
	all.map_info = map;
	all.img_info = img;
	return (all);
}
