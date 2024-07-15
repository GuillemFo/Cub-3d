/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:24:43 by codespace         #+#    #+#             */
/*   Updated: 2024/07/15 12:36:14 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D_bonus.h"

void	fill_with_space(char *str, int size)
{
	while (--size >= 0)
		str[size] = ' ';
}

int	construct_map(t_file *file, char *line, int i)
{
	int		j;

	j = 0;
	while (line[j] && line[j] != '\n')
	{
		if (ft_strchr("NSEW", line[j]))
		{
			file->stx = j;
			file->sty = i - 2;
			file->sto = line[j];
			file->map[i][j + 2] = '0';
		}
		else
			file->map[i][j + 2] = line[j];
		j++;
	}
	return (0);
}

int	init_map(t_file *file)
{
	int	i;

	file->map = ft_calloc((file->max_y + 5), sizeof(char *));
	if (!file->map)
		return (message("Map allocation error\n"), 1);
	i = 0;
	while (i < file->max_y + 4)
	{
		file->map[i] = ft_calloc((file->max_x + 5), sizeof(char));
		if (!file->map[i])
			return (message("Map allocation error\n"), 1);
		fill_with_space(file->map[i], file->max_x + 4);
		i++;
	}
	return (0);
}

int	build_map(char **av, t_file *file)
{
	char	*line;
	int		fd;
	int		i;

	if (init_map(file))
		return (1);
	i = 2;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (message("File does not open\n"), 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (has_map(line) == true)
			construct_map(file, line, i++);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (check_wall(file));
}

/*

The build_map function has to add 2 extra lines over an at the bottom
so we can check them. Has to add 2 spaces before and after each line
and extend the lines that need to be completed with spaces before or
after using the max lenght x and y saved on the structure;

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

Need to calculate the lenght between the spacers and the map walls and
from the last map wall to the max size found and stored at file->max_x

*/