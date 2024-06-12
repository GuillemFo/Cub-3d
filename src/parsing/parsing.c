/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:14 by codespace         #+#    #+#             */
/*   Updated: 2024/06/12 20:29:56 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_args(t_file *file, char *line)
{
	if (line_is_space(line) == false)
	{
		if (load_arg(line, file) == 1)
		{
			free(line);
			return (message("Bad config\n"), 1);
		}
	}
	return (0);
}

int	check_map(t_file *file, char *fn)
{
	char	*line;
	int		len;
	int		fd;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
		return (message("File does not open\n"), 1);
	len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (file->data_ok < 6)
		{
			if (get_args(file, line) == 1)
				return (close(fd), 1);
		}
		else if (file->data_ok == 6 && line_is_space(line) == false)
			file->data_ok = 7;
		if (file->data_ok == 7 && line_is_space(line) == true)
		{
			close(fd);
			free(line);
			return (message("Empty line in map\n"), 1);
		}
		else if (file->data_ok == 7)
		{
			if (valid_map_line(line) == true)
			{
				len = ft_strlen(line);
				if (len > file->max_x)
					file->max_x = len;
				file->max_y += 1;
			}
			else
			{
				close(fd);
				return (message("Map contains wrong data\n"), 1);
			}
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (file->data_ok != 7);
}

int	check_args(int ac, char **av)
{
	if (ac != 2)
	{
		if (ac == 1)
			return (message("Missing map\n"), 1);
		else if (ac > 2)
			return (message("Too many arguments\n"), 1);
	}
	if (check_ext(av[1], ".cub") != 0)
		return (message("File should be .cub type\n"), 1);
	return (0);
}

/*

confirm .cub FILE and only 1 arg

◦ The map must be closed/surrounded by walls, if not the program must return
an error.
◦ Except for the map content, each type of element can be separated by one or
more empty line(s).
◦ Except for the map content which always has to be the last, each type of
element can be set in any order in the file.
◦ Except for the map, each type of information from an element can be separated
by one or more space(s).
◦ The map must be parsed as it looks in the file. Spaces are a valid part of the
map and are up to you to handle. You must be able to parse any kind of map,
as long as it respects the rules of the map.

*/