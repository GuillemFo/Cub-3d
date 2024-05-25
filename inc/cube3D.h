/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:31:22 by codespace         #+#    #+#             */
/*   Updated: 2024/05/25 02:23:15 by codespace        ###   ########.fr       */
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





/*-=-=-=-=-=-=-=-=FUNCTIONS=-=-=-=-=-=-=-=-=*/

int		check_args(char **av);
int		check_name(char *name);
void	message(char *msg);

#endif