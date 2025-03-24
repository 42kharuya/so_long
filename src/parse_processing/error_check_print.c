#include "../../includes/so_long.h"

void	error_check_parse_print(int error_check)
{
	ft_printf("Error\n");
	if (error_check == OPEN_ERROR)
		ft_printf("open function error. Please make sure .ber PATH is correct!\n");
	else if (error_check == CLOSE_ERROR)
		ft_printf("clse function error. Please make sure .ber PATH is correct!\n");
	else if (error_check == MALLOC_ERROR)
		ft_printf("malloc allocation failure!\n");
	else if (error_check == RECTANGULAR_ERROR)
		ft_printf("map is not rectangular! Please make map rectangular.\n");
	else if (error_check == PATH_ERROR)
		ft_printf("The PATH extension specified is incorrect. Please specify a .ber file.\n");
	else if (error_check == INVALID_ELEMENT_ERROR)
		ft_printf("invalid element in map specified.\n");
	else if (error_check == NUMBER_OF_PLAYER_ERROR)
		ft_printf("The number of player must be one.\n");
	else if (error_check == NUMBER_OF_EXIT_ERROR)
		ft_printf("The number of exit must be one.\n");
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
