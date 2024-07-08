/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wil <wil@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:43:09 by gforns-s          #+#    #+#             */
/*   Updated: 2024/07/08 13:20:36 by wil              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window(t_graph *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
	return (1);
}

int	img_init(t_graph *g)
{
	g->i.img = mlx_new_image(g->mlx, WIN_X, WIN_Y);
	if (!g->i.img)
		return (1);
	g->i.addr = mlx_get_data_addr(g->i.img, &(g->i.bpp), &(g->i.ll),
			&(g->i.en));
	g->mm.img = mlx_new_image(g->mlx, MM_X * MM_BSIZE, MM_Y * MM_BSIZE);
	if (!g->mm.img)
		return (1);
	g->mm.w = MM_X * MM_BSIZE;
	g->mm.h = MM_Y * MM_BSIZE;
	g->mm.addr = mlx_get_data_addr(g->mm.img, &(g->mm.bpp), &(g->mm.ll),
			&(g->mm.en));
	return (0);
}

int	start_mlx(t_data *data)
{
	data->g->mlx = mlx_init();
	if (!data->g->mlx)
	{
		return (message("mlx initialitation error\n"), 1);
	}
	data->g->win = mlx_new_window(data->g->mlx, WIN_X, WIN_Y,
			"Cub3D gforns-s & josegar2");
	if (load_textures(data->file, data->g))
	{
		return (1);
	}
	if (img_init(data->g))
		return (message("Image creation error\n"), 1);
	data->g->file = data->file;
	loop_rays(data->g);
	mlx_hook(data->g->win, KEYDOWN, 0, p_moves, data->g);
	mlx_hook(data->g->win, DESTROY, 1L << 0, close_window, data->g);
	mlx_loop(data->g->mlx);
	return (0);
}
	//mlx_hook(data->g->win, 06, (1L<<6), m_moves, data->g);
	// pending mouse moves
