/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:11 by codespace         #+#    #+#             */
/*   Updated: 2024/05/25 02:23:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		if (ac == 1)
			return (printf("Missing map\n"), 1);
		else if (ac > 2)
			return (printf("Too many arguments\n"), 1);
	}
	check_args(av);
	printf("hola\n");
}