/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:09:52 by codespace         #+#    #+#             */
/*   Updated: 2024/05/27 14:47:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

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
