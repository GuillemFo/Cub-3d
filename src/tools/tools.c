/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:09:52 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 13:27:54 by codespace        ###   ########.fr       */
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
	result = malloc((ft_strlen(s) + 1) * sizeof(char));
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

bool	valid_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
		{
			while (line[i] == ' ')
				i++;
		}
		if (line[i] != '1' || line[i] != '0' || line[i] != 'N' || line[i] != 'S'
			|| line[i] != 'E' || line[i] != 'W')
			return (false);
		i++;
	}
	return (true);
}

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
