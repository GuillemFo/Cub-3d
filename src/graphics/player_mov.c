/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:01:40 by codespace         #+#    #+#             */
/*   Updated: 2024/07/09 17:12:27 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	other_moves(int keycode, t_graph *g)
{
	if (keycode == LEFT_KEY)
	{
		if (check_pmove(g, 'l') == true)
			player_left(&g->p);
	}
	else if (keycode == RIGHT_KEY)
	{
		if (check_pmove(g, 'r') == true)
			player_right(&g->p);
	}
	else if (keycode == ESC_KEY)
	{
		mlx_destroy_window(g->mlx, g->win);
		exit(0);
	}
	return (0);
}

int	p_moves(int keycode, t_graph *g)
{
	if (keycode == W_KEY && check_pmove(g, 'w') == true)
		player_w(&g->p, LINEAR_SPEED);
	else if (keycode == S_KEY && check_pmove(g, 's') == true)
		player_s(&g->p, LINEAR_SPEED);
	else if (keycode == A_KEY && check_pmove(g, 'a') == true)
		player_a(&g->p, LINEAR_SPEED);
	else if (keycode == D_KEY && check_pmove(g, 'd') == true)
		player_d(&g->p, LINEAR_SPEED);
	else if (keycode == LEFT_KEY || keycode == RIGHT_KEY || keycode == ESC_KEY)
		other_moves(keycode, g);
	else if (keycode == M_KEY)
		g->mm_on = (g->mm_on != 1);
	return (0);
}

bool	check_around(t_graph *g, t_player tp)
{
	if (!((int)tp.povx % BLOCK_SIZE))
		if (get_map_char(g, tp.povx - 1, tp.povy) != '0')
			return (false);
	if (!((int)tp.povy % BLOCK_SIZE))
		if (get_map_char(g, tp.povx, tp.povy - 1) != '0')
			return (false);
	if (!((int)tp.povx % BLOCK_SIZE) && !((int)tp.povy % BLOCK_SIZE))
		if (get_map_char(g, tp.povx - 1, tp.povy - 1) != '0')
			return (false);
	return (true);
}
