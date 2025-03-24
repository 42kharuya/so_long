#include "../../includes/so_long.h"

static void	set_element(char **buffer, char *buffer_img, int line_byte, int x, int y)
{
	int	element_x;
	int	element_y;
	int	pixel_element;
	int	pixel_map;

	element_y = 0;
	while (element_y < 32)
	{
		element_x = 0;
		while (element_x < 32)
		{
			pixel_element = (element_y * 128) + (element_x * 4);
			pixel_map = (((y * 32) + element_y) * line_byte) + (((x * 32) + element_x) * 4);
			(*buffer)[pixel_map + 0] = buffer_img[pixel_element + 0];
			(*buffer)[pixel_map + 1] = buffer_img[pixel_element + 1];
			(*buffer)[pixel_map + 2] = buffer_img[pixel_element + 2];
			(*buffer)[pixel_map + 3] = buffer_img[pixel_element + 3];
			element_x++;
		}
		element_y++;
	}
	return ;
}

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
		while (x < (map_info.horizontal))
		{
			if (map[y][x] == 'P')
				set_element(buffer, img_info.buffer_player, line_byte, x, y);
			else if (map[y][x] == 'C')
				set_element(buffer, img_info.buffer_collectible, line_byte, x, y);
			else if (map[y][x] == 'E')
				set_element(buffer, img_info.buffer_exit, line_byte, x, y);
			else if (map[y][x] == '1')
				set_element(buffer, img_info.buffer_wall, line_byte, x, y);
			else if (map[y][x] == '0')
				set_element(buffer, img_info.buffer_space, line_byte, x, y);
			x++;
		}
		y++;
	}
}

void	window_set_element(void *img, t_img img_info, t_map map_info)
{
	char	*buffer;
	int 	line_byte;
	int		pixel_bits;
	int		endian;

	buffer = mlx_get_data_addr(img, &pixel_bits, &line_byte, &endian);
	set_elements(map_info, img_info, &buffer, line_byte);
	return ;
}
