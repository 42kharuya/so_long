#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_map map_info;
	int i;

	if (argc != 2)
		error_check_print(NUMBER_OF_ARGUMENT_ERROR);
	map_info = init_struct_map_info(argv[1]);
	i = 0;
	while (map_info.map[i])
	{
		printf("map:%s\n", map_info.map[i]);
		i++;
	}
	i = 0;
	while (map_info.map_visitable[i])
	{
		printf("map visitable:%s\n", map_info.map_visitable[i]);
		i++;
	}
	return (0);
}
