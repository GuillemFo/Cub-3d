/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:01:40 by codespace         #+#    #+#             */
/*   Updated: 2024/07/03 16:23:07 by codespace        ###   ########.fr       */
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
	if (keycode == W_KEY)
	{
		if (check_pmove(g, 'w') == true)
			player_w(&g->p);
	}
	else if (keycode == S_KEY)
	{
		if (check_pmove(g, 's') == true)
			player_s(&g->p);
	}
	else if (keycode == A_KEY)
	{
		if (check_pmove(g, 'a') == true)
			player_a(&g->p);
	}
	else if (keycode == D_KEY)
	{
		if (check_pmove(g, 'd') == true)
			player_d(&g->p);
	}
	else if (keycode == LEFT_KEY || keycode == RIGHT_KEY || keycode == ESC_KEY)
		other_moves(keycode, g);
	loop_rays(g);
	return (0);
}

int	m_moves(int keycode, t_graph *g)
{
	(void)g;
	ft_printf("%d\n", keycode);
return (0);
}
