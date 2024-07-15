/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:59:40 by codespace         #+#    #+#             */
/*   Updated: 2024/07/15 12:02:09 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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
	int			i;

	tp = g->p;
	i = 0;
	while (i++ < LINEAR_SPEED)
	{
		if (c == 'w')
			player_w(&tp, 1);
		else if (c == 's')
			player_s(&tp, 1);
		else if (c == 'a')
			player_a(&tp, 1);
		else if (c == 'd')
			player_d(&tp, 1);
		else if (c == 'l')
			player_left(&tp);
		else if (c == 'r')
			player_right(&tp);
		if (get_map_char(g, tp.povx, tp.povy) != '0')
			return (false);
		if (check_around(g, tp) == false)
			return (false);
	}
	return (true);
}
