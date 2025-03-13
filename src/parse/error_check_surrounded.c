#include "../../includes/so_long.h"

static void horizontal_check(char **map, int vertical)
{
	int	i;
	int first_row;
	int last_row;

	first_row = 0;
	i = 0;
	while (map[first_row][i] != '\0')
	{
		if (map[first_row][i] != '1')
			error_check_print(MAP_SURROUNDED_ERROR);
		i++;
	}
	last_row = vertical - 1;
	i = 0;
	while (map[last_row][i] != '\0')
	{
		if (map[last_row][i] != '1')
			error_check_print(MAP_SURROUNDED_ERROR);
		i++;
	}
	return ;
}

static void vertical_check(char **map, int horizotal)
{
	int	i;
	int	first_column;
	int	last_column;

	first_column = 0;
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][first_column] != '1')
			error_check_print(MAP_SURROUNDED_ERROR);
		i++;
	}
	last_column = horizotal - 1;
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][last_column] != '1')
			error_check_print(MAP_SURROUNDED_ERROR);
		i++;
	}
	return ;
}

void	error_check_surrounded(char **map, int horizontal, int vertical)
{
	horizontal_check(map, vertical);
	vertical_check(map, horizontal);
}