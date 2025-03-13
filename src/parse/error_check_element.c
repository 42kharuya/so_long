#include "../../includes/so_long.h"

static	void	match_against_correct(int player, int exit, int collectible)
{
	if (player != 1)
		error_check_print(NUMBER_OF_PLAYER_ERROR);
	else if (exit != 1)
		error_check_print(NUMBER_OF_EXIT_ERROR);
	else if (collectible < 1)
		error_check_print(NUMBER_OF_COLLECTIBLE_ERROR);
	return ;
}

void	error_check_element(char **map)
{
	int	element[3];
	int i;
	int j;

	element[0] = 0;
	element[1] = 0;
	element[2] = 0;
	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] == 'P')
				element[0]++;
			else if (map[i][j] == 'E')
				element[1]++;
			else if (map[i][j] == 'C')
				element[2]++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				error_check_print(INVALID_ELEMENT_ERROR);
		}
	}
	match_against_correct(element[0], element[1], element[2]);
	return ;
}