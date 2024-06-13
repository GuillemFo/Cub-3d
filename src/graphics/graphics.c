/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:43:09 by gforns-s          #+#    #+#             */
/*   Updated: 2024/06/13 15:59:05 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// mlx_hook(data->mlx->mlx_win, 2, 1L << 0, key_press, &data);
int	key_press(int keycode, t_data *data)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
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
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit(0);
	}
	return (1);
}

int	close_window(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
	return (1);
}









void	start_mlx(t_data *data)
{
	data->mlx->mlx = mlx_init();
	data->mlx->mlx_win = mlx_new_window(data->mlx->mlx, 1920, 1080,
			"Cub3D gforns-s & josegar2");
	mlx_hook(data->mlx->mlx_win, KEYDOWN, 1L << 0, esc_window, data);
	mlx_hook(data->mlx->mlx_win, DESTROY, 1L << 0, close_window, data);

	mlx_loop(data->mlx->mlx);
}
