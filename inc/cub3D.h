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

/*-=-=-=-=-=-=-=-=COLOR CODES=-=-=-=-=-=-=-=-*/

# define C_R "\x1b[31m" // RED
# define C_G "\x1b[32m" // GREEN
# define C_B "\x1b[34m" // BLUE
# define C_Y "\x1b[33m" // YELLOW
# define C_M "\x1b[35m" // MAGENTA
# define C_C "\x1b[36m" // CYAN
# define C_RESET "\x1b[0m"

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


typedef struct s_data
{
	t_mlx 	*win;
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
int		ft_strlen_n(char *var);
int		check_ext(char *argv, char *text);
bool	line_is_space(char *line);
int		build_map(char **av, t_file *file);
bool	has_map(char *line);

char	*clean_tabs(char *line);
int		check_ext_sp(char *str, char *text);
void	print_map_term(char **map);
void	*ft_free_split(char **s);
void	fill_with_space(char *str);
char	*clean_l(char *line);
int	check_ext_sp(char *str, char *text);
t_data  *c3d_free(t_data *data);
void	*ft_free(void *p);


void	print_map_term(t_file *file);

#endif