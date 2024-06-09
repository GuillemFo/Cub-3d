/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:11 by codespace         #+#    #+#             */
/*   Updated: 2024/06/09 16:53:53 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_file(t_file *file)
{
	file->NO = NULL;
	file->SO = NULL;
	file->EA = NULL;
	file->WE = NULL;
	file->F_flag = 0;
	file->C_flag = 0;
	file->max_x= 0;
	file->max_y = 0;
	file->data_ok = 0;
	file->nb_player = 0;
}

void	init_data(t_data *data)
{
	data->file = malloc(sizeof(t_file));
	init_file(data->file);
	data->win = malloc(sizeof(t_mlx));
}

int	main(int ac, char **av)
{
	t_data	*data;

	init_data(data);
	check_args(ac, av, data);
	build_map(av, data->file);
	print_map_term(data->file->map);
	printf("hola\n");
}
