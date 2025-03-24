#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

// macro(error)
# define OPEN_ERROR 0
# define CLOSE_ERROR 1
# define MALLOC_ERROR 2
# define RECTANGULAR_ERROR 3
# define PATH_ERROR 4
# define INVALID_ELEMENT_ERROR 5
# define NUMBER_OF_PLAYER_ERROR 6
# define NUMBER_OF_EXIT_ERROR 7
# define NUMBER_OF_COLLECTIBLE_ERROR 8
# define NUMBER_OF_ARGUMENT_ERROR 9
# define MAP_SURROUNDED_ERROR 10
# define PLAYBLE_COLLECTIVE_ERROR 11
# define PLAYBLE_EXIT_ERROR 12

// macro(move)
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define ALLOW_UP 65362
# define ALLOW_DOWN 65364
# define ALLOW_LEFT 65361
# define ALLOW_RIGHT 65363

// struct
typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_player
{
	int	x;
	int	y;
	int	up_location[2];
	int	down_location[2];
	int	left_location[2];
	int	right_location[2];
}	t_player;

typedef struct s_map
{
	char		**map; //freeの必要あり
	char		**map_visitable;
	int			vertical;
	int			horizontal;
	int			collectible_count;
	t_player	player_info;
}	t_map;

typedef struct s_img
{
	void	*img;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*wall;
	void	*space;
	char	*buffer_player;
	char	*buffer_collectible;
	char	*buffer_exit;
	char	*buffer_wall;
	char	*buffer_space;
}	t_img;

typedef struct s_all
{
	t_vars	*vars;
	t_map	*map_info;
	t_img	*img_info;
}	t_all;

// prototype
t_map		init_struct_map_info(char	*map_path);
t_player	init_struct_player_info(char **map);
void		error_check_parse_print(int error_check);
void		error_check_rectangular(char **map);
void		error_check_path_extension(char *path);
void		error_check_element(char **map);
void		error_check_surrounded(char **map, int horizontal, int vertical);
void		error_check_playble(t_map map_info);
char		**init_struct_map_info_map(char *map_path, int vertical);
int			init_struct_map_info_vertical(char *map_path);
int			init_struct_map_info_collectible(char **map);
char		**init_struct_map_info_map_visitable_init(t_map map_info);
void		init_struct_map_info_map_visitable(char **map_visitable, int x, int y);
int			ft_free(t_all *all);
void		ft_free_map(char **map);
t_img		init_struct_img_info(void *mlx, t_map map_info);
void		window_set_element(void *img, t_img img_info, t_map map_info);
t_vars		init_struct_vars(t_map map_info);
int			key_hook(int keycode, t_all *all);
t_all		init_struct_all(t_vars *vars, t_map *map_info, t_img *img_info);
void		window_move(t_all *all, int vector, int p_x, int p_y);

#endif