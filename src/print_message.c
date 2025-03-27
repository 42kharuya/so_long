#include "../includes/so_long.h"

void	print_message_parse_error(int error_check)
{
	ft_printf("Error\n");
	if (error_check == RECTANGULAR_ERROR)
		ft_printf("map is not rectangular! Please make map rectangular.\n");
	else if (error_check == PATH_ERROR)
		ft_printf("The PATH extension specified is incorrect.\n");
	else if (error_check == INVALID_ELEMENT_ERROR)
		ft_printf("invalid element in map specified.\n");
	else if (error_check == NUMBER_OF_PLAYER_ERROR)
		ft_printf("The number of player must be one.\n");
	else if (error_check == NUMBER_OF_EXIT_ERROR)
		ft_printf("The number of element must be one.\n");
	else if (error_check == NUMBER_OF_COLLECTIBLE_ERROR)
		ft_printf("The number of collectible must be at least one.\n");
	else if (error_check == NUMBER_OF_ARGUMENT_ERROR)
		ft_printf("Usage: ./so_long [path_of_map]\n");
	else if (error_check == MAP_SURROUNDED_ERROR)
		ft_printf("map is not surrounded/enclosed by wall.\n");
	else if (error_check == PLAYBLE_COLLECTIVE_ERROR)
		ft_printf("map is not playble. Unable to acquire collectible.\n");
	else if (error_check == PLAYBLE_EXIT_ERROR)
		ft_printf("map is not playble. can't get to the exit.\n");
	exit(EXIT_FAILURE);
}

void	print_message_func_error(int error_check)
{
	if (error_check == OPEN_ERROR)
		ft_printf("open function error. Please check the PATH\n");
	else if (error_check == CLOSE_ERROR)
		ft_printf("close function error. Please check the PATH\n");
	else if (error_check == MALLOC_ERROR)
		ft_printf("malloc allocation failure!\n");
	exit(EXIT_FAILURE);
}

void	print_message_success(t_all *all)
{
	window_set_element(*(all->img_info), *(all->map_info));
	mlx_put_image_to_window(all->vars->mlx, all->vars->win,
		all->img_info->img, 0, 0);
	ft_printf("congratulations!!\nThe game has been cleared!\n");
	ft_free(all);
}
