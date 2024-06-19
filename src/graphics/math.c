/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:04:16 by gforns-s          #+#    #+#             */
/*   Updated: 2024/06/19 15:05:13 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// Function to perform raycasting and return the wall size for column x
int get_wall_size(t_graph *g, int x, t_data *data)
{
    double camera_x = 2 * x / (double)WIN_X - 1;  // Map x coordinate to camera plane
    double ray_dir_x = g->p.dir_x + g->p.plane_x * camera_x;
    double ray_dir_y = g->p.dir_y + g->p.plane_y * camera_x;

    // Current position in map
    int map_x = (int)g->p.pos_x;
    int map_y = (int)g->p.pos_y;

    // Length of ray from current position to next x or y side
    double side_dist_x;
    double side_dist_y;

    // Length of ray from one x or y side to next x or y side
    double delta_dist_x = fabs(1 / ray_dir_x);
    double delta_dist_y = fabs(1 / ray_dir_y);
    double perp_wall_dist;

    // Step and initial sideDist
    int step_x;
    int step_y;
    int hit = 0;  // Was there a wall hit?
    int side;     // Was a NS or a EW wall hit?

    // Calculate step and initial sideDist
    if (ray_dir_x < 0)
    {
        step_x = -1;
        side_dist_x = (g->p.pos_x - map_x) * delta_dist_x;
    }
    else
    {
        step_x = 1;
        side_dist_x = (map_x + 1.0 - g->p.pos_x) * delta_dist_x;
    }
    if (ray_dir_y < 0)
    {
        step_y = -1;
        side_dist_y = (g->p.pos_y - map_y) * delta_dist_y;
    }
    else
    {
        step_y = 1;
        side_dist_y = (map_y + 1.0 - g->p.pos_y) * delta_dist_y;
    }

    // Perform DDA
    while (hit == 0)
    {
        // Jump to next map square, either in x-direction, or in y-direction
        if (side_dist_x < side_dist_y)
        {
            side_dist_x += delta_dist_x;
            map_x += step_x;
            side = 0;
        }
        else
        {
            side_dist_y += delta_dist_y;
            map_y += step_y;
            side = 1;
        }
        // Check if ray has hit a wall
        if (data->file->map[map_x][map_y] > 0) hit = 1;
    }

    // Calculate distance to the point of impact
    if (side == 0)
        perp_wall_dist = (map_x - g->p.pos_x + (1 - step_x) / 2) / ray_dir_x;
    else
        perp_wall_dist = (map_y - g->p.pos_y + (1 - step_y) / 2) / ray_dir_y;

    // Calculate the height of the line to draw on screen
    int line_height = (int)(WIN_Y / perp_wall_dist);

    return line_height;
}




























