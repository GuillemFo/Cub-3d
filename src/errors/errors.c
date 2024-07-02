/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:26:12 by codespace         #+#    #+#             */
/*   Updated: 2024/06/15 11:47:33 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//	Been told to use exit and quit this
//	The kill_phase are intended to be a proper cleanup depending onn what stage
//	we have to kill the program and for what reason
void	message(char *msg)
{
	printf("Error\n%s", msg);
}

//starge 1 == only texture malloc
//starge 2 == call stage 1, RGB ints
//starge 3 == call stage 2, clean map
void	kill_phase_0(int stage)	//parsing -> loading textures, map and rgb
{
	(void)stage;
}

//Creating window for mlx, textures not working or else
void	kill_phase_1(void)
{
}

void	kill_phase_2(void)
{
}

void	kill_phase_3(void)
{
}
