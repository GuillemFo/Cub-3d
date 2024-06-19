/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:43:09 by gforns-s          #+#    #+#             */
/*   Updated: 2024/06/19 22:04:11 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// mlx_hook(data->mlx->win, 2, 1L << 0, key_press, &data);
int	key_press(int keycode, t_graph *g)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(g->mlx, g->win);
		exit(0);
	}
    else
    {
        mlx_put_image_to_window(g->mlx, g->win, g->i.img, 0, 0);
        mlx_do_sync(g->mlx);
    }
	return (0);
}

int	esc_window(int keycode, t_graph *g)
{
	if (keycode == ESC_KEY)
	{
	    mlx_destroy_window(g->mlx, g->win);
		exit(0);
	}
	return (1);
}

int	close_window(t_graph *g)
{
	mlx_destroy_window(g->mlx, g->win);
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


int img_init(t_graph *g)
{
	g->i.img = mlx_new_image(g->mlx, WIN_X, WIN_Y);
    if (!g->i.img)
	{
        return (1);
	}
	g->i.addr = mlx_get_data_addr(g->i.img, &(g->i.bpp), &(g->i.ll), &(g->i.en));
    return (0);
}


int	start_mlx(t_data *data)
{
	data->g->mlx = mlx_init();
    if (!data->g->mlx)
	{
        return (message("mlx initialitation error\n"), 1);
	}
	data->g->win = mlx_new_window(data->g->mlx, WIN_X, WIN_Y,
			"Cub3D gforns-s & josegar2");
    if (load_textures(data->file, data->g))
	{
		return (1);
	}
	if (img_init(data->g))
        return (message("Image creation error\n"), 1);
	// Been told to start first with a color innstead of image
	// maybe better to do a separate functionfor hooks and loop
    //mlx_put_image_to_window(data->g->mlx, data->g->win, data->g->txt[0].img, 0, 0);
	check_columns(data->g);
	mlx_hook(data->g->win, KEYDOWN, 0, key_press, data->g);
	//mlx_hook(data->g->win, KEYDOWN, 0, p_moves, data->g);
	mlx_hook(data->g->win, DESTROY, 1L << 0, close_window, data->g);
	mlx_loop(data->g->mlx);
    return (0);
}

//int	game_loop()??


int	main_game(t_data *data)
{
	start_mlx(data);
	mlx_put_image_to_window(data->g, data->g->win, data->g->i.img, 0, 0);

	return (0);
}

/*

    Obrir finestra --> OK
    Pintar alguna imatge a una posicio x,y, per exemple les mateixes textures --> imatge si, a posicio en concret no se
    Aconseguir que amb esc o la creu es tanqui la finestra --> OK
    Aconseguir que amb les tecles es canviin les coordenades povx, povy i l'angle povo
    Les funcions per en una columna y pintar el cealing
    
*/