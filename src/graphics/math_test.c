/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:01:51 by codespace         #+#    #+#             */
/*   Updated: 2024/06/26 17:55:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// int get_wall_distance(t_graph *g, int x)
// {
// /*    distance from player to projection (WIN_X / 2) / tan(FIELD_OF_VIEW / 2)

//     Dimension of the Projection Plane = WIN_X * WIN_Y units
//     Center of the Projection Plane = (WIN_X / 2,WIN_Y / 2)
//     Distance to the Projection Plane = (WIN_X / 2) / tan(FIELD_OF_VIEW / 2)
//     Angle between subsequent rays = FIELD_OF_VIEW / WIN_X degrees == 1 column
// */
// 	x = 0;
// 	while (x < WIN_X -1)
// 	{
		
// /*	Based on the viewing angle, subtract 30 degrees (half of the FOV).
// 	Starting from column 0:
// 		Cast a ray. (The term “cast” is a bit confusing. Imagine the player as a wizard who can “cast” rays instead of spells. The ray is just an “imaginary” line extending from the player.)
// 		Trace the ray until it hits a wall.
//     Record the distance to the wall (the distance is equal to the length of the ray).
//     Add the angle increment so that the ray moves to the right (we know from Figure 10 that the value of the angle increment is 60/320 degrees).
//     Repeat step 2 and 3 for each subsequent column until all 320 rays are cast.
// */
// 	if (g->p.pova )

// 	}
// }       
//a loop that keeps trying C.x=A.x+Xa C.y=A.y+Ya and check if its a hit? and if no,
//D.x=C.x+Xa D.y=C.y+Ya and so, while no hit.
//keep this loop and continue while no hit. recicle c.x and c.y for each new iteration until the wall has been found
int	loop_ray_throw()
{
	while (g->ray.hit == false)
	{
		C.x=A.x+Xa;
		C.y=A.y+Ya;
		if (g->file->map[C.y][C.x] == '1')
		{
			g->ray.hit = true;
			break ;
		}
		A.x = C.x;
		A.y = C.y;
	}
	return (lenght of the ray??)
}

int get_first_pos(t_graph *g, int x)	
{
	//for angle between 0 and 179;
	if ((g->p.pova * (180 / M_PI))>= 0 && g->p.pova * (180 / M_PI) < 180)
	{
		A.y = rounded_down(g->ray.pos_y/BLOCK_SIZE) * (BLOCK_SIZE) - 1;
		A.x = g->ray.pos_x + (g->ray.pos_y - A.y)/tan(g->p.pova * (180 / M_PI));
		Y.a = -BLOCK_SIZE
	}
	//for angle between 180 and 360;
	else
	{
		A.y = rounded_down(g->ray.pos_y/BLOCK_SIZE) * (BLOCK_SIZE) + BLOCK_SIZE;
		A.x = g->ray.pos_x + (g->ray.pos_y - A.y)/tan(g->p.pova * (180 / M_PI));
		Y.a = BLOCK_SIZE
	}
	Xa = BLOCK_SIZE/tan(g->p.pova * (180 / M_PI));
	if (g->file->map[A.y][A.x] == '1')
	{
		g->ray.hit = true;
		return (1);	
	}
	}
	return (0);
}




























































