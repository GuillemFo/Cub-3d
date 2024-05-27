/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:14 by codespace         #+#    #+#             */
/*   Updated: 2024/05/27 14:00:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

char	**build_map(char *line, t_file *file)
{
	int	len;

	len = ft_strlen(line);
	if (len > file->max_x)

}

int *copy_RGB(char *s)//pending
{
	int *RGB;
	int	i;

	i = 0;
	RGB = malloc(3 * sizeof(int));
	while (s[i] != ',');

}

char *copy_path(char *s)
{
	char *path;
	int	len;

	len = 0;
	len = ft_strlen(s);
	path = malloc((len + 1) * sizeof(char));
	ft_strlcpy(path, s, len);
	return (path);
}

int	load_arg(char *line, t_file *file)
{
	char *tmp;
	char **txt;

	tmp = ft_replace(line, '\t', ' ');
	txt = ft_split(tmp, ' ');
	if (ft_strcmp(txt[0], "NO") == 0 && txt[1] && !txt[2])
	{
		if (file->NO == NULL)
		{
		file->NO = copy_path(txt[1]);
		file->data_ok += 1;
		}
		else
			return (message("ERROR\n"), 1);
	}
	else if (ft_strcmp(txt[0], "SO") == 0 && txt[1] && !txt[2])
	{
		if (file->SO == NULL)
		{
			file->SO = copy_path(txt[1]);
			file->data_ok += 1;
		}
		else
			return (message("ERROR\n"), 1);
	}
	else if (ft_strcmp(txt[0], "EA") == 0 && txt[1] && !txt[2])
	{
		if (file->EA == NULL)
		{
			file->EA = copy_path(txt[1]);
			file->data_ok += 1;
		}
		else
			return (message("ERROR\n"), 1);
	}
	else if (ft_strcmp(txt[0], "WE") == 0 && txt[1] && !txt[2])
	{
		if (file->WE == NULL)
		{
			file->WE = copy_path(txt[1]);
			file->data_ok += 1;
		}
		else
			return (message("ERROR\n"), 1);
	}
	else if (ft_strcmp(txt[0], "F") == 0 && txt[1] && !txt[2])
	{
		if (file->F_flag == 0)
		{
			file->F = copy_RGB(txt[1]);
			file->data_ok += 1;
			file->F_flag = 1;
		}
		else
			return (message("ERROR\n"), 1);
	}
	else if (ft_strcmp(txt[0], "C") == 0 && txt[1] && !txt[2])
	{
		if (file->C_flag == 0)
		{
			file->C = copy_RGB(txt[1]);
			file->data_ok += 1;
			file->C_flag = 1;
		}
		else
			return (message("ERROR\n"), 1);
	}
	else if (line == NULL || line[0] == '\0')
		return (0);
	return (0);	
}

/*
	else if (valid_char(line) == true && file->data_ok == 6)
		file->tmp = build_map(line, file);
	else
		return (message("Error\nCould not load .cub, input not correct\n"), 1);
*/

int	check_map(t_file *file, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == 0)
		return (message("ERROR\nError reading first line\n"), 1);
	load_arg(line, &file);


		
	
	// iterate line entirely and try find NO SO WE EA F C to allocate and load the proper info to the file.* of each one


}

int	check_name(char *name)
{
	int	tmp;

	tmp = ft_strlen_n(name);
	if (ft_strncmp(&name[tmp - 4], ".cub", 4) != 0)
		return (-1);
	return (0);
}

int	check_args(int ac, char **av, t_data data)
{
	int	fd;

	if (ac != 2)
	{
		if (ac == 1)
			return (message("Missing map\n"), 1);
		else if (ac > 2)
			return (message("Too many arguments\n"), 1);
	}
	if (check_ber(av[1], ".cub") != 0) //pending to port from so_long and changing name
		return (message("ERROR\nFile should be .cub type\n"), 1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		message("ERROR\nFile does not open\n");
	if (check_map(data.file, fd) != 0)
	{
		message("ERROR\nMap not correct\n");
		close(fd);
	}
	close(fd);	
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