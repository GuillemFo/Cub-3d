/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:09:52 by codespace         #+#    #+#             */
/*   Updated: 2024/07/09 18:23:08 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//ISSUE CHECKING IF MAP HAS SPACES INSIDE BUT SURROUNDED BY 1
//REDO FUNCTION
//there can be spaces insides a line. Will check later if map is closed
bool	valid_map_line(t_file *file, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!ft_strchr("01NSEW", line[i]))
		return (message("Invalid line before map\n"), false);
	if (line[i] != '1')
	{
		return (message("Map not closed\n"), false);
	}
	while (line[i] && line[i] != '\n')
	{
		if (ft_strchr("NSEW", line[i]) && file->sty)
			return (message("More than one starting point\n"), false);
		if (!ft_strchr(" 10NSEW", line[i]))
			return (message("Wrong char in map\n"), false);
		if (ft_strchr("NSEW", line[i]))
			file->sty++;
		i++;
	}
	return (true);
}

bool	check_is_num(char *s)
{
	int	i;

	if (!s)
		return (false);
	i = 1;
	if (s[0] == '+' || ft_isdigit(s[0]))
	{
		while (s[i] != '\0')
		{
			if (!ft_isdigit(s[i]))
				return (false);
			i++;
		}
	}
	else
		return (false);
	return (true);
}

bool	line_is_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

bool	has_map(char *line)
{
	int	i;

	i = 0;
	if (line && line[0] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
			return (true);
	}
	return (false);
}
