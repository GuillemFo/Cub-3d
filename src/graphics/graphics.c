/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:43:09 by gforns-s          #+#    #+#             */
/*   Updated: 2024/06/14 15:50:59 by gforns-s         ###   ########.fr       */
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

int	esc_window(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (1);
}

int	close_window(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->mlx, mlx->win);
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


void img_init(t_data *data)
{
	data->mlx->img = malloc(sizeof(t_image));
	//malloc protection
	data->mlx->img = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	data->mlx->img->addr = mlx_get_data_addr(data->mlx, &data->mlx->img->bpp, &data->mlx->img->size_line, &data->mlx->img->endian);
	
}




void	start_mlx(t_data *data)
{
	data->mlx->mlx = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx, WIN_X, WIN_Y,
			"Cub3D gforns-s & josegar2");
	img_init(data);
	// maybe better to do a separate functionfor hooks and loop
	// mlx_hook(data->mlx->win, KEYDOWN, 1L << 0, esc_window, data);
	// mlx_hook(data->mlx->win, DESTROY, 1L << 0, close_window, data);
	// mlx_loop(data->mlx->mlx);
}

//int	game_loop()??


int	main_game(t_data *data)
{
	start_mlx(data);
	mlx_put_image_to_window(data->mlx, data->mlx->win, data->mlx->img->img, 0, 0);


}