/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:09:52 by codespace         #+#    #+#             */
/*   Updated: 2024/06/15 11:44:12 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//ISSUE CHECKING IF MAP HAS SPACES INSIDE BUT SURROUNDED BY 1
//REDO FUNCTION
bool	valid_map_line(t_file *file, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_strchr("NSEW", line[i]))
		return (message("Starting point out of map\n"), false);
	while (line[i] && line[i] != '\n' && line[i] != ' ')
	{
		if (ft_strchr("NSEW", line[i]) && file->sty)
			return (message("More than one starting point\n"), false);
		if (!ft_strchr("10NSEW", line[i]))
			return (message("Wrong char in map\n"), false);
		if (ft_strchr("NSEW", line[i]))
			file->sty++;
		i++;
	}
	while (line[i] && line[i] != '\n')
		if (line[i++] != ' ')
			return (message("Space inside the map\n"), false);
	return (true);
}

bool	check_is_num(char *s)
{
	int	i;

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
		if (ft_strchr("10", line[i]))
			return (true);
	}
	return (false);
}
