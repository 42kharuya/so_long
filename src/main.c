#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map_info;
	t_img	img_info;
	t_vars	vars;
	t_all	all;

	if (argc != 2)
		error_check_parse_print(NUMBER_OF_ARGUMENT_ERROR);
	map_info = init_struct_map_info(argv[1]);
	vars = init_struct_vars(map_info);
	img_info = init_struct_img_info(vars.mlx, map_info);
	all = init_struct_all(&vars, &map_info, &img_info);
	window_set_element(img_info.img, img_info, map_info);
	mlx_put_image_to_window(vars.mlx, vars.win, img_info.img, 0, 0);
	mlx_hook(vars.win, 17, 1L << 0, ft_free, &all);
	mlx_key_hook(vars.win, key_hook, &all);
	mlx_loop(vars.mlx);
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_map 	map_info;
// 	int 	i;

// 	if (argc != 2)
// 		error_check_parse_print(NUMBER_OF_ARGUMENT_ERROR);
// 	map_info = init_struct_map_info(argv[1]);
// 	i = 0;
// 	while (map_info.map[i])
// 	{
// 		printf("map:%s\n", map_info.map[i]);
// 		i++;
// 	}
// 	i = 0;
// 	printf ("-----------------------------------------------\n");
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 320, 360, "so_long");
// 	ft_free(&map_info);
// 	return (0);
// }
