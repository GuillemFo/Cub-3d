/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:04:16 by gforns-s          #+#    #+#             */
/*   Updated: 2024/06/19 13:08:40 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
loop for ray casting:

dimension of projected plane = 1920x1080
center of projection plane = 960,540
distance to the projection plane = 960 / tan(30) = 1662.768775266
angle of ray * column = 60/1920

void	loop_ray(t_data *data)	// under dev... rn makes no sense
{
	
}

float better than double and use vectorial instead of angular calc.


*/
void	player_to_ray(t_graph *g)
{
	g->ray.pos_x = g->p.povx;
	g->ray.pos_y = g->p.povy;
}































