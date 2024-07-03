/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wil <wil@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:10:26 by gforns-s          #+#    #+#             */
/*   Updated: 2024/07/03 19:39:57 by wil              ###   ########.fr       */
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
	p->pova = fmod((p->pova + p->rots), 2 * M_PI);
	p->dirx = cos(p->pova);
	p->diry = -sin(p->pova);
	return (0);
}
