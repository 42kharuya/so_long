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

static void	ft_free_img(t_img *img_info, void *mlx)
{
	mlx_destroy_image(mlx, img_info->collectible);
	mlx_destroy_image(mlx, img_info->exit);
	mlx_destroy_image(mlx, img_info->player);
	mlx_destroy_image(mlx, img_info->wall);
	mlx_destroy_image(mlx, img_info->space);
	mlx_destroy_image(mlx, img_info->img);
	return ;
}

static void	ft_free_vars(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
}

int	ft_free(t_all *all)
{
	ft_free_map(all->map_info->map);
	ft_free_map(all->map_info->map_visitable);
	ft_free_img(all->img_info, all->vars->mlx);
	ft_free_vars(all->vars);
	exit(EXIT_SUCCESS);
	return (0);
}