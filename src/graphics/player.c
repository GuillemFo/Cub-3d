/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:10:26 by gforns-s          #+#    #+#             */
/*   Updated: 2024/06/27 11:25:26 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int player_w(t_player *p)
{
	p->povx += LINEAR_SPEED * cos(p->pova);
	p->povy -= LINEAR_SPEED * sin(p->pova);
	return (0);
}

int player_s(t_player *p)
{
	p->povx += LINEAR_SPEED * cos(p->pova);
	p->povy += LINEAR_SPEED * sin(p->pova);
	return (0);
}

int player_a(t_player *p)
{
	p->povx -= LINEAR_SPEED * sin(p->pova);
	p->povy += LINEAR_SPEED * cos(p->pova);
	return (0);
}

int player_d(t_player *p)
{
	p->povx += LINEAR_SPEED * sin(p->pova);
	p->povy += LINEAR_SPEED * cos(p->pova);
	return (0);
}

int player_left(t_player *p)
{
	p->pova = fmod((p->pova + ROTATION_SPEED), 2 * M_PI);
	return (0);
}

int player_right(t_player *p)
{
	p->pova -= ROTATION_SPEED;
	if (p->pova < 0)
	p->pova += 2 * M_PI;
	return (0);
}

// get integer coordinate given the double value of the position
int i_coor(double pos)
{
    return (trunc(pos / BLOCK_SIZE));
}

char    get_map_char(t_graph *g, double x, double y)
{
    return (g->file->map[i_coor(y) + 2][i_coor(x) + 2]);
}

bool	check_pmove(t_graph *g, char c)
{
	t_player tmp;
	tmp.povx = g->p.povx;
	tmp.povy = g->p.povy;
	tmp.pova = g->p.pova;

	if (c == 'w')
		player_w(&tmp);
	else if (c == 's')
		player_s(&tmp);
	else if (c == 'a')
		player_a(&tmp);
	else if (c == 'd')
		player_d(&tmp);
	else if (c == 'l')
		player_left(&tmp);
	else if (c == 'r')
		player_right(&tmp);
	if (get_map_char(g, tmp.povx, tmp.povy) == '1') 
		return (false);
	return (true);
}

int	p_moves(int keycode, t_graph *g)
{
	if (keycode == W_KEY)
	{
		if (check_pmove(g, 'w') == true)
			player_w(&g->p);
	//	printf("X:%.2f Y:%.2f A:%f\n", g->p.povx, g->p.povy, g->p.pova* (180 / M_PI));
	//	printf("X:%d Y:%d A:%f\n\n", i_coor(g->p.povx), i_coor(g->p.povy), g->p.pova* (180 / M_PI));
	}
	else if (keycode == S_KEY)
	{
		if (check_pmove(g, 's') == true)
			player_s(&g->p);
	//	printf("X:%.2f Y:%.2f A:%f\n", g->p.povx, g->p.povy, g->p.pova* (180 / M_PI));
	//	printf("X:%d Y:%d A:%f\n\n", i_coor(g->p.povx), i_coor(g->p.povy), g->p.pova* (180 / M_PI));
	}
	else if (keycode == A_KEY)
	{
		if (check_pmove(g, 'a') == true)
			player_a(&g->p);
	//	printf("X:%.2f Y:%.2f A:%f\n", g->p.povx, g->p.povy, g->p.pova* (180 / M_PI));
	//	printf("X:%d Y:%d A:%f\n\n", i_coor(g->p.povx), i_coor(g->p.povy), g->p.pova* (180 / M_PI));
	}
	else if (keycode == D_KEY)
	{
		if (check_pmove(g, 'd') == true)
			player_d(&g->p);
	//	printf("X:%.2f Y:%.2f A:%f\n", g->p.povx, g->p.povy, g->p.pova* (180 / M_PI));
	//	printf("X:%d Y:%d A:%f\n\n", i_coor(g->p.povx), i_coor(g->p.povy), g->p.pova* (180 / M_PI));
	}
	else if (keycode == LEFT_KEY)
	{
		if (check_pmove(g, 'l') == true)
			player_left(&g->p);
	//	printf("X:%.2f Y:%.2f A:%f\n", g->p.povx, g->p.povy, g->p.pova* (180 / M_PI));
	//	printf("X:%d Y:%d A:%f\n\n", i_coor(g->p.povx), i_coor(g->p.povy), g->p.pova* (180 / M_PI));
	}

	/// This key wont work correctly
	else if (keycode == RIGHT_KEY)
	{
		if (check_pmove(g, 'r') == true)
			player_right(&g->p);
	//	printf("X:%.2f Y:%.2f A:%f\n", g->p.povx, g->p.povy, g->p.pova* (180 / M_PI));
	//	printf("X:%d Y:%d A:%f\n\n", i_coor(g->p.povx), i_coor(g->p.povy), g->p.pova* (180 / M_PI));
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
    loop_rays(g);
	return (0);
}
