/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:10:26 by gforns-s          #+#    #+#             */
/*   Updated: 2024/07/03 13:05:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	player_w(t_player *p)
{
	p->povx += LINEAR_SPEED * p->dirx;
	p->povy += LINEAR_SPEED * p->diry;
	return (0);
}

int	player_s(t_player *p)
{
	p->povx -= LINEAR_SPEED * p->dirx;
	p->povy -= LINEAR_SPEED * p->diry;
	return (0);
}

int	player_a(t_player *p)
{
	p->povx += LINEAR_SPEED * p->diry;
	p->povy -= LINEAR_SPEED * p->dirx;
	return (0);
}

int	player_d(t_player *p)
{
	p->povx -= LINEAR_SPEED * p->diry;
	p->povy += LINEAR_SPEED * p->dirx;
	return (0);
}

int	player_left(t_player *p)
{
	p->pova = fmod((p->pova + ROTATION_SPEED), 2 * M_PI);
	p->dirx = cos(p->pova);
	p->diry = -sin(p->pova);
	return (0);
}
