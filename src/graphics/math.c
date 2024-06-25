/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:04:16 by gforns-s          #+#    #+#             */
/*   Updated: 2024/06/25 12:42:05 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



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
/*
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
	}
	return (lenght of the ray??)
}
*/

//guess this is the 1 st pos of the ray check? If so, we can call from here 
//a loop that keeps trying C.x=A.x+Xa C.y=A.y+Ya and check if its a hit? and if no,
//D.x=C.x+Xa D.y=C.y+Ya and so, while no hit.
// From x, y and angle get the first Vertical and Horizontal hits
void    get_first_hit(t_ray *r)	
{
	//need to know in what direction im looking so i can add the -1 or +BLOCK_SIZE to the positive and negative angle
	//plus we need protection so the player cant be in the wall. Maybe -16 block to the end of the cell touching a wall?
	//Im adding this protection now;
    r->dir_x = cos(r->raya);
    r->dir_y = -sin(r->raya);
    r->fvhx = (i_coor(r->pos_x) + (r->dir_x > 0)) * BLOCK_SIZE;
    if (r->dir_x == 0)
        r->fvhy = -1;
    else
        r->fvhy = (r->fvhx - r->pos_x) * r->dir_y / r->dir_x + r->pos_y;
    r->fhhy = (i_coor(r->pos_y) + (r->dir_y > 0)) * BLOCK_SIZE;
    if (r->dir_y == 0)
        r->fhhx = -1;
    else
        r->fhhx = (r->fhhy - r->pos_y) * r->dir_x / r->dir_y + r->pos_x;
    printf("Vertical hit X : %.2f Y : %.2f\n", r->fvhx, r->fvhy);
    printf("Horizontal hit X : %.2f Y : %.2f\n", r->fhhx, r->fhhy);

/*
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
*/
}


void    loop_rays(t_graph *g)
{
    int i;

    g->ray.pos_x = g->p.povx;
    g->ray.pos_y = g->p.povy;
    g->ray.raya = g->p.pova + FIELD_OF_VIEW / 2;
    if (g->ray.raya > 2 * M_PI)
        g->ray.raya -= 2 * M_PI;
    i = 0;
    if (i < WIN_X)	// while (i++ < WIN_X)
    {
        get_first_hit(&g->ray);
        g->ray.raya -= FIELD_OF_VIEW / WIN_X;
        if (g->ray.raya < 0)
            g->ray.raya += 2 * M_PI;
		if (g->ray.fvhy <= g->ray.fhhy && g->ray.fvhx <= g->ray.fhhx)
		{
			if (((int)g->ray.fvhy >= 0 && (int)g->ray.fvhx >= 0) && ((int)g->ray.fvhy / BLOCK_SIZE <= g->file->max_y && (int)g->ray.fvhx / BLOCK_SIZE <= g->file->max_y))
			{
				if (g->file->map[2 + (int)g->ray.fvhy / BLOCK_SIZE][2 + (int)g->ray.fvhx / BLOCK_SIZE] == '1')
					printf("hit 1\n");
				else
					printf("miss 1\n");
			}
			else if (((int)g->ray.fhhy >= 0 && (int)g->ray.fhhx >= 0) && ((int)g->ray.fhhy / BLOCK_SIZE <= g->file->max_x && (int)g->ray.fhhx / BLOCK_SIZE <= g->file->max_x))
			{
				if (g->file->map[2 + (int)g->ray.fhhy / BLOCK_SIZE][2 + (int)g->ray.fhhx / BLOCK_SIZE] == '1')
					printf("hit 2\n");
				else
					printf("miss 2\n");
			}
		}
		else
		{
			if (((int)g->ray.fhhy >= 0 && (int)g->ray.fhhx >= 0) && ((int)g->ray.fhhy / BLOCK_SIZE <= g->file->max_x && (int)g->ray.fhhx / BLOCK_SIZE <= g->file->max_x))
			{
				if (g->file->map[2 + (int)g->ray.fhhy / BLOCK_SIZE][2 + (int)g->ray.fhhx / BLOCK_SIZE] == '1')
					printf("hit 3\n");
				else
					printf("miss 3\n");
			}
			else if (((int)g->ray.fvhy >= 0 && (int)g->ray.fvhx >= 0) && ((int)g->ray.fvhy / BLOCK_SIZE <= g->file->max_y && (int)g->ray.fvhx / BLOCK_SIZE <= g->file->max_y))
			{
				if (g->file->map[2 + (int)g->ray.fvhy / BLOCK_SIZE][2 + (int)g->ray.fvhx / BLOCK_SIZE] == '1')
					printf("hit 4\n");
				else
					printf("miss 4\n");
			}

		}
    }
}


