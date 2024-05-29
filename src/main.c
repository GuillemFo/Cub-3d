/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:11 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 14:17:19 by codespace        ###   ########.fr       */
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

	data = malloc(sizeof(t_data));
	init_data(data);
	check_args(ac, av, data);
	printf("hola\n");
}
