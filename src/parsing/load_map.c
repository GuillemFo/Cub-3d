/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:24:43 by codespace         #+#    #+#             */
/*   Updated: 2024/05/31 16:49:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/// FUUUCCKKKK im fking stressed and lost :'(

int	build_map(char **av, t_file *file)
{
	char	*line;
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (message("ERROR\nFile does not open\n"), 1);
	file->map = malloc((file->max_y + 4) * sizeof(char));
	file->map[0] = malloc((file->max_x + 4) * sizeof(char));
	file->map[1] = malloc((file->max_x + 4) * sizeof(char));
	file->map[file->max_y + 1] = malloc((file->max_x + 4) * sizeof(char));
	file->map[file->max_y + 2] = malloc((file->max_x + 4) * sizeof(char));
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
