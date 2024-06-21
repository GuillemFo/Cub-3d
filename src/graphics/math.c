/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:04:16 by gforns-s          #+#    #+#             */
/*   Updated: 2024/06/21 08:45:51 by gforns-s         ###   ########.fr       */
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
    
int	test(t_graph *g)
{
	g->p.pova;
	g->ray.pos_y
}


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



















