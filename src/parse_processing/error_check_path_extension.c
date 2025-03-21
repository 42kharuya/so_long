#include "../../includes/so_long.h"

void error_check_path_extension(char *path)
{
	char *extension;

	extension = ft_strchr(path, '.');
	if (ft_strlen(extension) != ft_strlen(".ber")
			|| ft_strncmp(extension, ".ber", sizeof(extension)) != 0)
		error_check_parse_print(PATH_ERROR);
	return ;
}