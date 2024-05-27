/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:14 by codespace         #+#    #+#             */
/*   Updated: 2024/05/27 08:18:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

load_arg_file(char *line, t_file *file)
{

	//Apply split instead?? but ill have to customize it
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		
	else if (line[i] == 'S' && line[i + 1] == 'O')

	else if (line[i] == 'E' && line[i + 1] == 'A')

	else if (line[i] == 'W' && line[i + 1] == 'E')

	else if (line[i] == 'F')

	else if (line[i] == 'C')
		
	else	
	
}


int	check_map(t_file file, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == 0)
		return (message("ERROR\nError reading first line\n"), 1);
	
	// iterate line entirely and try find NO SO WE EA F C to allocate and load the proper info to the file.* of each one
	load_arg_file(line, &file);


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