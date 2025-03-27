/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:23:26 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/27 15:23:28 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map_info;
	t_img	img_info;
	t_vars	vars;
	t_all	all;

	if (argc != 2)
		print_message_parse_error(NUMBER_OF_ARGUMENT_ERROR);
	map_info = init_map_info(argv[1]);
	vars = init_vars(map_info);
	img_info = init_img_info(vars.mlx, map_info);
	all = init_struct_all(&vars, &map_info, &img_info);
	window_set_element(img_info, map_info);
	mlx_put_image_to_window(vars.mlx, vars.win, img_info.img, 0, 0);
	mlx_hook(vars.win, 17, 1L << 0, ft_free, &all);
	mlx_key_hook(vars.win, key_hook, &all);
	mlx_loop(vars.mlx);
	return (0);
}
