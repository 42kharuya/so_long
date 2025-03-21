#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;
	t_map 	map_info;
	int 	i;

	if (argc != 2)
		error_check_parse_print(NUMBER_OF_ARGUMENT_ERROR);
	map_info = init_struct_map_info(argv[1]);
	i = 0;
	while (map_info.map[i])
	{
		printf("map:%s\n", map_info.map[i]);
		i++;
	}
	i = 0;
	printf ("-----------------------------------------------\n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 360, "so_long");
	ft_free(&map_info);
	return (0);
}
