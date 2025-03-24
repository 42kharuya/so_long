#include "../../includes/so_long.h"

static t_img	init_struct_img_info_xpm(void *mlx)
{
	t_img	img_info;
	int		width;
	int		height;

	img_info.player = mlx_xpm_file_to_image(mlx, "./src/imgs/player.xpm", &width, &height);
	img_info.collectible = mlx_xpm_file_to_image(mlx, "./src/imgs/collectible.xpm", &width, &height);
	img_info.exit = mlx_xpm_file_to_image(mlx, "./src/imgs/exit.xpm", &width, &height);
	img_info.wall = mlx_xpm_file_to_image(mlx, "./src/imgs/wall.xpm", &width, &height);
	img_info.space = mlx_xpm_file_to_image(mlx, "./src/imgs/space.xpm", &width, &height);
	return (img_info);
}

static void	init_struct_img_info_buffer(t_img *img_info)
{
	int 	line_bytes;
	int		pixel_bits;
	int		endian;

	img_info->buffer_player = mlx_get_data_addr(img_info->player, &pixel_bits, &line_bytes, &endian);
	img_info->buffer_collectible = mlx_get_data_addr(img_info->collectible, &pixel_bits, &line_bytes, &endian);
	img_info->buffer_exit = mlx_get_data_addr(img_info->exit, &pixel_bits, &line_bytes, &endian);
	img_info->buffer_space = mlx_get_data_addr(img_info->space, &pixel_bits, &line_bytes, &endian);
	img_info->buffer_wall = mlx_get_data_addr(img_info->wall, &pixel_bits, &line_bytes, &endian);
	return ;
}

t_img	init_struct_img_info(void *mlx, t_map map_info)
{
	t_img	img_info;

	img_info = init_struct_img_info_xpm(mlx);
	init_struct_img_info_buffer(&img_info);
	img_info.img =  mlx_new_image(mlx, map_info.horizontal * 64, map_info.vertical * 64);
	return (img_info);
}