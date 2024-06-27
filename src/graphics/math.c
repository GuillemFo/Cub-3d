/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:04:16 by gforns-s          #+#    #+#             */
/*   Updated: 2024/06/27 10:29:40 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    get_first_hit(t_ray *r)	
{
    r->dir_x = cos(r->raya);
    r->dir_y = -sin(r->raya);
    r->fvhx = (i_coor(r->pos_x) + (r->dir_x > 0)) * BLOCK_SIZE;
    if (r->dir_x == 0)
        r->fvhy = -1;
    else
        r->fvhy = (r->fvhx - r->pos_x) * r->dir_y / r->dir_x + r->pos_y;
    r->fhhy = (i_coor(r->pos_y) + (r->dir_y > 0)) * BLOCK_SIZE;
    if (r->dir_y == 0)
        r->fhhx = -1;
    else
        r->fhhx = (r->fhhy - r->pos_y) * r->dir_x / r->dir_y + r->pos_x;
    printf("Vertical hit X : %.2f Y : %.2f\n", r->fvhx, r->fvhy);
    printf("Horizontal hit X : %.2f Y : %.2f\n", r->fhhx, r->fhhy);
}

int	ray_inside(t_file *f, double x, double y)
{
	int grid_x;
	int grid_y;

	grid_x = (int)(x / BLOCK_SIZE);
	grid_y = (int)(y / BLOCK_SIZE);

printf("Y=%d-- X=%d--\n", f->max_y, f->max_x -1);
	if (grid_y >= 0 && grid_y < f->max_y -1)
	{
		ft_printf("1\n");
		if (grid_x >= 0 && grid_x < f->max_x - 1) //added -1 to compensate for array starting at 0.
		{
			ft_printf("2\n");
			ft_printf("is %c\n", f->map[ 2 + grid_y][ 2 + grid_x]);
			if (f->map[2 + grid_y][2 + grid_x] != '1' && f->map[2 + grid_y][2 + grid_x] != ' ') ////the +2 is due extra space around the map to not read out of memory
				return (1);
		}
		ft_printf("3\n");
	}
	return (0);

}


void    loop_rays(t_graph *g)
{
    int i;

    g->ray.pos_x = g->p.povx;
    g->ray.pos_y = g->p.povy;
    g->ray.raya = g->p.pova + FIELD_OF_VIEW / 2;
    if (g->ray.raya > 2 * M_PI)
        g->ray.raya -= 2 * M_PI;
    i = 0;
    if (i < WIN_X)	// while (i++ < WIN_X)
    {
        get_first_hit(&g->ray);
		if (ray_inside(g->file, g->ray.fvhx, g->ray.fvhy) && ray_inside(g->file, g->ray.fhhx, g->ray.fhhy))
		{
			if (g->ray.fvhy <= g->ray.fhhy && g->ray.fvhx <= g->ray.fhhx)
			{
				if (g->file->map[2 + (int)g->ray.fvhy / BLOCK_SIZE][2 + (int)g->ray.fvhx / BLOCK_SIZE] == '1')
					printf("Ver hit\n");
				else
					printf("Ver miss\n");
			}
			else
			{
				if (g->file->map[2 + (int)g->ray.fhhy / BLOCK_SIZE][2 + (int)g->ray.fhhx / BLOCK_SIZE] == '1')
					printf("Hor hit\n");
				else
					printf("Hor miss\n");
			}
			// if we miss in both directions, then we loop again. *Apply bottom formula
		}
		else
            printf("Ray out of bounds\n");
	}
}
/*
int	loop_ray_throw()
{
	while (g->ray.hit == false)
	{
		C.x=A.x+Xa;
		C.y=A.y+Ya;
		if (g->file->map[C.y][C.x] == '1')
		{
			g->ray.hit = true;
			break ;
		}
		A.x = C.x;
		A.y = C.y;
	}
	return (From here call draw column);
}
*/

