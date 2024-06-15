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

# define BLOCK_SIZE 128
# define PLAYER_HEIGHT 64
# define FIELD_OF_VIEW 60
# define SIZE_X 800
# define SIZE_Y 600
# define ANGULAR_STEP FIELD_OF_VIEW / SIZE_X
# define POV_DISTANCE (SIZE_X /2) / tan(FIELD_OF_VIEW / 2)
# define LINEAR_SPEED 16
# define ROTATION_SPEED 5

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
	char	**map;
	char	**tmp;
	int		max_x;
	int		max_y;
	int		data_ok;
    int     stx;
    int     sty;
    char    sto;
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
	int		povx; //Point of View X
	int		povy; //Point of View Y
	double	pova; //Point of View angle
}			t_graph;


typedef struct s_data
{
	t_mlx 	*win;
	t_graph	gr;
	t_file	*file;
	
}				t_data;



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


void	print_map_term(t_file *file);

#endif