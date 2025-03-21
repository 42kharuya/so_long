#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*win;
	void	*img;
	t_map 	map_info;
	t_img	img_info;

	if (argc != 2)
		error_check_parse_print(NUMBER_OF_ARGUMENT_ERROR);
	map_info = init_struct_map_info(argv[1]);
	mlx = mlx_init();
	win = mlx_new_window(mlx, map_info.horizontal * 64, map_info.vertical * 64, "so_long");
	img_info = init_struct_img_info(mlx);
	img = mlx_new_image(mlx, map_info.horizontal * 64, map_info.vertical * 64);
	window_set_element(img, img_info, map_info);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	mlx_destroy_image(mlx, img);
	ft_free_img(&img_info, mlx);
	ft_free(&map_info);
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
// 	mlx_win = mlx_new_window(mlx, 640, 360, "so_long");
// 	ft_free(&map_info);
// 	return (0);
// }
