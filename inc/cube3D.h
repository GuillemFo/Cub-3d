/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:22 by codespace         #+#    #+#             */
/*   Updated: 2024/05/25 08:19:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUDE3D_H

/*-=-=-=-=-=-=-=-=LIBRARIES=-=-=-=-=-=-=-=-*/

# include "../mlx_linux/mlx.h"
# include "../src/libft/libft.h"

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

typedef struct s_map
{
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	int		*F;	//Floor color
	int		*C;	//Ceiling color
	char	**map;
}				t_map;


typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;


typedef struct s_data
{
	t_mlx 	win;
	t_map	map;
	
}				t_data;



/*-=-=-=-=-=-=-=-=FUNCTIONS=-=-=-=-=-=-=-=-=*/

int		check_args(int ac, char **av);
int		check_name(char *name);
void	message(char *msg);

#endif