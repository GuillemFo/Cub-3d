/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:46:15 by josegar2          #+#    #+#             */
/*   Updated: 2024/07/06 23:35:52 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	x_destroy_img2(t_graph *mx)
{
	if (mx->cei.addr)
	{
		mlx_destroy_image(mx->mlx, mx->cei.img);
		mx->cei.addr = NULL;
	}
	if (mx->flo.addr)
	{
		mlx_destroy_image(mx->mlx, mx->flo.img);
		mx->flo.addr = NULL;
	}
}

void	x_destroy_img(t_graph *mx)
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
		i++;
	}
	if (mx->i.addr)
	{
		mlx_destroy_image(mx->mlx, mx->i.img);
		mx->i.addr = NULL;
	}
	if (mx->mm.addr)
	{
		mlx_destroy_image(mx->mlx, mx->mm.img);
		mx->mm.addr = NULL;
	}
	x_destroy_img2(mx);
}

t_image	get_xpm_img(t_graph *mx, char *fn)
{
	t_image	rim;

	rim.addr = NULL;
	rim.img = mlx_xpm_file_to_image(mx->mlx, fn, &rim.w, &rim.h);
	if (!rim.img)
		return (rim);
	rim.addr = mlx_get_data_addr(rim.img, &rim.bpp, &rim.ll, &rim.en);
	return (rim);
}

int	load_textures(t_file *fl, t_graph *mx)
{
	mx->txt[0] = get_xpm_img(mx, fl->no);
	mx->txt[1] = get_xpm_img(mx, fl->so);
	mx->txt[2] = get_xpm_img(mx, fl->ea);
	mx->txt[3] = get_xpm_img(mx, fl->we);
	mx->cei = get_xpm_img(mx, CEILING);
	mx->flo = get_xpm_img(mx, FLOOR);
	if (!mx->txt[0].addr || !mx->txt[1].addr || !mx->txt[2].addr
		|| !mx->txt[3].addr || !mx->cei.addr || !mx->flo.addr)
	{
		message("Can't load texture files\n");
		return (1);
	}
	return (0);
}
