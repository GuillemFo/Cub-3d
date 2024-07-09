/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:12:38 by gforns-s          #+#    #+#             */
/*   Updated: 2024/07/09 17:12:55 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	m_press(int keycode, int x, int y, t_graph *g)
{
	(void)x;
	(void)y;
	if (keycode == 1)
		g->m_flag = 1;
	return (0);
}

int	m_release(int keycode, int x, int y, t_graph *g)
{
	(void)x;
	(void)y;
	if (keycode == 1)
		g->m_flag = 0;
	return (0);
}

int	m_moves(int x, int y, t_graph *g)
{
	(void)y;
	if (g->m_flag == 0)
		return (0);
	if (g->m_count++ % ROT_SPEED_M)
		return (0);
	else if ((x <= (WIN_X / 2)) && g->m_flag == 1)
	{
		if (check_pmove(g, 'l') == true)
			player_left(&g->p);
	}
	else if ((x > (WIN_X / 2)) && g->m_flag == 1)
	{
		if (check_pmove(g, 'r') == true)
			player_right(&g->p);
	}
	g->m_count = 1;
	return (0);
}
