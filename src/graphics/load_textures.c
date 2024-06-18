/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:46:15 by josegar2          #+#    #+#             */
/*   Updated: 2024/06/17 21:36:38 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	x_destroy_img(t_mlx *mx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (mx->txt[i].addr != NULL)
		{
			mlx_destroy_image(mx->mlx, mx->txt[i].img);
			mx->txt[i].addr = NULL;
		}
	}
	if (!mx->img && !mx->img->addr)
	{
		mlx_destroy_image(mx->mlx, mx->img->img);
		mx->img->addr = NULL;
	}
}

t_image	get_xpm_img(t_mlx *mx, char *fn)
{
	t_image	rim;

	rim.addr = NULL;
	rim.img = mlx_xpm_file_to_image(mx->mlx, fn, &rim.w, &rim.h);
	if (!rim.img)
		return (rim);
	rim.addr = mlx_get_data_addr(rim.img, &rim.bpp, &rim.ll, &rim.en);
	return (rim);
}

int	load_textures(t_file *fl, t_mlx *mx)
{
	mx->txt[0] = get_xpm_img(mx, fl->NO);
	mx->txt[1] = get_xpm_img(mx, fl->SO);
	mx->txt[2] = get_xpm_img(mx, fl->EA);
	mx->txt[3] = get_xpm_img(mx, fl->WE);
	if (!mx->txt[0].addr || !mx->txt[1].addr || !mx->txt[2].addr
		|| !mx->txt[3].addr)
	{
		message("Can't load texture files\n");
		return (1);
	}
	return (0);
}