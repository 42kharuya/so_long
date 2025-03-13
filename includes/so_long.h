#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

// macro
#define OPEN_ERROR 0
#define CLOSE_ERROR 1
#define MALLOC_ERROR 2
#define RECTANGULAR_ERROR 3
#define PATH_ERROR 4
#define INVALID_ELEMENT_ERROR 5
#define NUMBER_OF_PLAYER_ERROR 6
#define NUMBER_OF_EXIT_ERROR 7
#define NUMBER_OF_COLLECTIBLE_ERROR 8
#define NUMBER_OF_ARGUMENT_ERROR 9
#define MAP_SURROUNDED_ERROR 10

// struct
typedef struct s_map
{
	char	**map; //freeの必要あり
	int		*map_calc;
	int		vertical; //縦
	int		horizontal; //横
	int		collectible_count;
} t_map;

// prototype
t_map	init_struct_map_info(char	*map_path);
t_map	init_struct_initial(void);
void	error_check(t_map map_info, char *path);
void	error_check_print(int error_check);
void	error_check_rectangular(char **map);
void	error_check_path_extension(char *path);
void	error_check_element(char **map);
void	error_check_surrounded(char **map, int horizontal, int vertical);

#endif