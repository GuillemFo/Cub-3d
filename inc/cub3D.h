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
# include <stdbool.h>
# include <math.h>

/*-=-=-=-=-=-=-=-=COLOR CODES=-=-=-=-=-=-=-=-*/

# define C_R "\x1b[31m" // RED
# define C_G "\x1b[32m" // GREEN
# define C_B "\x1b[34m" // BLUE
# define C_Y "\x1b[33m" // YELLOW
# define C_M "\x1b[35m" // MAGENTA
# define C_C "\x1b[36m" // CYAN
# define C_RESET "\x1b[0m"

/*-=-=-=-=-=-=-=-GRAPH SETTINGS=-=-=-=-=-=-=-*/

# define FIELD_OF_VIEW 60
# define SIZE_X 1920
# define SIZE_Y 1080
# define ANGULAR_STEP FIELD_OF_VIEW / SIZE_X
# define POV_DISTANCE (SIZE_X /2) / tan(FIELD_OF_VIEW / 2)
# define LINEAR_SPEED 16
# define ROTATION_SPEED 5


/*###	KEY MAPPING	###*/
# define ESC_KEY 65307
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define W_KEY 119


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
	//key hooks??
	//mouse??
}			t_event;

typedef struct s_file
{
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	int		*F;	//Floor color
	int		*C;	//Ceiling color
	int		F_flag;
	int		C_flag;
	char	**map;
	char	**tmp;
	int		max_x;
	int		max_y;
	int		data_ok;
	int		nb_player;
}				t_file;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct	s_graph
{
	int		bs; //block size
	int		vh; //view height
	int		xs; //X size
	int		ys; //Y size
	double	fov; //Field of view
	double	angs; //Angular step
	int		lins; //Linear speed
	double	rots; //Rotation speed
	int		povx; //Point of View X	(player view)
	int		povy; //Point of View Y	(player view)
	double	pova; //Point of View angle	(player view)
	double	ray_x;
	double	ray_y;
}			t_graph;


typedef struct s_data
{
	t_mlx 	*mlx;
	t_graph	gr;
	t_file	*file;
	
}				t_data;



/*-=-=-=-=-=-=-=-=FUNCTIONS=-=-=-=-=-=-=-=-=*/

int		check_args(int ac, char **av);
int		check_map(t_file *file, char *fn);
void	message(char *msg);
char	*ft_replace(char *s, char og, char re);
char	*clean_l(char *line);
bool	valid_map_line(char *line);
bool	check_is_num(char *s);
int		check_ext(char *argv, char *text);
bool	line_is_space(char *line);
int		build_map(char **av, t_file *file);
bool	has_map(char *line);
int		check_ext_sp(char *str, char *text);
void	*ft_free_split(char **s);
void	fill_with_space(char *str);
char	*clean_l(char *line);
int		check_ext_sp(char *str, char *text);
t_data  *c3d_free(t_data *data);
void	*ft_free(void *p);
void	start_mlx(t_data *data);


void	print_map_term(t_file *file);

#endif