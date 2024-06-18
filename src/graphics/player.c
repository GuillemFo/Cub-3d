/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:10:26 by gforns-s          #+#    #+#             */
/*   Updated: 2024/06/18 12:01:16 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	p_moves(int keycode, t_graph *g)
{
	if (keycode == W_KEY)
	{
		//check if possible
		player_w(g->p);
	}
	else if (keycode == S_KEY)
	{
		player_s(g->p);
	}
	else if (keycode == A_KEY)
	{
		player_a(g->p);
	}
	else if (keycode == D_KEY)
	{
		player_d(g->p);
	}
}

//Pending to change to ints of block size instead of floats

int player_w(t_player p)
{
	p.povy += LINEAR_SPEED;
}
int player_s(t_player p)
{
	p.povy-= 0.10;
}
int player_a(t_player p)
{
	p.povx-= 0.10;
}
int player_d(t_player p)
{
	p.povx+= 0.10;
}