/*
Interpreting formula from https://permadi.com/tutorial/raycast/images/figure15.gif
Y = 3.5 & X = 1.5 //Remember that img presents x first then y (1.5x,3.5y) and g->p.pova is in degree
======Finding horizontal intersection ======
1. Finding the coordinate of A.  
	If the ray is facing up	
	  A.y = rounded_down(g->ray.pos_y/BLOCK_SIZE) * (BLOCK_SIZE) - 1;
	If the ray is facing down
	  A.y = rounded_down(g->ray.pos_y/BLOCK_SIZE) * (BLOCK_SIZE) + BLOCK_SIZE;

(In the picture, the ray is facing up, so we use
	the first formula.  

	A.y=rounded_down(g->ray.pos_y/BLOCK_SIZE) * (BLOCK_SIZE) - 1;
	A.y=rounded_down(3.5 * 128/128) * (128) - 1 = 383;

	Now at this point, we can find out the grid 
	coordinate of y.
	However, we must decide whether A is part of 
	the block above the line,
	or the block below the line.  
	Here, we chose to make A part of the block
	above the line, that is why we subtract 1 from A.y.
	So the grid coordinate of A.y is 383/128 = 2; //rounded down

	A.x = Px + (Py-A.y)/tan(ALPHA);
	In the picture, (assume ALPHA is 60 degrees),
	A.x = g->ray.pos_x + (g->ray.pos_y - A.y)/tan(g->p.pova);
	A.x=(1.5 *128) + ((3.5*128)-383)/tan(60) = about 229; //rounded down
	The grid coordinate of A.x is 229/128 = 1;	//rounded down

	So A is at grid (1,2) and we can check 
	whether there is a wall on that grid.
	There is no wall on (1,2) so the ray will be 
	extended to C.

2. Finding Ya
	If the ray is facing up	
	  Ya=-128;	-BLOCK_SIZE
	If the ray is facing down
	  Ya=128;	BLOCK_SIZE

3. Finding Xa
	Xa = BLOCK_SIZE/tan(g->p.pova) = 73;
	Xa = 128/tan(60) = 73;

4. We can get the coordinate of C as follows:
	C.x=A.x+Xa = 229+73 = 302;	//rounded down
	C.y=A.y+Ya = 383-128 = 255;	//rounded down
	Convert this into grid coordinate by 
	dividing each component with BLOCK_SIZE (128).  
	The result is 
	C.x = 302/128 = 2 (grid coordinate), 
	C.y = 255/128 = 1 (grid coordinate) 
	So the grid coordinate of C is (2, 1).  
	(C programmer''s note: Remember we always round down, 
	this is especially true since
	you can use right shift by 8 to divide by 64).

5. Grid (2,1) is checked.  
	Again, there is no wall, so the ray is extended 
	to D.  

6. We can get the coordinate of D as follows:
	D.x=C.x+Xa = 302+73 = 375;
	D.y=C.y+Ya = 255-128 = 127;
	Convert this into grid coordinate by 
	dividing each component with BLOCK_SIZE (128).  
	The result is 
	D.x = 375/128 = 2 (grid coordinate), 
	D.y = 127/128 = 0 (grid coordinate) 
	So the grid coordinate of D is (2, 0).  

6. Grid (2,0) is checked.  
	There is a wall there, so the process stop.





*/














