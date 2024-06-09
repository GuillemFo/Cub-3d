/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:14 by codespace         #+#    #+#             */
/*   Updated: 2024/06/09 19:04:18 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// char	**build_map(char *line, t_file *file)
// {
	// int	len;
// 
	// len = ft_strle_n(line);
	// if (len > file->max_x)
	// {}
// }

int	max_min_RGB(int *RGB)
{
	int	i;
	
	i = 0;
	while (i < 3)
	{
		if (RGB[i] > 255 || RGB[i] < 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_rgb(char **RGB)
{
	int	i;

	i = 0;
	while (RGB[i])
	{
		if (check_is_num(RGB[i]) == false)
			return (1);
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

int copy_RGB(char *s, int *RGB)
{
	char *polished;
	char **tmp;
	char **tmp1;

	polished = ft_replace(s, '\n', ' ');
	tmp1 = ft_split(polished, ' ');
	tmp = ft_split(tmp1[1], ',');
	ft_free_split(tmp1);
	if (check_rgb(tmp) == 1)
		return (message("Error, RGB not valid\n"),ft_free_split(tmp), 1);
	RGB = malloc(3 * sizeof(int));
	RGB[0] = ft_atoi(tmp[0]);
	RGB[1] = ft_atoi(tmp[1]);
	RGB[2] = ft_atoi(tmp[2]);
	if (max_min_RGB(RGB) == 1)
		return (message("Error, RGB out of range\n"),ft_free_split(tmp), 1);
	ft_free_split(tmp);
	return (0);
}

char *copy_path(char *s)
{
	char	*path;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[i] == ' ')
		i++;
	len = (ft_strlen_n(&s[i]) + 1);
	path = malloc((len + 1) * sizeof(char));
	ft_strlcpy(path, &s[i], len);
	return (path);
}

int	load_arg(char *line, t_file *file)
{

	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_replace(line, '\t', ' ');
	if (tmp[i] == ' ')
	{
		while (tmp[i] == ' ')
			i++;
	}
	if (tmp[i] == 'N' && tmp[i + 1] == 'O' && tmp[i + 2] == ' ')
	{
		if (file->NO == NULL)
		{
			file->NO = copy_path(&tmp[i + 2]);
			file->data_ok +=1;
		}
		else
			return (message("Multiple arguments for NO\n"), 1);
	}
	else if (tmp[i] == 'S' && tmp[i + 1] == 'O' && tmp[i + 2] == ' ')
	{
		if (file->SO == NULL)
		{
			file->SO = copy_path(&tmp[i + 2]);
			file->data_ok +=1;
		}
		else
			return (message("Multiple arguments for SO\n"), 1);
	}
	else if (tmp[i] == 'E' && tmp[i + 1] == 'A' && tmp[i + 2] == ' ')
	{
		if (file->EA == NULL)
		{
			file->EA = copy_path(&tmp[i + 2]);
			file->data_ok +=1;
		}
		else
			return (message("Multiple arguments for EA\n"), 1);
	}
	else if (tmp[i] == 'W' && tmp[i + 1] == 'E' && tmp[i + 2] == ' ')
	{
		if (file->WE == NULL)
		{
			file->WE = copy_path(&tmp[i + 2]);
			file->data_ok +=1;
		}
		else
			return (message("Multiple arguments for WE\n"), 1);
	}
	else if (tmp[i] == 'F' && tmp[i + 1] == ' ')
	{
		if (file->F_flag == 0)
		{
			copy_RGB(&tmp[i], file->F);
			file->data_ok +=1;
			file->F_flag = 1;
		}
		else
			return (message("Multiple arguments for F\n"), 1);
	}
	else if (tmp[i] == 'C' && tmp[i + 1] == ' ')
	{
		if (file->C_flag == 0)
		{
			copy_RGB(&tmp[i], file->F);
			file->data_ok +=1;
			file->C_flag = 1;
		}
		else
			return (message("Multiple arguments for C\n"), 1);
	}
	return (0);
}

int	check_map(t_file *file, int fd)
{
	char	*line;
	int		len;
	int		r;

	r = 0;

	len = 0;
	line = get_next_line(fd);
	r += 1;
	if (line == 0)
		return (message("ERROR. No line found\n"), 1);
	if (load_arg(line, file) == 1)
		return (message("Error loading args\n"), 1);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		r += 1;
		if (line != NULL && line[0] != '\0' && line[0] != '\n')
		{
			if (file->data_ok == 6 && line_is_space(line) == false)
			{
				if (valid_map_line(line) == true)
				{
					len = ft_strlen_n(line);
					if (len > file->max_x)
						file->max_x = len;
					file->max_y +=1;
				}
				else
					return (message("Error, map contains wrong data\n"), 1);
			}
			else if (file->data_ok != 6)
			{
				if (load_arg(line, file) == 1)
					return (message("\n"), 1);
			}
		}
	}
	return (0);
}

int	check_name(char *name)
{
	int	tmp;

	tmp = ft_strlen_n(name);
	if (ft_strncmp(&name[tmp - 4], ".cub", 4) != 0)
		return (-1);
	return (0);
}

int	check_args(int ac, char **av, t_data *data)
{
	int	fd;

	if (ac != 2)
	{
		if (ac == 1)
			return (message("Missing map\n"), 1);
		else if (ac > 2)
			return (message("Too many arguments\n"), 1);
	}
	if (check_ext(av[1], ".cub") != 0)
		return (message("ERROR\nFile should be .cub type\n"), 1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		message("ERROR\nFile does not open\n");
	if (check_map(data->file, fd) != 0)
	{
		close(fd);
		message("ERROR\nMap not correct\n");
	}
	close(fd);
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