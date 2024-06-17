/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:11 by codespace         #+#    #+#             */
/*   Updated: 2024/06/18 00:17:28 by josegar2         ###   ########.fr       */
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
	ldata->mlx = ft_calloc(1, sizeof(t_mlx));
	if (!ldata->mlx)
		ldata = c3d_free(ldata);
	return (ldata);
}

void    set_start(t_data *data)
{
    data->player.bs = BLOCK_SIZE;
    data->player.vh = VIEW_HEIGHT;
    data->player.fov = FIELD_OF_VIEW;
    data->player.angs = ANGULAR_STEP;
    data->player.lins = LINEAR_SPEED;
    data->player.rots = ROTATION_SPEED;
    data->player.povx = data->file->stx * BLOCK_SIZE + BLOCK_SIZE / 2;
    data->player.povy = data->file->sty * BLOCK_SIZE + BLOCK_SIZE / 2;
    if (data->file->sto == 'N')
        data->player.pova = (90 * M_PI) / 180;
    else if (data->file->sto == 'S')
        data->player.pova = (270 * M_PI) / 180;
    else if (data->file->sto == 'W')
        data->player.pova = M_PI;
    else if (data->file->sto == 'E')
        data->player.pova = 0;
    data->mlx->rgbc = (data->file->C[0] << 16) + (data->file->C[1] << 8);
    data->mlx->rgbc += data->file->C[2];
    data->mlx->rgbf = (data->file->F[0] << 16) + (data->file->F[1] << 8);
    data->mlx->rgbf += data->file->F[2];
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
