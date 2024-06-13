/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:04:16 by gforns-s          #+#    #+#             */
/*   Updated: 2024/06/13 17:36:29 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
loop for ray casting:

dimension of projected plane = 1920x1080
center of projection plane = 960,540
distance to the projection plane = 960 / tan(30) = 1662.768775266
angle of ray * column = 60/1920

void	loop_ray(t_data *data)
{
	int	x;

	x = 0;
	while (x < SIZE_X)
	{
		double data->gr->pova = 2 * x / (double)SIZE_X - 1;
		double ray_dir_x = dir_x + plane_x * data->gr->pova;
		double ray_dir_y = dir_y + plane_y * camera_x;
}

































*/
