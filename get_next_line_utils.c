/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:01:19 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/23 13:53:22 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line(char *temp)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	new_line = ft_calloc((i + 2), sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		new_line[i] = temp[i];
		i++;
	}
	if (temp[i] && temp[i] == '\n')
	{
		new_line[i] = '\n';
		i++;
	}
	return (new_line);
}

char	*ft_new_temp(char *temp)
{
	char	*new_temp;
	int		i;
	int		j;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	new_temp = ft_calloc((ft_len(temp) - i + 1), sizeof(char));
	if (!new_temp)
		return (NULL);
	i++;
	j = 0;
	while (temp[i])
	{
		new_temp[j] = temp[i];
		i++;
		j++;
	}
	free(temp);
	return (new_temp);
}

int	ft_len(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char				*ptr;
	unsigned long		i;

	if (size == 0)
		return (malloc(0));
	if (nmemb > 2147483647 / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
