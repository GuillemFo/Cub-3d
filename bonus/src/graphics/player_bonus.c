/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:10:26 by gforns-s          #+#    #+#             */
/*   Updated: 2024/07/15 12:36:27 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D_bonus.h"

int	player_w(t_player *p, int speed)
{
	p->povx += speed * p->dirx;
	p->povy += speed * p->diry;
	return (0);
}

int	player_s(t_player *p, int speed)
{
	p->povx -= speed * p->dirx;
	p->povy -= speed * p->diry;
	return (0);
}

int	player_a(t_player *p, int speed)
{
	p->povx += speed * p->diry;
	p->povy -= speed * p->dirx;
	return (0);
}

int	player_d(t_player *p, int speed)
{
	p->povx -= speed * p->diry;
	p->povy += speed * p->dirx;
	return (0);
}

int	player_left(t_player *p)
{
	p->pova = fmod((p->pova + p->rots), 2 * M_PI);
	p->dirx = cos(p->pova);
	p->diry = -sin(p->pova);
	return (0);
}
