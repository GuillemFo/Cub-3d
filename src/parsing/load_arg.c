/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:05:50 by josegar2          #+#    #+#             */
/*   Updated: 2024/06/12 20:12:04 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	max_min_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] > 255 || rgb[i] < 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (check_is_num(rgb[i]) == false)
			return (1);
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

int	copy_rgb(char *s, int **rgb)
{
	char	*polished;
	char	**tmp;
	char	**tmp1;

	polished = ft_replace(s, '\n', ' ');
	tmp1 = ft_split(polished, ' ');
	tmp = ft_split(tmp1[1], ',');
	ft_free_split(tmp1);
	if (check_rgb(tmp) == 1)
		return (message("Error, rgb not valid\n"), ft_free_split(tmp), 1);
	*rgb = malloc(3 * sizeof(int));
	(*rgb)[0] = ft_atoi(tmp[0]);
	(*rgb)[1] = ft_atoi(tmp[1]);
	(*rgb)[2] = ft_atoi(tmp[2]);
	if (max_min_rgb(*rgb) == 1)
		return (message("Error, rgb out of range\n"), ft_free_split(tmp), 1);
	ft_free_split(tmp);
	return (0);
}

char	*copy_path(char *s)
{
	char	*path;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[i] == ' ')
		i++;
	len = (ft_strlen(&s[i]) + 1);
	path = malloc((len + 1) * sizeof(char));
	ft_strlcpy(path, &s[i], len);
	return (path);
}

int	load_arg(char *line, t_file *file)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_replace(line, '\t', ' ');
	if (tmp[i] == ' ')
	{
		while (tmp[i] == ' ')
			i++;
	}
	if (tmp[i] == 'N' && tmp[i + 1] == 'O' && tmp[i + 2] == ' ')
	{
		if (file->NO == NULL)
		{
			file->NO = copy_path(&tmp[i + 2]);
			file->data_ok += 1;
		}
		else
			return (message("Multiple arguments for NO\n"), 1);
	}
	else if (tmp[i] == 'S' && tmp[i + 1] == 'O' && tmp[i + 2] == ' ')
	{
		if (file->SO == NULL)
		{
			file->SO = copy_path(&tmp[i + 2]);
			file->data_ok += 1;
		}
		else
			return (message("Multiple arguments for SO\n"), 1);
	}
	else if (tmp[i] == 'E' && tmp[i + 1] == 'A' && tmp[i + 2] == ' ')
	{
		if (file->EA == NULL)
		{
			file->EA = copy_path(&tmp[i + 2]);
			file->data_ok += 1;
		}
		else
			return (message("Multiple arguments for EA\n"), 1);
	}
	else if (tmp[i] == 'W' && tmp[i + 1] == 'E' && tmp[i + 2] == ' ')
	{
		if (file->WE == NULL)
		{
			file->WE = copy_path(&tmp[i + 2]);
			file->data_ok += 1;
		}
		else
			return (message("Multiple arguments for WE\n"), 1);
	}
	else if (tmp[i] == 'F' && tmp[i + 1] == ' ')
	{
		if (file->F_flag == 0 && copy_rgb(&tmp[i], &(file->F)) == 0)
		{
			file->data_ok += 1;
			file->F_flag = 1;
		}
		else
			return (message("Incorrect floor info\n"), 1);
	}
	else if (tmp[i] == 'C' && tmp[i + 1] == ' ')
	{
		if (file->C_flag == 0 && copy_rgb(&tmp[i], &(file->C)) == 0)
		{
			file->data_ok += 1;
			file->C_flag = 1;
		}
		else
			return (message("Incorrect ceiling info\n"), 1);
	}
	else
		return (message("Not valid map file\n"), 1);
	return (0);
}
