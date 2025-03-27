/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_set_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:23:41 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/27 15:23:42 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	set_element(t_img img_info, char *buff_ele, int x, int y)
{
	int	elem_x;
	int	elem_y;
	int	pixel_element;
	int	pixel_map;
	int	l_bytes;

	l_bytes = img_info.l_bytes;
	elem_y = 0;
	while (elem_y < 64)
	{
		elem_x = 0;
		while (elem_x < 64)
		{
			pixel_element = (elem_y * 256) + (elem_x * 4);
			pixel_map = (((y * 64) + elem_y) * l_bytes)
				+ (((x * 64) + elem_x) * 4);
			img_info.buff_img[pixel_map + 0] = buff_ele[pixel_element + 0];
			img_info.buff_img[pixel_map + 1] = buff_ele[pixel_element + 1];
			img_info.buff_img[pixel_map + 2] = buff_ele[pixel_element + 2];
			img_info.buff_img[pixel_map + 3] = buff_ele[pixel_element + 3];
			elem_x++;
		}
		elem_y++;
	}
	return ;
}

static void	set_elements(t_map map_info, t_img img_info)
{
	char	**map;
	int		x;
	int		y;

	map = map_info.map;
	y = 0;
	while (y < (map_info.vertical))
	{
		x = 0;
		while (x < (map_info.horizontal))
		{
			if (map[y][x] == 'P')
				set_element(img_info, img_info.buff_p, x, y);
			else if (map[y][x] == 'C')
				set_element(img_info, img_info.buff_c, x, y);
			else if (map[y][x] == 'E')
				set_element(img_info, img_info.buff_e, x, y);
			else if (map[y][x] == '1')
				set_element(img_info, img_info.buff_w, x, y);
			else if (map[y][x] == '0')
				set_element(img_info, img_info.buff_s, x, y);
			x++;
		}
		y++;
	}
}

void	window_set_element(t_img img_info, t_map map_info)
{
	int		l_bytes;
	int		p_bits;
	int		en;

	img_info.buff_img = mlx_get_data_addr(img_info.img, &p_bits, &l_bytes, &en);
	img_info.l_bytes = l_bytes;
	set_elements(map_info, img_info);
	return ;
}
