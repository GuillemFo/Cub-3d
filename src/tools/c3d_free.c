/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:57:58 by josegar2          #+#    #+#             */
/*   Updated: 2024/07/15 15:23:11 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*ft_free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

// it's called if file != NULL
t_file	*c3d_free_file(t_file *file)
{
	int	i;

	file->no = ft_free(file->no);
	file->so = ft_free(file->so);
	file->ea = ft_free(file->ea);
	file->we = ft_free(file->we);
	file->f = ft_free(file->f);
	file->c = ft_free(file->c);
	if (file->map)
	{
		i = 0;
		while (i < file->max_y + 4)
		{
			file->map[i] = ft_free(file->map[i]);
			i++;
		}
		file->map = ft_free(file->map);
	}
	file = ft_free(file);
	return (file);
}

t_graph	*c3d_free_win(t_graph *g)
{
	if (g->mlx)
	{
		x_destroy_img(g);
		if (g->win)
			mlx_destroy_window(g->mlx, g->win);
		g->mlx = ft_free(g->mlx);
	}
	g = ft_free(g);
	return (g);
}

t_data	*c3d_free(t_data *data)
{
	if (data)
	{
		if (data->file)
			data->file = c3d_free_file(data->file);
		if (data->g)
			data->g = c3d_free_win(data->g);
		data = ft_free(data);
	}
	return (data);
}

void	*ft_free(void *p)
{
	if (p)
		free(p);
	return (NULL);
}
