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

╰─ ./cub3D maps/map3.cub
NO : textures/Wall_NO1.xpm
SO : textures/Wall_SO1.xpm
EA : textures/Wall_EA1.xpm
WE : textures/Wall_WE1.xpm
F : 184, 113, 39
C : 51, 198, 227
Start x: 26 y: 11
Start orientation: N
Max X: 38 Y: 14
--                                          --
--                                          --
--          1111111111111111111111111       --
--          1000000000110000000000001       --
--          1011000001110000000000001       --
--          100101111111111100000000111111  --
--  11111111101101101110001111111111        --
--  1000000000110111111011111111111         --
--  1111011111111111111111111111111         --
--  111101111111111111111111010001          --
--  11000000110101011100000010001           --
--  10000000000000001100000010001           --
--  10000000000000001101010010001           --
--  1100000111010101111101111000111         --
--  11110011111010111101111010001           --
--  11111111111111111111111111111           --
--                                          --
--                                          --
=================================================================
==14346==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x6040000007fb at pc 0x56f2d46767b7 bp 0x7ffe38d3b810 sp 0x7ffe38d3b800
READ of size 1 at 0x6040000007fb thread T0
    #0 0x56f2d46767b6 in get_map_char src/graphics/player_2.c:33
    #1 0x56f2d46729f3 in wall_v_hit src/graphics/math.c:25
    #2 0x56f2d46739f8 in loop_rays src/graphics/math.c:102
    #3 0x56f2d4676ed8 in p_moves src/graphics/player_mov.c:59
    #4 0x56f2d4678405 in mlx_loop (/home/wil/Desktop/Cub-3d/cub3D+0x13405)
    #5 0x56f2d467263b in start_mlx src/graphics/graphics.c:54
    #6 0x56f2d466e71a in main src/main.c:75
    #7 0x729895829d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #8 0x729895829e3f in __libc_start_main_impl ../csu/libc-start.c:392
    #9 0x56f2d466dae4 in _start (/home/wil/Desktop/Cub-3d/cub3D+0x8ae4)

0x6040000007fb is located 0 bytes to the right of 43-byte region [0x6040000007d0,0x6040000007fb)
allocated by thread T0 here:
    #0 0x729895eb4887 in __interceptor_malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x56f2d46771c8 in ft_calloc (/home/wil/Desktop/Cub-3d/cub3D+0x121c8)
    #2 0x56f2d466f341 in init_map src/parsing/load_map.c:52
    #3 0x56f2d466f4ff in build_map src/parsing/load_map.c:67
    #4 0x56f2d466e66a in main src/main.c:71
    #5 0x729895829d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

SUMMARY: AddressSanitizer: heap-buffer-overflow src/graphics/player_2.c:33 in get_map_char
Shadow bytes around the buggy address:
  0x0c087fff80a0: fa fa fd fd fd fd fd fa fa fa 00 00 00 00 00 03
  0x0c087fff80b0: fa fa 00 00 00 00 00 03 fa fa 00 00 00 00 00 03
  0x0c087fff80c0: fa fa 00 00 00 00 00 03 fa fa 00 00 00 00 00 03
  0x0c087fff80d0: fa fa 00 00 00 00 00 03 fa fa 00 00 00 00 00 03
  0x0c087fff80e0: fa fa 00 00 00 00 00 03 fa fa 00 00 00 00 00 03
=>0x0c087fff80f0: fa fa 00 00 00 00 00 03 fa fa 00 00 00 00 00[03]
  0x0c087fff8100: fa fa 00 00 00 00 00 03 fa fa 00 00 00 00 00 03
  0x0c087fff8110: fa fa 00 00 00 00 00 03 fa fa 00 00 00 00 00 03
  0x0c087fff8120: fa fa 00 00 00 00 00 03 fa fa 00 00 00 00 00 03
  0x0c087fff8130: fa fa 00 00 00 00 00 03 fa fa fd fd fd fd fd fa
  0x0c087fff8140: fa fa fd fd fd fd fd fd fa fa fd fd fd fd fd fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==14346==ABORTING

















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
