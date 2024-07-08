/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wil <wil@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:05:50 by josegar2          #+#    #+#             */
/*   Updated: 2024/07/08 12:36:40 by wil              ###   ########.fr       */
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

	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL)
		return (1);
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

int	copy_rgb(t_file *file, char *s, int **rgb)
{
	int		i;
	char	**tmp;

	i = 1;
	if (s[i] != ' ' && s[i] != '\t')
		return (message("Not valid map file\n"), 1);
	if (*rgb != NULL)
		return (message("Duplicated color entry\n"), 1);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[ft_strlen(s) - 1] == '\n')
		s[ft_strlen(s) - 1] = '\0';
	if (s[i] == '\0')
		return (message("No color information\n"), 1);
	tmp = ft_split(&s[i], ',');
	if (check_rgb(tmp) == 1)
		return (message("RGB info not valid\n"), ft_free_split(tmp), 1);
	*rgb = ft_calloc(3, sizeof(int));
	(*rgb)[0] = ft_atoi(tmp[0]);
	(*rgb)[1] = ft_atoi(tmp[1]);
	(*rgb)[2] = ft_atoi(tmp[2]);
	if (max_min_rgb(*rgb) == 1)
		return (message("RGB out of range\n"), ft_free_split(tmp), 1);
	file->data_ok++;
	return (ft_free_split(tmp), 0);
}

int	copy_path(t_file *file, char *s, char **tpath)
{
	int	i;

	i = 2;
	if (s[i] != ' ' && s[i] != '\t')
		return (message("Not valid map file\n"), 1);
	if (*tpath != NULL)
		return (message("Duplicated texture entry\n"), 1);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[ft_strlen(s) - 1] == '\n')
		s[ft_strlen(s) - 1] = '\0';
	if (s[i] == '\0')
		return (message("No texture path\n"), 1);
	*tpath = ft_strdup(&s[i]);
	if (*tpath == NULL)
		return (message("String duplication error\n"), 1);
	file->data_ok += 1;
	return (0);
}

int	load_arg(char *line, t_file *file)
{
	char	**tpath;
	int		i;

	i = 0;
	tpath = NULL;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!ft_strncmp("NO", &line[i], 2))
		tpath = &(file->no);
	else if (!ft_strncmp("SO", &line[i], 2))
		tpath = &(file->so);
	else if (!ft_strncmp("EA", &line[i], 2))
		tpath = &(file->ea);
	else if (!ft_strncmp("WE", &line[i], 2))
		tpath = &(file->we);
	if (tpath)
		return (copy_path(file, &line[i], tpath));
	if (line[i] == 'F')
		return (copy_rgb(file, &line[i], &(file->f)));
	if (line[i] == 'C')
		return (copy_rgb(file, &line[i], &(file->c)));
	return (message("Not valid entry in map file\n"), 1);
}
