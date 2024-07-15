/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:34:02 by josegar2          #+#    #+#             */
/*   Updated: 2024/07/15 12:02:09 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	draw_brick(t_image im, int x, int y, int color)
{
	int	i;
	int	j;

	x *= 16;
	y *= 16;
	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 16)
		{
			c3d_mlx_pixel_put(im, x + i, y + j++, color);
		}
		i++;
	}
}

void	draw_minimap(t_graph *g, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 13)
		{
			if (x + j >= g->file->max_x || y + i >= g->file->max_y)
				draw_brick(g->mm, j, i, MMEMPTY);
			else if (g->file->map[y + i + 2][x + j + 2] == '1')
				draw_brick(g->mm, j, i, MMWALL);
			else if (g->file->map[y + i + 2][x + j + 2] == '0')
				draw_brick(g->mm, j, i, MMFLOOR);
			else
				draw_brick(g->mm, j, i, MMEMPTY);
			j++;
		}
		i++;
	}
}

void	draw_mm_player(t_graph *g, int x, int y)
{
	int	xp;
	int	yp;
	int	i;
	int	j;

	xp = (i_coor(g->p.povx) - x) * MM_BSIZE;
	xp += trunc(fmod(g->p.povx, BLOCK_SIZE) * MM_BSIZE / BLOCK_SIZE);
	yp = (i_coor(g->p.povy) - y) * MM_BSIZE;
	yp += trunc(fmod(g->p.povy, BLOCK_SIZE) * MM_BSIZE / BLOCK_SIZE);
	i = -2;
	while (i < 3)
	{
		j = -2;
		while (j < 3)
			c3d_mlx_pixel_put(g->mm, xp + j++, yp + i, MMPLAYER);
		i++;
	}
	i = 0;
	while (i < 16)
	{
		c3d_mlx_pixel_put(g->mm, xp + (int)(i * g->p.dirx),
			yp + (int)(i * g->p.diry), MMPLAYER);
		i++;
	}
}
// minimap 13 x 11. Each coor = 16 pixels

void	minimap(t_graph *g)
{
	int	x;
	int	y;

	if ((i_coor(g->p.povx) + 6) >= g->file->max_x)
		x = g->file->max_x - 13;
	else
		x = i_coor(g->p.povx) - 6;
	if (x < 0)
		x = 0;
	if ((i_coor(g->p.povy) + 5) >= g->file->max_y)
		y = g->file->max_y - 11;
	else
		y = i_coor(g->p.povy) - 5;
	if (y < 0)
		y = 0;
	draw_minimap(g, x, y);
	draw_mm_player(g, x, y);
	mlx_put_image_to_window(g->mlx, g->win, g->mm.img, 0, 0);
}
