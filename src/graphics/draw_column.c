/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:00:29 by josegar2          #+#    #+#             */
/*   Updated: 2024/06/20 15:56:50 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	c3d_mlx_pixel_put(t_image im, int x, int y, int color)
{
	char *dst;

	dst = im.addr + (y * im.ll + x * (im.bpp / 8));
	*(unsigned int *)dst = color;
}

int get_texture_color(t_image im, int x, int y)
{
	char *dst;

	dst = im.addr + (y * im.ll + x * (im.bpp / 8));
	return (*(unsigned int *)dst);
}

void	draw_texture(t_graph *g, int x, int sow, int side, int sidex, int off)
{
	int 	y;
	float	yratio;
	int		txty;
	int		color;

	(void)off;
	y = (WIN_Y - sow) / 2;
	yratio = g->txt[side].h / sow;
	txty = 0;
	while (y > 0 && y < WIN_Y && y < sow + (WIN_Y - sow) / 2)
	{
		color = get_texture_color(g->txt[side], sidex, txty++ * yratio);
		c3d_mlx_pixel_put(g->i, x, y++, color);
	}
}

// draw the column x of the scene, with a SizeOfWall sow and an offset off
// off == 0 means in the center
void	draw_column(t_graph *g, int x, int sow, int off)
{
	int y;

	y = 0;
	(void)off;
	while (WIN_Y - sow > 0 && y < (WIN_Y - sow) / 2)
	{
		c3d_mlx_pixel_put(g->i, x, y++, g->rgbc);
	}
    y += sow;
	while (y < WIN_Y)
	{
		c3d_mlx_pixel_put(g->i, x, y++, g->rgbf);
	}
}

void	check_columns(t_graph *g)
{
	int	x;
	int	sow;
    int sidex;

	x = 0;
    sidex = 0;
	while (x < WIN_X)
	{
		sow = x % WIN_Y;
		if (!sow)
			sow++;
		draw_column(g, x, sow, 0);
        draw_texture(g, x, sow, 0, sidex, 0);
        sidex = (sidex + 1) % BLOCK_SIZE;
		x++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->i.img, 0, 0);
}