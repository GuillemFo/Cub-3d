/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:14 by codespace         #+#    #+#             */
/*   Updated: 2024/05/27 12:04:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	build_map(char **map)
{
	int	len;
	

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
	int	i;
	int	x;

	i = 0;
	while (s[i] == ' ')
		i++;
	x = i;
	while (s[i] != ' ' || s[i] != '\0')
		i++;
	path = malloc(((i - x) + 1) * sizeof(char));
	ft_strlcpy(path, &s[x], i - x);
	i = ft_strlen(path);
	if (ft_strncmp(&path[i - 4], ".xmp", 4) != 0)
		return (message("No .xpm file found\n"), NULL);
	return (path);
}

load_file_arg(char *line, t_file *file)
{
	int	i;

	i = 0;
	if (line[i] == ' ')
	{
		while (line[i] == ' ')
			i++;
	}
	if (line[i] == 'N' && line[i + 1] == 'O')
		file->NO = copy_path(&line[i + 2]);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		file->SO = copy_path(&line[i + 2]);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		file->EA = copy_path(&line[i + 2]);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		file->WE = copy_path(&line[i + 2]);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		file->F = copy_RGB(&line[i + 1]);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		file->C = copy_RGB(&line[i + 1]);
	else if (line[i] == '1'|| line[i] == '0')
		build_map(file->map);
	else
		return (message("Error on .cub file\n"), 1);
	return (0);	
}


int	check_map(t_file file, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == 0)
		return (message("ERROR\nError reading first line\n"), 1);
	
	// iterate line entirely and try find NO SO WE EA F C to allocate and load the proper info to the file.* of each one
	load_file_arg(line, &file);


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
	if (check_ber(av[1], ".cub") != 0)
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