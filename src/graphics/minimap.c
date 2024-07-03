/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:34:02 by josegar2          #+#    #+#             */
/*   Updated: 2024/07/03 20:07:03 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define MMWALL 0x000000FF
#define MMFLOOR 0x00000000
#define MMEMPTY 0x00FFFFFF
#define MMPLAYER 0x00FF0000

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
	t_image	mm;
	int		i;
	int		j;

	mm.img = mlx_new_image(g->mlx, 13 * 16, 11 * 16);
	//check error
	mm.addr = mlx_get_data_addr(mm.img, &mm.bpp, &mm.ll, &mm.en);
	mm.w = 13 * 16;
	mm.h = 11 * 16;
	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 13)
		{
			if (x + j >= g->file->max_x || y + i >= g->file->max_y)
				draw_brick(mm, j, i, MMEMPTY);
			else if (g->file->map[y + i + 2][x + j + 2] == '1')
				draw_brick(mm, j, i, MMWALL);
			else if (g->file->map[y + i + 2][x + j + 2] == '0')
				draw_brick(mm, j, i, MMFLOOR);
			else
				draw_brick(mm, j, i, MMEMPTY);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(g->mlx, g->win, mm.img, 0, 0);
	mlx_destroy_image(g->mlx, mm.img);
}


// minimap 13 x 11. Each coor = 16 pixels
void	minimap(t_graph *g)
{
	int		x;
	int		y;

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
}

