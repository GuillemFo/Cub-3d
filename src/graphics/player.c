/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:10:26 by gforns-s          #+#    #+#             */
/*   Updated: 2024/06/18 10:45:06 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	p_moves(int keycode, t_data *data)
{
	if (keycode == W_KEY)
	{
		//check if possible
		player_w(data->g->p);
	}
	else if (keycode == S_KEY)
	{
		player_s(data->g->p);
	}
	else if (keycode == A_KEY)
	{
		player_a(data->g->p);
	}
	else if (keycode == D_KEY)
	{
		player_d(data->g->p);
	}
}

float player_w(t_player p)
{
	p.ppy+= 0.10;
}
float player_s(t_player p)
{
	p.ppy-= 0.10;
}
float player_a(t_player p)
{
	p.ppx-= 0.10;
}
float player_d(t_player p)
{
	p.ppx+= 0.10;
}
