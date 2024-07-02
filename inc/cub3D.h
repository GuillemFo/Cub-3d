/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:22 by codespace         #+#    #+#             */
/*   Updated: 2024/05/28 09:16:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*-=-=-=-=-=-=-=-=LIBRARIES=-=-=-=-=-=-=-=-*/

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../src/libft/libft.h"
# include <math.h>
# include <stdbool.h>

/*-=-=-=-=-=-=-=-=COLOR CODES=-=-=-=-=-=-=-=-*/

# define C_R "\x1b[31m" // RED
# define C_G "\x1b[32m" // GREEN
# define C_B "\x1b[34m" // BLUE
# define C_Y "\x1b[33m" // YELLOW
# define C_M "\x1b[35m" // MAGENTA
# define C_C "\x1b[36m" // CYAN
# define C_RESET "\x1b[0m"

/*-=-=-=-=-=-=-=-GRAPH SETTINGS=-=-=-=-=-=-=-*/

# define BLOCK_SIZE 512
# define VIEW_HEIGHT 256
# define FIELD_OF_VIEW (60 * M_PI) / 180
# define WIN_X 1920
# define WIN_Y 1080
# define ANGULAR_STEP FIELD_OF_VIEW / WIN_X
# define POV_DISTANCE (WIN_X / 2) / tan(FIELD_OF_VIEW / 2)
# define LINEAR_SPEED 64
# define ROTATION_SPEED (5 * M_PI) / 180

/*###	KEY MAPPING	###*/

# ifdef MAC_OS
#  define ESC_KEY 53
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define W_KEY 13
#  define LEFT_KEY 123 // to check
#  define RIGHT_KEY 124 //to check
# else
#  define ESC_KEY 65307
#  define A_KEY 97
#  define S_KEY 115
#  define D_KEY 100
#  define W_KEY 119
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363
# endif

/*###	X11 EVENTS SUPPORTED BY MINILIBX	###*/
# define KEYDOWN 2
# define KEYUP 3
# define MOUSEDOWN 4
# define MOUSEUP 5
# define MOUSEMOVE 6
# define EXPOSE 12
# define DESTROY 17

/*###	MOUSE EVENTS	###*/
# define LEFT_CLICK 1
# define RIGHT_CLICK 3
# define MID_CLICK 2
# define SCROLL_UP 5
# define SCROLL_DOWN 4

/*##	DEFINE TO SHORT CODE	##*/
# define IMG_WIN mlx_put_image_to_window

/*-=-=-=-=-=-=-=-=-=STRUCTS=-=-=-=-=-=-=-=-=-*/

typedef struct s_event
{
	// key hooks??
	// mouse??
}			t_event;

typedef struct s_file
{
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	int *F; // Floor color
	int *C; // Ceiling color
	char	**map;
	char	**tmp;
	int		max_x;
	int		max_y;
	int		data_ok;
	int		stx;
	int		sty;
	char	sto;
}			t_file;

typedef struct t_ray
{
	double	pos_x;
	double	pos_y;
	double	raya; //ray angle
	double	dirx; // cos(raya)
	double	diry; // -sin(raya)
	double	fvhx; //FirstVerticalHit X
	double	fvhy; //FirstVerticalHit Y
	double	fhhx; //FirstHoritzontalHit X
	double	fhhy; //FirstHoritzontalHit Y
	double	wvhx; //WallVerticalHit X
	double	wvhy; //WallVerticalHit Y
	double	deltay; // y increment to next V hit;
	double	wvhl; //WallVerticalHit Length
	double	whhx; //WallHoritzontalHit X
	double	whhy; //WallHoritzontalHit Y
	double	deltax; // x increment to next H hit;
	double	whhl; //WallHoritzontalHit Length
	double	sow; //size of wall
	int		soi; //Side Of Impact: 0-NO, 1-SO, 2-EA, 3-WE
	double	ooi; // Offset Of Impact. Distance from left side of wall
	bool	hit;

}			t_ray;

typedef struct s_image
{
	//
	void *img;  // mlx_new_img
	char *addr; // mlx_get_data_addr
	int		w;
	int		h;
	int bpp; // mlx_get_data_addr
	int ll;  // line length
	int en;  // endian
}			t_image;

typedef struct s_player
{
	int bs;         // Block size
	int vh;         // View height
	double	fov;     // Field of view
	double	ppd;	// Projection Plane Distance
	double angs;    // Angular step
	int lins;       // Linear speed
	double rots;    // Rotation speed
	double	povx;       // Point of view x
	double	povy;       // Point of view y
	double	pova;    // Point of view angle
	double	dirx;	// cos(pova)
	double	diry;	// -sin(pova)
}			t_player;

typedef struct s_graph
{
	void *mlx; // mlx
	void *win; // win
	t_image i; // img
	t_image	txt[4];
	int		rgbc;
	int		rgbf;
	t_player p; // player struct
	t_ray	ray;
	t_file	*file;
}			t_graph;

typedef struct s_data
{
	t_graph *g; // t_grapth graphics
	t_file	*file;
}			t_data;

/*-=-=-=-=-=-=-=-=FUNCTIONS=-=-=-=-=-=-=-=-=*/

int		check_args(int ac, char **av);
int		check_map(t_file *file, char *fn);
int     load_arg(char *line, t_file *file);
void	message(char *msg);
bool	valid_map_line(t_file *file, char *line);
bool	check_is_num(char *s);
int		check_ext(char *argv, char *text);
bool	line_is_space(char *line);
int		build_map(char **av, t_file *file);
int	   	check_wall(t_file *f);
bool	has_map(char *line);
void	*ft_free_split(char **s);
t_data  *c3d_free(t_data *data);
void	*ft_free(void *p);
int		start_mlx(t_data *data);
int		load_textures(t_file *fl, t_graph *mx);
void	x_destroy_img(t_graph *mx);
void	draw_column(t_graph *g, int x, t_ray r);
void	draw_texture(t_graph *g, int x, t_ray r);
int 	i_coor(double pos);
char    get_map_char(t_graph *g, double x, double y);
void    loop_rays(t_graph *g);
int			p_moves(int keycode, t_graph *g);

/*-=-=-=-=-=- TEST FUNCTIONS=-=-=-=-=-=-=-=-=*/

void	check_columns(t_graph *g);
void	print_map_term(t_file *file);

int get_wall_size(t_graph *g, int x);


#endif