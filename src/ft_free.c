/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:23:17 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/27 15:23:18 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i] != NULL)
		free (map[i++]);
	free(map);
	return ;
}

static void	ft_free_img(t_img *img, void *mlx)
{
	mlx_destroy_image(mlx, img->c);
	mlx_destroy_image(mlx, img->e);
	mlx_destroy_image(mlx, img->p);
	mlx_destroy_image(mlx, img->w);
	mlx_destroy_image(mlx, img->s);
	mlx_destroy_image(mlx, img->img);
	return ;
}

static void	ft_free_vars(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
}

int	ft_free(t_all *all)
{
	ft_free_map(all->map_info->map);
	ft_free_map(all->map_info->map_v);
	ft_free_img(all->img_info, all->vars->mlx);
	ft_free_vars(all->vars);
	exit(EXIT_SUCCESS);
	return (0);
}
