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
#define PLAYBLE_COLLECTIVE_ERROR 11
#define PLAYBLE_EXIT_ERROR 12

// struct
typedef struct s_player
{
	int	x;
	int y;
	int	up_location[2];
	int down_location[2];
	int	left_location[2];
	int	right_location[2];
} t_player;

typedef struct s_map
{
	char		**map; //freeの必要あり
	char		**map_visitable;
	int			vertical; //縦
	int			horizontal; //横
	int			collectible_count;
	t_player	player_info;
} t_map;

// prototype
t_map		init_struct_map_info(char	*map_path);
t_player	init_struct_player_info(char **map);
void		error_check_print(int error_check);
void		error_check_rectangular(char **map);
void		error_check_path_extension(char *path);
void		error_check_element(char **map);
void		error_check_surrounded(char **map, int horizontal, int vertical);
void		error_check_playble(char **map_visitable);
char		**init_struct_map_info_map(char *map_path, int vertical);
int			init_struct_map_info_vertical(char *map_path);
int			init_struct_map_info_collectible(char **map);
char		**init_struct_map_info_map_visitable_init(t_map map_info);
void		init_struct_map_info_map_visitable(char **map_visitable, int x, int y);


#endif