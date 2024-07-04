/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:00:29 by josegar2          #+#    #+#             */
/*   Updated: 2024/07/05 00:07:45 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	c3d_mlx_pixel_put(t_image im, int x, int y, int color)
{
	char	*dst;

	dst = im.addr + (y * im.ll + x * (im.bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_texture_color(t_image im, int x, int y)
{
	char	*dst;

	dst = im.addr + (y * im.ll + x * (im.bpp / 8));
	return (*(unsigned int *)dst);
}

void	draw_texture(t_graph *g, int x, t_ray r)
{
	int		y;
	int		z;
	float	yratio;
	double	txty;
	int		color;

	y = (WIN_Y > r.sow) * (WIN_Y - r.sow) / 2;
	z = (y + r.sow) * (WIN_Y > r.sow) + WIN_Y * (WIN_Y <= r.sow);
	yratio = (float)g->txt[r.soi].h / r.sow;
	r.ooi *= g->txt[r.soi].w / BLOCK_SIZE;
	txty = (r.sow > WIN_Y) * yratio * (r.sow - WIN_Y) / 2;
	while (y < z)
	{
		color = get_texture_color(g->txt[r.soi], r.ooi, trunc(txty));
		txty += yratio;
		c3d_mlx_pixel_put(g->i, x, y++, color);
	}
	draw_column(g, x, r);
}
//	printf("ooi: %.3f sow: %.3f\n",r.ooi, r.sow);
//	printf("x: %d, ooi: %.3f yratio: %.3f", x, r.ooi, yratio);
//	printf("y: %d z: %d txty: %.3f\n", y, z, txty);

// draw the column x of the scene, with a SizeOfWall sow and an offset off
// off == 0 means in the center
void	draw_column(t_graph *g, int x, t_ray r)
{
	int	y;
    double  p;

	if (r.sow >= WIN_Y)
		return ;
	y = 0;
	while (WIN_Y - r.sow > 0 && y < (int)(WIN_Y - r.sow) / 2)
	{
		c3d_mlx_pixel_put(g->i, x, y++, g->rgbc);
	}
	y += (int)r.sow;
	while (y < WIN_Y)
	{
        p = g->p.ppd * VIEW_HEIGHT / (y - BLOCK_SIZE / 2);
        p = p / cos(g->p.pova - g->ray.raya);
		c3d_mlx_pixel_put(g->i, x, y++, g->rgbf >> (int)p % 3);
	}
}
