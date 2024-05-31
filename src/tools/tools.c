/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:09:52 by codespace         #+#    #+#             */
/*   Updated: 2024/05/31 15:56:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	message(char *msg)
{
	printf("%s", msg);
}

char	*ft_replace(char *s, char og, char re)
{
	char *result;
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	result = malloc((ft_strlen_n(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s[i])
	{
		if (s[i] == og)
			result[i] = re;
		else
			result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}



//under dev due issues with spaces. Calculating before map spaces and after map spaces without accepting mid map spaces.
bool	valid_map_line(char *line)
{
	int		i;
	char	*tmp;
	char	*cl;

	i = 0;
	tmp = ft_replace(line, '\t', ' ');
	cl = ft_replace(tmp, '\n', ' ');
	free(tmp);
	if (cl[i] == ' ')
	{
		while (cl[i] == ' ')
			i++;
	}
	if (cl[i] == '1' || cl[i] == '0' || cl[i] == 'N' || cl[i] == 'S'
		|| cl[i] == 'E' || cl[i] == 'W')
	{
		while (cl[i] == '1' || cl[i] == '0' || cl[i] == 'N' || cl[i] == 'S'
		|| cl[i] == 'E' || cl[i] == 'W')
			i++;
		if (cl[i] == ' ')
		{
			while (cl[i] == ' ')
				i++;
			if (cl[i] != '\0')
				return (message("Error, Space inside the map\n"), false);
		}
		else if (cl[i] != ' ' && cl[i] != '\0')
			return (message("Error, Space inside the map2\n"), false);
	}
	else
		return (message("Error, invalid map\n"), false);
	free(cl);
	return (true);
}

		// if (cl[i] != '1' && cl[i] != '0' && cl[i] != 'N' && cl[i] != 'S'
		// 	&& cl[i] != 'E' && cl[i] != 'W')

bool	bool_digit(int val)
{
	if (val >= '0' && val <= '9')
		return (true);
	else
		return (false);
}

bool	check_is_num(char *s)
{
	int	i;

	i = 1;
	if (s[0] == '+' || (s[0] >= '0' && s[0] <= '9'))
	{
		while (s[i] != '\0')
		{
			if (bool_digit(s[i]) == false)
				return (false);
			i++;
		}
	}
	else
		return (false);
	return (true);
}

int	ft_strlen_n(const char *var)
{
	int	count;

	count = 0;
	while (var[count] != '\0' && var[count] != '\n')
		count++;
	return (count);
}

int	check_ext(char *argv, char *text)
{
	int	tmp;

	tmp = ft_strlen_n(argv);
	if (ft_strncmp(&argv[tmp - 4], text, 4) != 0)
		return (-1);
	return (0);
}

bool	line_is_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' || line[i] != '\t' || line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}
