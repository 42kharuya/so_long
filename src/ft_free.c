#include "../includes/so_long.h"

void	ft_free_map(char **map)
{
	int i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i] != NULL)
		free (map[i++]);
	free(map);
	return ;
}

void	ft_free_img(t_img *img_info, void *mlx)
{
	mlx_destroy_image(mlx, img_info->collectible);
	mlx_destroy_image(mlx, img_info->exit);
	mlx_destroy_image(mlx, img_info->player);
	mlx_destroy_image(mlx, img_info->wall);
	mlx_destroy_image(mlx, img_info->space);
	return ;
}

void	ft_free(t_map *map_info)
{
	ft_free_map(map_info->map);
	ft_free_map(map_info->map_visitable);
}