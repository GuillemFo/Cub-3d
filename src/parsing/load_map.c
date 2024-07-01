/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wil <wil@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:24:43 by codespace         #+#    #+#             */
/*   Updated: 2024/07/01 18:57:21 by wil              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
