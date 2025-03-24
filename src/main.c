#include "../includes/so_long.h"

t_vars	mlx_initializer(t_map map_info)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win =  mlx_new_window(vars.mlx, map_info.horizontal * 64, map_info.vertical * 64, "so_long");
	return (vars);
}

int key_hook(int keycode, t_all *all)
{
	printf ("key code:%d\n", keycode);
	if (keycode == 65307)
		return (ft_free(all));
	return (0);
}

t_all	all_initializer(t_vars *vars, t_map *map_info, t_img *img_info)
{
	t_all	all;

	all.vars = vars;
	all.map_info = map_info;
	all.img_info = img_info;
	return (all);
}

int	main(int argc, char *argv[])
{
	t_map 	map_info;
	t_img	img_info;
	t_vars	vars;
	t_all	all;

	if (argc != 2)
		error_check_parse_print(NUMBER_OF_ARGUMENT_ERROR);
	map_info = init_struct_map_info(argv[1]);
	vars = mlx_initializer(map_info);
	img_info = init_struct_img_info(vars.mlx, map_info);
	all = all_initializer(&vars, &map_info, &img_info);
	window_set_element(img_info.img, img_info, map_info);
	mlx_put_image_to_window(vars.mlx, vars.win, img_info.img, 0, 0);
	mlx_hook(vars.win, 17, 1L<<0, ft_free, &all);
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
