/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:24:43 by codespace         #+#    #+#             */
/*   Updated: 2024/05/31 17:50:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/// FUUUCCKKKK im fking stressed and lost :'(

char	*construct_map(char *line)
{
	char	*tmp;
	char	*ret;

	tmp = ft_strjoin("  ", line);
	ret = ft_strjoinplus(tmp, "  ");
	return (ret);
}


int	build_map(char **av, t_file *file)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		i;

	i = 2;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (message("ERROR\nFile does not open\n"), 1);
	file->map = malloc((file->max_y + 4) * sizeof(char));
	//this needs to go on a function that builds the edges only
	file->map[0] = malloc((file->max_x + 4) * sizeof(char));	//**
	file->map[1] = malloc((file->max_x + 4) * sizeof(char));	//**
	file->map[file->max_y + 1] = malloc((file->max_x + 4) * sizeof(char));	//**
	file->map[file->max_y + 2] = malloc((file->max_x + 4) * sizeof(char));	//**
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		tmp = clean_l(line);
		if (has_map(tmp) == true)
		{
			file->map[i] = construct_map(tmp);
			i++;
		}
	}
	return (0);
}
