/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:11 by codespace         #+#    #+#             */
/*   Updated: 2024/06/12 11:48:11 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_data	*init_data()
{
    t_data  *ldata;

	ldata = ft_calloc(1, sizeof(t_data));
	if (!ldata)
		return (NULL);
	ldata->file = ft_calloc(1, sizeof(t_file));
	if (!ldata->file)
		return (ft_free(ldata));
	ldata->win = ft_calloc(1, sizeof(t_mlx));
	if (!ldata->win)
		ldata = c3d_free(ldata);
	return (ldata);
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
	// print_map_term(data->file);
	printf("hola\n");
}
