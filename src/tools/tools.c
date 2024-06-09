/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:09:52 by codespace         #+#    #+#             */
/*   Updated: 2024/06/09 16:26:45 by gforns-s         ###   ########.fr       */
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

	i = 0;
	tmp = clean_l(line);
	if (tmp[i] == ' ')
	{
		while (tmp[i] == ' ')
			i++;
	}
	if (tmp[i] == '1' || tmp[i] == '0' || tmp[i] == 'N' || tmp[i] == 'S'
		|| tmp[i] == 'E' || tmp[i] == 'W')
	{
		while (tmp[i] == '1' || tmp[i] == '0' || tmp[i] == 'N' || tmp[i] == 'S'
		|| tmp[i] == 'E' || tmp[i] == 'W')
			i++;
		if (tmp[i] == ' ')
		{
			while (tmp[i] == ' ')
				i++;
			if (tmp[i] != '\0')
				return (message("Error, Space inside the map\n"), false);
		}
		else if (tmp[i] != ' ' && tmp[i] != '\0')
			return (message("Error, Space inside the map2\n"), false);
	}
	else
		return (message("Error, invalid map\n"), false);
	free(tmp);
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

bool	has_map(char *line)
{
	int	i;

	i = 0;
	if (line && line[0] != '\0')
	{
		if (line[i] == ' ')
		{
			while (line[i] == ' ')
				i++;
		}
		if (line[i] == '1' || line[i] == '0' )
			return (true);
		else if (line[i] == 'N' || line[i] == 'E' || line[i] == 'W' ||
			line[i] == 'S')
			return (false);	//(message("Error, player out of the map\n"), false);
	}
	return (false);
}

char	*clean_tabs(char *line)
{
	char	*cl;
	
	cl = ft_replace(line, '\t', ' ');
	return (cl);
}

int	check_ext_sp(char *str, char *text)
{
	int	i;

	if (str && str[0] != '\0')
	{
		i = ft_strlen(str);
		while (str[i] == ' ' && str[i - 1])
			i--;
		if (ft_strncmp(&str[i - 4], text, 4) != 0)
			return (-1);
	}
	return (0);
}

void	print_map_term(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("--%s--\n", map[i]);
		i++;
	}
}