#include "../../includes/so_long.h"

//byte単位
static void	set_element(char **buffer, char *buffer_img, int line_byte, int x, int y)
{
	int	x_tmp;
	int	x_max;
	int	y_max;
	int pixel_big;
	int pixel_small;

	x_tmp = x;
	x_max = x + 64;
	y_max = y + 64;
	while (y < y_max)
	{
		x = x_tmp;
		while(x < x_max)
		{
			pixel_big = (y * line_byte) + (x * 4);
			pixel_small = (y * 256) + (x * 4);
			(*buffer)[pixel_big + 0] = buffer_img[pixel_small + 0];
			(*buffer)[pixel_big + 1] = buffer_img[pixel_small + 1];
			(*buffer)[pixel_big + 2] = buffer_img[pixel_small + 2];
			(*buffer)[pixel_big + 3] = buffer_img[pixel_small + 3];
			x++;
		}
		y++;
	}
	return ;
}

//pixel単位
static void	set_elements(t_map map_info, t_img img_info, char **buffer, int line_byte)
{
	char **map;
	int	x;
	int	y;

	map = map_info.map;
	y = 0;
	while (y < (map_info.vertical))
	{
		x = 0;
		while (x < map_info.horizontal)
		{
			printf ("y:%d x:%d\n", y, x);
			if (map[y][x] == 'P')
				set_element(buffer, img_info.buffer_player, line_byte, x * 64, y * 64);
			else if (map[y][x] == 'C')
				set_element(buffer, img_info.buffer_collectible, line_byte, x * 64, y * 64);
			else if (map[y][x] == 'E')
				set_element(buffer, img_info.buffer_exit, line_byte, x * 64, y * 64);
			else if (map[y][x] == '1')
				set_element(buffer, img_info.buffer_wall, line_byte, x * 64, y * 64);
			else if (map[y][x] == '0')
				set_element(buffer, img_info.buffer_space, line_byte, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	window_set_element(void *img, t_img img_info, t_map map_info)
{
	int line_byte;
	int pixel_bits;
	int endian;

	char *buffer = mlx_get_data_addr(img, &pixel_bits, &line_byte, &endian);
	printf("line_byte:%d\n", line_byte);
	set_elements(map_info, img_info, &buffer, line_byte);
	return ;
}