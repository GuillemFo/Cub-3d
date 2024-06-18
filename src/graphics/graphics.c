/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:43:09 by gforns-s          #+#    #+#             */
/*   Updated: 2024/06/18 08:19:00 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// mlx_hook(data->mlx->win, 2, 1L << 0, key_press, &data);
int	key_press(int keycode, t_data *data)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
		exit(0);
	}
	return (0);
}

int	esc_window(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
	    mlx_destroy_window(data->mlx->mlx, data->mlx->win);
		exit(0);
	}
	return (1);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	exit(0);
	return (1);
}

/*
old struct style.
void	missing_parser(t_data *data)
{
	data->gr.povy = 4;	player pos y
	data->gr.povx = 4;	player pos x
	data->gr.pova = 270; //south. player pos angle
	data->gr.bs = 512;	texture size
	data->gr.vh = 256;	player pov height
}
*/


int img_init(t_data *data)
{
	data->mlx->img = ft_calloc(1, sizeof(t_image));
    if (!data->mlx->img)
	{
        return (1);
	}
	data->mlx->img->img = mlx_new_image(data->mlx->mlx, WIN_X, WIN_Y);
    if (!data->mlx->img->img)
	{
        return (1);
	}
	data->mlx->img->addr = mlx_get_data_addr(data->mlx->mlx, &data->mlx->img->bpp, &data->mlx->img->ll, &data->mlx->img->en);
	return (0);
}


int	start_mlx(t_data *data)
{
	data->mlx->mlx = mlx_init();
    if (!data->mlx->mlx)
	{
        return (message("mlx initialitation error\n"), 1);
	}
	data->mlx->win = mlx_new_window(data->mlx->mlx, WIN_X, WIN_Y,
			"Cub3D gforns-s & josegar2");
    if (load_textures(data->file, data->mlx))
	{
		return (1);
	}
	if (img_init(data))
        return (message("Image creation error\n"), 1);
	// Been told to start first with a color innstead of image
	// maybe better to do a separate functionfor hooks and loop
    mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->txt[0].img, 0, 0);
	mlx_hook(data->mlx->win, KEYDOWN, 0, esc_window, data);
	mlx_hook(data->mlx->win, DESTROY, 1L << 0, close_window, data);
	mlx_loop(data->mlx->mlx);
    return (0);
}

//int	game_loop()??


int	main_game(t_data *data)
{
	start_mlx(data);
	mlx_put_image_to_window(data->mlx, data->mlx->win, data->mlx->img->img, 0, 0);

	return (0);
}

/*

    Obrir finestra --> OK
    Pintar alguna imatge a una posicio x,y, per exemple les mateixes textures --> imatge si, a posicio en concret no se
    Aconseguir que amb esc o la creu es tanqui la finestra --> OK
    Aconseguir que amb les tecles es canviin les coordenades povx, povy i l'angle povo
    Les funcions per en una columna y pintar el cealing
    
*/