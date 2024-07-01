/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wil <wil@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:10:26 by gforns-s          #+#    #+#             */
/*   Updated: 2024/07/01 16:54:48 by wil              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int player_w(t_player *p)
{
	p->povx += LINEAR_SPEED * p->dirx;
	p->povy += LINEAR_SPEED * p->diry;
	return (0);
}

int player_s(t_player *p)
{
	p->povx -= LINEAR_SPEED * p->dirx;
	p->povy -= LINEAR_SPEED * p->diry;
	return (0);
}

int player_a(t_player *p)
{
	p->povx += LINEAR_SPEED * p->diry;
	p->povy -= LINEAR_SPEED * p->dirx;
	return (0);
}

int player_d(t_player *p)
{
	p->povx -= LINEAR_SPEED * p->diry;
	p->povy += LINEAR_SPEED * p->dirx;
	return (0);
}

int player_left(t_player *p)
{
	p->pova = fmod((p->pova + ROTATION_SPEED), 2 * M_PI);
    p->dirx = cos(p->pova);
    p->diry = -sin(p->pova);
	return (0);
}

int player_right(t_player *p)
{
	p->pova -= ROTATION_SPEED;
	if (p->pova < 0)
	    p->pova += 2 * M_PI;
    p->dirx = cos(p->pova);
    p->diry = -sin(p->pova);
	return (0);
}

// get integer coordinate given the double value of the position
int i_coor(double pos)
{
    return ((int) pos / BLOCK_SIZE);
}

char    get_map_char(t_graph *g, double x, double y)
{
    return (g->file->map[i_coor(y) + 2][i_coor(x) + 2]);
}

bool	check_pmove(t_graph *g, char c)
{
	t_player tp;
    tp = g->p;

	if (c == 'w')
		player_w(&tp);
	else if (c == 's')
		player_s(&tp);
	else if (c == 'a')
		player_a(&tp);
	else if (c == 'd')
		player_d(&tp);
	else if (c == 'l')
		player_left(&tp);
	else if (c == 'r')
		player_right(&tp);
	if (get_map_char(g, tp.povx, tp.povy) != '0') 
		return (false);
    if (!((int)tp.povx % BLOCK_SIZE))
		if (get_map_char(g, tp.povx - 1, tp.povy) != '0')
        	return (false);
    if (!((int)tp.povy % BLOCK_SIZE))
		if (get_map_char(g, tp.povx, tp.povy - 1) != '0')
        	return (false);
	return (true);
}

int	p_moves(int keycode, t_graph *g)
{
	if (keycode == W_KEY)
	{
		if (check_pmove(g, 'w') == true)
			player_w(&g->p);
	//	ft_printf("X:%.2f Y:%.2f A:%f\n", g->p.povx, g->p.povy, g->p.pova* (180 / M_PI));
	//	ft_printf("X:%d Y:%d A:%f\n\n", i_coor(g->p.povx), i_coor(g->p.povy), g->p.pova* (180 / M_PI));
	}
	else if (keycode == S_KEY)
	{
		if (check_pmove(g, 's') == true)
			player_s(&g->p);
	//	ft_printf("X:%.2f Y:%.2f A:%f\n", g->p.povx, g->p.povy, g->p.pova* (180 / M_PI));
	//	ft_printf("X:%d Y:%d A:%f\n\n", i_coor(g->p.povx), i_coor(g->p.povy), g->p.pova* (180 / M_PI));
	}
	else if (keycode == A_KEY)
	{
		if (check_pmove(g, 'a') == true)
			player_a(&g->p);
	//	ft_printf("X:%.2f Y:%.2f A:%f\n", g->p.povx, g->p.povy, g->p.pova* (180 / M_PI));
	//	ft_printf("X:%d Y:%d A:%f\n\n", i_coor(g->p.povx), i_coor(g->p.povy), g->p.pova* (180 / M_PI));
	}
	else if (keycode == D_KEY)
	{
		if (check_pmove(g, 'd') == true)
			player_d(&g->p);
	//	ft_printf("X:%.2f Y:%.2f A:%f\n", g->p.povx, g->p.povy, g->p.pova* (180 / M_PI));
	//	ft_printf("X:%d Y:%d A:%f\n\n", i_coor(g->p.povx), i_coor(g->p.povy), g->p.pova* (180 / M_PI));
	}
	else if (keycode == LEFT_KEY)
	{
		if (check_pmove(g, 'l') == true)
			player_left(&g->p);
	//	ft_printf("X:%.2f Y:%.2f A:%f\n", g->p.povx, g->p.povy, g->p.pova* (180 / M_PI));
	//	ft_printf("X:%d Y:%d A:%f\n\n", i_coor(g->p.povx), i_coor(g->p.povy), g->p.pova* (180 / M_PI));
	}

	/// This key wont work correctly
	else if (keycode == RIGHT_KEY)
	{
		if (check_pmove(g, 'r') == true)
			player_right(&g->p);
	//	ft_printf("X:%.2f Y:%.2f A:%f\n", g->p.povx, g->p.povy, g->p.pova* (180 / M_PI));
	//	ft_printf("X:%d Y:%d A:%f\n\n", i_coor(g->p.povx), i_coor(g->p.povy), g->p.pova* (180 / M_PI));
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
