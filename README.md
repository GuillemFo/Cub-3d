# Cub-3d

Map issues:
-------------------------------------
Map just under some parameters

C 51,198,227
1111
-------------------------------------
Map with multiple new lines at the end
-------------------------------------
Crash sometimes when corner not fully closed
-------------------------------------
AddressSanitizer:DEADLYSIGNAL
=================================================================
==14118==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000024 (pc 0x5f0a6d27f709 bp 0x7ffe49e813b0 sp 0x7ffe49e81380 T0)
==14118==The signal is caused by a READ memory access.
==14118==Hint: address points to the zero page.
    #0 0x5f0a6d27f709 in get_map_char src/graphics/player_2.c:33
    #1 0x5f0a6d27c00b in wall_h_hit src/graphics/math.c:52
    #2 0x5f0a6d27c9db in loop_rays src/graphics/math.c:103
    #3 0x5f0a6d27fe26 in p_moves src/graphics/player_mov.c:58
    #4 0x5f0a6d281355 in mlx_loop (/home/wil/Desktop/Cub-3d/cub3D+0x13355)
    #5 0x5f0a6d27b63b in start_mlx src/graphics/graphics.c:53
    #6 0x5f0a6d27771a in main src/main.c:75
    #7 0x7f909d029d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #8 0x7f909d029e3f in __libc_start_main_impl ../csu/libc-start.c:392
    #9 0x5f0a6d276ae4 in _start (/home/wil/Desktop/Cub-3d/cub3D+0x8ae4)

AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV src/graphics/player_2.c:33 in get_map_char
==14118==ABORTING
--------------------------------------------------------
When tab in map, says map not closed.
--------------------------------------------------------
Some times if space replaced by tab, map crashes or says not closed
--------------------------------------------------------
Error
Map not closed

=================================================================
==15438==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 16 byte(s) in 1 object(s) allocated from:
    #0 0x70ded80b4887 in __interceptor_malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x5c801cc1e116 in ft_calloc (/home/wil/Desktop/Cub-3d/cub3D+0x12116)
    #2 0x5c801cc14bc3 in init_data src/main.c:19
    #3 0x5c801cc1558d in main src/main.c:66
    #4 0x70ded7a29d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

Indirect leak of 488 byte(s) in 1 object(s) allocated from:
    #0 0x70ded80b4887 in __interceptor_malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x5c801cc1e116 in ft_calloc (/home/wil/Desktop/Cub-3d/cub3D+0x12116)
    #2 0x5c801cc14c3e in init_data src/main.c:25
    #3 0x5c801cc1558d in main src/main.c:66
    #4 0x70ded7a29d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

SUMMARY: AddressSanitizer: 504 byte(s) leaked in 2 allocation(s).
-----------------------------------------------------------------
If map has spaces before the map, it calls as a not closed one
-----------------------------------------------------------------

Error
Can't load texture files

=================================================================
==17993==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 136 byte(s) in 1 object(s) allocated from:
    #0 0x7e4a7d2b4887 in __interceptor_malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x5ead8d952f3f in mlx_init (/home/wil/Desktop/Cub-3d/cub3D+0x12f3f)
    #2 0x5ead8d94971a in main src/main.c:75
    #3 0x7e4a7cc29d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

Indirect leak of 936 byte(s) in 1 object(s) allocated from:
    #0 0x7e4a7d2b4887 in __interceptor_malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x5ead8d9530f0 in mlx_new_window (/home/wil/Desktop/Cub-3d/cub3D+0x130f0)

Indirect leak of 160 byte(s) in 1 object(s) allocated from:
    #0 0x7e4a7d2b4887 in __interceptor_malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x7e4a7d0de9ef in XCreateGC (/lib/x86_64-linux-gnu/libX11.so.6+0x1e9ef)
------------------------------------------------------------------------------



















BUG!!! If map has multiple new lines without anything, will return error empty line on map!!

Subject
*	https://cdn.intra.42.fr/pdf/pdf/111520/en.subject.pdf
Math for raycasting
*	https://harm-smits.github.io/42docs/
*	https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/
*	http://gamecodeschool.com/essentials/calculating-heading-in-2d-games-using-trigonometric-functions-part-1/
*	https://reactive.so/post/42-a-comprehensive-guide-to-cub3d

Minilibx
*	https://github.com/terry-yes/mlx_example
*	https://harm-smits.github.io/42docs/libs/minilibx
*	https://gontjarow.github.io/MiniLibX/

Guille 21.06.24 8.47 am
->> Need to move the player acordingly to the map, so player cant go through walls or step inside one.[DONE]

Notes from permadi to calculate distance and so.
	*Interpreting formula from https://permadi.com/tutorial/raycast/images/figure15.gif

Y = 3.5 & X = 1.5 //img presents x first then y (1.5x,3.5y) and g->p.pova is in degree for this formulas 
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
