/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:11 by codespace         #+#    #+#             */
/*   Updated: 2024/07/15 12:05:32 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_data	*init_data(void)
{
	t_data	*ldata;

	ldata = ft_calloc(1, sizeof(t_data));
	if (!ldata)
		return (NULL);
	ldata->file = ft_calloc(1, sizeof(t_file));
	if (!ldata->file)
		return (ft_free(ldata));
	ldata->g = ft_calloc(1, sizeof(t_graph));
	if (!ldata->g)
		ldata = c3d_free(ldata);
	return (ldata);
}

void	set_start(t_graph *g, t_file *f)
{
	g->p.bs = BLOCK_SIZE;
	g->p.vh = VIEW_HEIGHT;
	g->p.fov = (FOV * M_PI) / 180;
	g->p.ppd = (WIN_X / 2) / tan(g->p.fov / 2);
	g->p.angs = ((FOV * M_PI) / 180) / WIN_X;
	g->p.lins = LINEAR_SPEED;
	g->p.rots = (ROT_SPEED * M_PI) / 180;
	g->p.povx = f->stx * BLOCK_SIZE;
	g->p.povx += (BLOCK_SIZE > 1) * BLOCK_SIZE / 2;
	g->p.povy = f->sty * BLOCK_SIZE;
	g->p.povy += (BLOCK_SIZE > 1) * BLOCK_SIZE / 2;
	if (f->sto == 'N')
		g->p.pova = (90 * M_PI) / 180;
	else if (f->sto == 'S')
		g->p.pova = (270 * M_PI) / 180;
	else if (f->sto == 'W')
		g->p.pova = M_PI;
	else if (f->sto == 'E')
		g->p.pova = 0;
	g->p.dirx = cos(g->p.pova);
	g->p.diry = -sin(g->p.pova);
	g->rgbc = (f->c[0] << 16) + (f->c[1] << 8);
	g->rgbc += f->c[2];
	g->rgbf = (f->f[0] << 16) + (f->f[1] << 8);
	g->rgbf += f->f[2];
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (check_args(ac, av) == 1)
		return (1);
	data = init_data();
	if (!data)
		return (message("Data initialization error\n"), 1);
	if (check_map(data->file, av[1]))
		return (c3d_free(data), 1);
	if (build_map(av, data->file) == 1)
		return (c3d_free(data), 1);
	set_start(data->g, data->file);
	if (start_mlx(data))
		return (c3d_free(data), 1);
	c3d_free(data);
	return (0);
}
