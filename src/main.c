/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:11 by codespace         #+#    #+#             */
/*   Updated: 2024/06/28 00:52:50 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void    set_start(t_data *data)
{
    data->g->p.bs = BLOCK_SIZE;
    data->g->p.vh = VIEW_HEIGHT;
    data->g->p.fov = FIELD_OF_VIEW;
    data->g->p.angs = ANGULAR_STEP;
    data->g->p.lins = LINEAR_SPEED;
    data->g->p.rots = ROTATION_SPEED;
    data->g->p.povx = data->file->stx * BLOCK_SIZE;
    data->g->p.povx += (BLOCK_SIZE > 1) * BLOCK_SIZE / 2;
    data->g->p.povy = data->file->sty * BLOCK_SIZE; 
    data->g->p.povy += (BLOCK_SIZE > 1) * BLOCK_SIZE / 2;
    if (data->file->sto == 'N')
        data->g->p.pova = (90 * M_PI) / 180;
    else if (data->file->sto == 'S')
        data->g->p.pova = (270 * M_PI) / 180;
    else if (data->file->sto == 'W')
        data->g->p.pova = M_PI;
    else if (data->file->sto == 'E')
        data->g->p.pova = 0;
    data->g->rgbc = (data->file->C[0] << 16) + (data->file->C[1] << 8);
    data->g->rgbc += data->file->C[2];
    data->g->rgbf = (data->file->F[0] << 16) + (data->file->F[1] << 8);
    data->g->rgbf += data->file->F[2];
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
		return (1);
	print_map_term(data->file);
    set_start(data);
	if (start_mlx(data))
        return (c3d_free(data), 1);
	printf("hola\n");
	c3d_free(data);
    return (0);
}
