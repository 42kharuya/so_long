/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_img_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:22:51 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/27 15:22:53 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_img	init_img_info_xpm(void *mlx)
{
	t_img	img_info;
	int		w;
	int		h;

	img_info.p = mlx_xpm_file_to_image(mlx, "./src/imgs/p.xpm", &w, &h);
	img_info.c = mlx_xpm_file_to_image(mlx, "./src/imgs/c.xpm", &w, &h);
	img_info.e = mlx_xpm_file_to_image(mlx, "./src/imgs/e.xpm", &w, &h);
	img_info.w = mlx_xpm_file_to_image(mlx, "./src/imgs/w.xpm", &w, &h);
	img_info.s = mlx_xpm_file_to_image(mlx, "./src/imgs/s.xpm", &w, &h);
	return (img_info);
}

static void	init_img_info_buff(t_img *img_info)
{
	int	l_bytes;
	int	p_bits;
	int	e;

	img_info->buff_p = mlx_get_data_addr(img_info->p, &p_bits, &l_bytes, &e);
	img_info->buff_c = mlx_get_data_addr(img_info->c, &p_bits, &l_bytes, &e);
	img_info->buff_e = mlx_get_data_addr(img_info->e, &p_bits, &l_bytes, &e);
	img_info->buff_s = mlx_get_data_addr(img_info->s, &p_bits, &l_bytes, &e);
	img_info->buff_w = mlx_get_data_addr(img_info->w, &p_bits, &l_bytes, &e);
	return ;
}

t_img	init_img_info(void *mlx, t_map map_info)
{
	t_img	img_info;
	int		w;
	int		h;

	img_info = init_img_info_xpm(mlx);
	init_img_info_buff(&img_info);
	w = map_info.horizontal * 64;
	h = map_info.vertical * 64;
	img_info.img = mlx_new_image(mlx, w, h);
	return (img_info);
}
