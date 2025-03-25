#include "../../includes/so_long.h"

static int	get_target_x(int p_x, int vector)
{
	int	target_x;

	target_x = 0;
	if (vector == W)
		target_x = p_x;
	else if (vector == A)
		target_x = p_x - 1;
	else if (vector == S)
		target_x = p_x;
	else if (vector == D)
		target_x = p_x + 1;
	return (target_x);
}

static int	get_target_y(int p_y, int vector)
{
	int	target_y;

	target_y = 0;
	if (vector == W)
		target_y = p_y - 1;
	else if (vector == A)
		target_y = p_y;
	else if (vector == S)
		target_y = p_y + 1;
	else if (vector == D)
		target_y = p_y;
	return (target_y);
}

void	window_move(t_all *all, int vector, int p_x, int p_y)
{
	char	**map;
	int		target_x;
	int		target_y;

	target_x = get_target_x(p_x, vector);
	target_y = get_target_y(p_y, vector);
	map = all->map_info->map;
	if (map[target_y][target_x] == '1')
		return ;
	else if (map[target_y][target_x] == '0')
		map[target_y][target_x] = map[p_y][p_x];
	else if (map[target_y][target_x] == 'C')
	{
		map[target_y][target_x] = map[p_y][p_x];
		(all->map_info->c_count)--;
	}
	else if (map[target_y][target_x] == 'E' && (all->map_info->c_count) == 0)
	{
		map[target_y][target_x] = map[p_y][p_x];
		map[p_y][p_x] = '0';
		window_set_element(all->img_info->img, *(all->img_info), *(all->map_info));
		mlx_put_image_to_window(all->vars->mlx, all->vars->win, all->img_info->img, 0, 0);
		ft_printf("congratulations!!\nThe game has been cleared!\n");
		ft_free(all);
	}
	else
		return ;
	map[p_y][p_x] = '0';
	all->map_info->player_info.x = target_x;
	all->map_info->player_info.y = target_y;
	window_set_element(all->img_info->img, *(all->img_info), *(all->map_info));
	mlx_put_image_to_window(all->vars->mlx, all->vars->win, all->img_info->img, 0, 0);
}
