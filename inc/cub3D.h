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
# define FOV 60
# define WIN_X 1920
# define WIN_Y 1080
# define LINEAR_SPEED 64
# define ROT_SPEED 5
# define ROT_SPEED_M 5

/*###	KEY MAPPING	###*/

# ifdef MAC_OS
#  define ESC_KEY 53
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define W_KEY 13
#  define LEFT_KEY 123  // to check
#  define RIGHT_KEY 124 // to check
# else
#  define ESC_KEY 65307
#  define A_KEY 97
#  define S_KEY 115
#  define D_KEY 100
#  define W_KEY 119
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363
# endif

# define KEYDOWN 2
# define KEYUP 3
# define DESTROY 17

/*-=-=-=-=-=-=-=-=-=STRUCTS=-=-=-=-=-=-=-=-=-*/

typedef struct s_file
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	int			*f;
	int			*c;
	char		**map;
	int			max_x;
	int			max_y;
	int			data_ok;
	int			stx;
	int			sty;
	char		sto;
}				t_file;

typedef struct t_ray
{
	double		pos_x;
	double		pos_y;
	double		raya;
	double		dirx;
	double		diry;
	double		fvhx;
	double		fvhy;
	double		fhhx;
	double		fhhy;
	double		wvhx;
	double		wvhy;
	double		deltay;
	double		wvhl;
	double		whhx;
	double		whhy;
	double		deltax;
	double		whhl;
	double		sow;
	int			soi;
	double		ooi;
	bool		hit;

}				t_ray;

typedef struct s_image
{
	//
	void		*img;
	char		*addr;
	int			w;
	int			h;
	int			bpp;
	int			ll;
	int			en;
}				t_image;

typedef struct s_player
{
	int			bs;
	int			vh;
	double		fov;
	double		ppd;
	double		angs;
	int			lins;
	double		rots;
	double		povx;
	double		povy;
	double		pova;
	double		dirx;
	double		diry;
}				t_player;

typedef struct s_graph
{
	void		*mlx;
	void		*win;
	t_image		i;
	t_image		txt[4];
	int			rgbc;
	int			rgbf;
	t_player	p;
	t_ray		ray;
	t_file		*file;
}				t_graph;

typedef struct s_data
{
	t_graph		*g;
	t_file		*file;
}				t_data;

/*-=-=-=-=-=-=-=-=FUNCTIONS=-=-=-=-=-=-=-=-=*/

int				check_args(int ac, char **av);
int				check_map(t_file *file, char *fn);
int				load_arg(char *line, t_file *file);
void			message(char *msg);
bool			valid_map_line(t_file *file, char *line);
bool			check_is_num(char *s);
int				check_ext(char *argv, char *text);
bool			line_is_space(char *line);
int				build_map(char **av, t_file *file);
int				check_wall(t_file *f);
bool			has_map(char *line);
void			*ft_free_split(char **s);
t_data			*c3d_free(t_data *data);
void			*ft_free(void *p);
int				start_mlx(t_data *data);
int				load_textures(t_file *fl, t_graph *mx);
void			x_destroy_img(t_graph *mx);
void			draw_column(t_graph *g, int x, t_ray r);
void			draw_texture(t_graph *g, int x, t_ray r);
int				i_coor(double pos);
char			get_map_char(t_graph *g, double x, double y);
void			loop_rays(t_graph *g);
int				p_moves(int keycode, t_graph *g);
bool			check_pmove(t_graph *g, char c);
int				player_w(t_player *p, int speed);
int				player_s(t_player *p, int speed);
int				player_a(t_player *p, int speed);
int				player_d(t_player *p, int speed);
int				player_right(t_player *p);
int				player_left(t_player *p);
void			c3d_mlx_pixel_put(t_image im, int x, int y, int color);
bool			check_around(t_graph *g, t_player tp);
#endif