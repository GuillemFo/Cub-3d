/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wil <wil@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:14 by codespace         #+#    #+#             */
/*   Updated: 2024/07/01 20:58:27 by wil              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_map(t_file *file, char *line)
{
	if (line_is_space(line))
	{
		ft_free(line);
		return (message("Empty line in map\n"), 1);
	}
	if (valid_map_line(file, line) == false)
		return (ft_free(line), 1);
	file->max_y += 1;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	if ((int)ft_strlen(line) > file->max_x)
		file->max_x = ft_strlen(line);
	return (0);
}

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
	int		fd;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
		return (message("File does not open\n"), 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (file->data_ok == 6 && line_is_space(line) == false)
			file->data_ok = 7;
		if (file->data_ok < 6)
			if (get_args(file, line) == 1)
				return (close(fd), 1);
		if (file->data_ok == 7)
			if (get_map(file, line) == 1)
				return (close(fd), 1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!file->sty)
		return (message("No starting point\n"), 1);
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
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4))
		return (message("File should be .cub type\n"), 1);
	return (0);
}
