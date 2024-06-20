/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:10:26 by gforns-s          #+#    #+#             */
/*   Updated: 2024/06/18 13:35:53 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


//Pending to change to ints of block size instead of floatst

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

int player_left(t_player *p)
{
	p->pova += ROTATION_SPEED * p->pova;
	printf("X:%d Y:%d A:%f\n", p->povx, p->povy, p->pova);
	return (0);
}

int player_right(t_player *p)
{
	p->pova -= ROTATION_SPEED * p->pova;
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
	else if (keycode == ESC_KEY)
	{
		mlx_destroy_window(g->mlx, g->win);
		exit(0);
	}
	else
		return (1);
	return (0);
}