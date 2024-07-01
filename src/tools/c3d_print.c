/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:18:04 by josegar2          #+#    #+#             */
/*   Updated: 2024/06/28 00:45:43 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map_term(t_file *file)
{
	int	i;

	i = 0;
	printf("NO : %s\n", file->NO);
	printf("SO : %s\n", file->SO);
	printf("EA : %s\n", file->EA);
	printf("WE : %s\n", file->WE);
	printf("F : %d, %d, %d\n", file->F[0], file->F[1], file->F[2]);
	printf("C : %d, %d, %d\n", file->C[0], file->C[1], file->C[2]);
	printf("Start x: %d y: %d\n", file->stx, file->sty);
	printf("Start orientation: %c\n", file->sto);
    printf("Max X: %d Y: %d\n", file->max_x, file->max_y);
	while (i <= file->max_y + 3)
	{
		printf("--%s--\n", file->map[i]);
		i++;
	}
}
