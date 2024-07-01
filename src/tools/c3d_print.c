/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wil <wil@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:18:04 by josegar2          #+#    #+#             */
/*   Updated: 2024/07/01 16:54:48 by wil              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map_term(t_file *file)
{
	int	i;

	i = 0;
	ft_printf("NO : %s\n", file->NO);
	ft_printf("SO : %s\n", file->SO);
	ft_printf("EA : %s\n", file->EA);
	ft_printf("WE : %s\n", file->WE);
	ft_printf("F : %d, %d, %d\n", file->F[0], file->F[1], file->F[2]);
	ft_printf("C : %d, %d, %d\n", file->C[0], file->C[1], file->C[2]);
	ft_printf("Start x: %d y: %d\n", file->stx, file->sty);
	ft_printf("Start orientation: %c\n", file->sto);
    ft_printf("Max X: %d Y: %d\n", file->max_x, file->max_y);
	while (i <= file->max_y + 3)
	{
		ft_printf("--%s--\n", file->map[i]);
		i++;
	}
}
