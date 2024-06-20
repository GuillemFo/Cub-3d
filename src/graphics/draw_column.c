/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:00:29 by josegar2          #+#    #+#             */
/*   Updated: 2024/06/19 22:07:51 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	c3d_mlx_pixel_put(t_image im, int x, int y, int color)
{
	char	*dst;

	dst = im.addr + (y * im.ll + x * (im.bpp / 8));
	*(unsigned int *)dst = color;
}

// draw the column x of the scene, with a SizeOfWall sow and an offset off
// off == 0 means
void	draw_column(t_graph *g, int x, int sow, int off)
{
	int	y;

	y = 0;
	(void)off;
	while (WIN_Y - sow > 0 && y < (WIN_Y - sow) / 2)
	{
		c3d_mlx_pixel_put(g->i, x, y++, g->rgbc);
		ft_printf("while Y=%d\n", y);
	}
	while (y < WIN_Y && y < sow + (WIN_Y - sow) / 2)

	{
		c3d_mlx_pixel_put(g->i, x, y++, 0x00FFFFFF);
	}
		ft_printf("Y=%d after pixel put black\n", y);
	while (y < WIN_Y)
	{
		c3d_mlx_pixel_put(g->i, x, y++, g->rgbf);
	}
			ft_printf("Y=%d after pixl put rgbf\n", y);
}

void	check_columns(t_graph *g, t_data *data)
{
	int x;
	int sow;

	x = 0;
	while (x < WIN_X)
	{
		sow = get_wall_size(g, x, data);
		ft_printf("sow=%d\n", sow);
		draw_column(g, x, sow, 0);
		x++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->i.img, 0, 0);
}
