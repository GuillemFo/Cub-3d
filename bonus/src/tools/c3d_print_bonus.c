/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_print_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:18:04 by josegar2          #+#    #+#             */
/*   Updated: 2024/07/15 12:37:05 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D_bonus.h"

void	print_map_term(t_file *file)
{
	int	i;

	i = 0;
	printf("NO : %s\n", file->no);
	printf("SO : %s\n", file->so);
	printf("EA : %s\n", file->ea);
	printf("WE : %s\n", file->we);
	printf("F : %d, %d, %d\n", file->f[0], file->f[1], file->f[2]);
	printf("C : %d, %d, %d\n", file->c[0], file->c[1], file->c[2]);
	printf("Start x: %d y: %d\n", file->stx, file->sty);
	printf("Start orientation: %c\n", file->sto);
	printf("Max X: %d Y: %d\n", file->max_x, file->max_y);
	while (i <= file->max_y + 3)
	{
		printf("--%s--\n", file->map[i]);
		i++;
	}
}

void	message(char *msg)
{
	printf("Error\n%s", msg);
}
