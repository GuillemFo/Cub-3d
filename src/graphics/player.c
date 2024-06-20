/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:10:26 by gforns-s          #+#    #+#             */
/*   Updated: 2024/06/20 12:13:38 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


// need to cap the pova to 2py max so when 2py is reached, next is 0;

int player_w(t_player *p)
{
	p->povx += LINEAR_SPEED * cos(p->pova);
	p->povy -= LINEAR_SPEED * sin(p->pova);
	printf("X:%d Y:%d A:%f\n", p->povx, p->povy, p->pova);
	return (0);
}

int player_s(t_player *p)
{
	p->povx += LINEAR_SPEED * cos(p->pova);
	p->povy += LINEAR_SPEED * sin(p->pova);
	printf("X:%d Y:%d A:%f\n", p->povx, p->povy, p->pova);
	return (0);
}

int player_a(t_player *p)
{
	p->povx -= LINEAR_SPEED * sin(p->pova);
	p->povy += LINEAR_SPEED * cos(p->pova);
	printf("X:%d Y:%d A:%f\n", p->povx, p->povy, p->pova);
	return (0);
}

int player_d(t_player *p)
{
	p->povx += LINEAR_SPEED * sin(p->pova);
	p->povy += LINEAR_SPEED * cos(p->pova);
	printf("X:%d Y:%d A:%f\n", p->povx, p->povy, p->pova);
	return (0);
}


/*
// Normalize angle to be within [-inf, inf)
angle = fmod(angle, 2 * M_PI);
if (angle < 0) 
{
    angle += 2 * M_PI; // Ensure angle is non-negative
}
*/


int player_left(t_player *p)
{
	p->pova = fmod((p->pova + ROTATION_SPEED), 2 * M_PI);
	printf("X:%d Y:%d A:%f\n", p->povx, p->povy, p->pova);
	return (0);
}

int player_right(t_player *p)
{
	p->pova -= ROTATION_SPEED;
	if (p->pova < 0)
	p->pova += 2 * M_PI;
	printf("X:%d Y:%d A:%f\n", p->povx, p->povy, p->pova);
	return (0);
}


int	p_moves(int keycode, t_graph *g)
{
	if (keycode == W_KEY)
	{
		//check if possible
		player_w(&g->p);
	}
	else if (keycode == S_KEY)
	{
		player_s(&g->p);
	}
	else if (keycode == A_KEY)
	{
		player_a(&g->p);
	}
	else if (keycode == D_KEY)
	{
		player_d(&g->p);
	}
	else if (keycode == LEFT_KEY)
	{
		player_left(&g->p);
	}
	else if (keycode == RIGHT_KEY)
	{
		player_right(&g->p);
	}
	//pending to move, cant call keydown hooks multiple times.
	//will only listen to the last one
	else if (keycode == ESC_KEY)
	{
		mlx_destroy_window(g->mlx, g->win);
		exit(0);
	}
	else
		return (1);
	return (0);
}