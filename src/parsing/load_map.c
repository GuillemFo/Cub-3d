/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:24:43 by codespace         #+#    #+#             */
/*   Updated: 2024/06/13 18:05:56 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*construct_map(char *line, int max_x)
{
	char	*tmp;
	char	*ret;
	char	*clean;
	int		len;

	clean = clean_l(line);
	len = ft_strlen(line);
	tmp = ft_strjoin("  ", clean);
	free(clean);
	if (len <= max_x)
	{
		len = (max_x - len) + 1;
	}
	else
		len = 2;
	clean = malloc (len +1 * sizeof(char));
	clean[len] = '\0';
	fill_with_space(clean);
	ret = ft_strjoin(tmp, clean);
	return (ret);
}

int	build_map(char **av, t_file *file)
{
	char	*line;
	int		fd;
	int		i;

	i = 2;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (message("ERROR\nFile does not open\n"), 1);
	printf("%d\n", file->max_y);
	file->map = malloc((file->max_y + 5) * sizeof(char*));
	file->map[file->max_y + 4] = NULL;

	file->map[0] = malloc((file->max_x + 4) * sizeof(char));	//first line
	file->map[0][file->max_x + 3] = '\0';
	fill_with_space(file->map[0]);

	file->map[1] = malloc((file->max_x + 4) * sizeof(char));	//second line
	file->map[1][file->max_x + 3] = '\0';
	fill_with_space(file->map[1]);

	file->map[file->max_y + 2] = malloc((file->max_x + 4) * sizeof(char));	//line after map 1
	file->map[file->max_y + 2][file->max_x + 3] = '\0';
	fill_with_space(file->map[file->max_y + 2]);

	file->map[file->max_y + 3] = malloc((file->max_x + 4) * sizeof(char));	//line after map 2 (segfault or not printing
	file->map[file->max_y + 3][file->max_x + 3] = '\0';
	fill_with_space(file->map[file->max_y + 3]);

	
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (has_map(line) == true)
		{
			file->map[i] = construct_map(line, file->max_x);
			i++;
		}
	}
	return (0);
}


/*

The build_map function has to add 2 extra lines over an at the bottom so we can check them.
Has to add 2 spaces before and after each line and extend the lines that need to be completed with spaces before or after
using the max lenght x and y saved on the structure;

Example

--                                     --
--                                     --
--          1111111111111111111111111  --
--          1000000000110000000000001  --
--          1011000001110000000000001  --
--          1001000000000000000000001  --
--  111111111011000001110000000000001  --
--  100000000011000001110111110111111  --
--  11110111111111011100000010001      --
--  11110111111111011101010010001      --
--  11000000110101011100000010001      --
--  10000000000000001100000010001      --
--  10000000000000001101010010001      --
--  11000001110101011111011110N0111    --
--  11110011111010111101111010001      --
--  11111111111111111111111111111      --
--                                     --
--                                     --

Need to calculate the lenght between the spacers and the map walls and from the last map wall to the max size found and stored at file->max_x

*/