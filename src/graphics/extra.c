/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wil <wil@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:46:16 by wil               #+#    #+#             */
/*   Updated: 2024/07/04 19:30:24 by wil              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int	apply_rgb_filter(unsigned int color, int *c)
{
	unsigned char	new_r;
	unsigned char	new_g;
	unsigned char	new_b;
	unsigned int	new_color;

	new_r = (((unsigned char *)&color)[2] * c[0]) / 255;
	new_g = (((unsigned char *)&color)[1] * c[1]) / 255;
	new_b = (((unsigned char *)&color)[0] * c[2]) / 255;
	((unsigned char *)&new_color)[2] = new_r;
	((unsigned char *)&new_color)[1] = new_g;
	((unsigned char *)&new_color)[0] = new_b;
	return (new_color);
}

int	get_texture_color2(t_image im, int x, int y, int *c)
{
	char			*dst;
	unsigned int	color;

	dst = im.addr + (y * im.ll + x * (im.bpp / 8));
	color = *(unsigned int *)dst;
	return (apply_rgb_filter(color, c));
}
