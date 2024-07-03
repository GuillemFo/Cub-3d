/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wil <wil@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:59:40 by codespace         #+#    #+#             */
/*   Updated: 2024/07/03 19:40:15 by wil              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	player_right(t_player *p)
{
	p->pova -= p->rots;
	if (p->pova < 0)
		p->pova += 2 * M_PI;
	p->dirx = cos(p->pova);
	p->diry = -sin(p->pova);
	return (0);
}

// get integer coordinate given the double value of the position
int	i_coor(double pos)
{
	return ((int)pos / BLOCK_SIZE);
}

char	get_map_char(t_graph *g, double x, double y)
{
	return (g->file->map[i_coor(y) + 2][i_coor(x) + 2]);
}

bool	check_pmove(t_graph *g, char c)
{
	t_player	tp;

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
