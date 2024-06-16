/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:12:49 by josegar2          #+#    #+#             */
/*   Updated: 2024/06/15 19:36:51 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_wall_h(t_file *f, int y)
{
	int	j;
	int	op;

	op = 0;
	j = 0;
	while (j < f->max_x)
	{
		if (!op && !ft_strchr(" 1", f->map[y + 2][j + 2]))
			return (message("Map not closed\n"), 1);
		if (op && f->map[y + 2][j + 2] == ' ' )
		{
			if (f->map[y + 2][j + 1] != '1')
				return (message("Map not closed\n"), 1);
			else
				op = 0;
		}
		if (!op && f->map[y + 2][j + 2] == '1')
			op = 1;
		j++;
	}
	if (op && f->map[y + 2][j + 1] != '1')
		return (message("Map not closed\n"), 1);
	return (0);
}

int	check_wall_v(t_file *f, int x)
{
	int	j;
	int	op;

	op = 0;
	j = 0;
	while (j < f->max_y)
	{
		if (!op && !ft_strchr(" 1", f->map[j + 2][x + 2]))
			return (message("Map not closed\n"), 1);
		if (op && f->map[j + 2][x + 2] == ' ' )
		{
			if (f->map[j + 1][x + 2] != '1')
				return (message("Map not closed\n"), 1);
			else
				op = 0;
		}
		if (!op && f->map[j + 2][x + 2] == '1')
			op = 1;
		j++;
	}
	if (op && f->map[j + 1][x + 2] != '1')
		return (message("Map not closed\n"), 1);
	return (0);
}

// In the map the start position has been changed by a 0
// So, just 1, 0 or spaces
int	check_wall(t_file *file)
{
	int	i;

	i = 0;
	while (i < file->max_y)
	{
		if (check_wall_h(file, i++))
			return (1);
	}
	i = 0;
	while (i < file->max_x)
	{
		if (check_wall_v(file, i++))
			return (1);
	}
	return (0);
}
