/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:11 by codespace         #+#    #+#             */
/*   Updated: 2024/05/28 13:11:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_data(t_data data)
{
	data.file = malloc(sizeof(t_file));
	data.win = malloc(sizeof(t_mlx));
}


int	main(int ac, char **av)
{
	t_data	data;

	init_data(data);
	check_args(ac, av, data);
	printf("hola\n");
}