/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:01:19 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/21 14:30:11 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line(char *temp)
{
	int		i;
	char	*new_line;

	i = 0;
	while (temp[i] != '\n')
		i++;
	new_line = malloc(sizeof(char) * i + 2);
	if (!new_line)
		return (NULL);
	i = 0;
	while (temp[i] != '\n')
	{
		new_line[i] = temp[i];
		i++;
	}
	new_line[i] = temp[i];
	i++;
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_new_temp(char *temp)
{
	char	*new_temp;
	int		i;
	int		start;

	i = 0;
	while (temp[i] != '\n')
		i++;
	start = i + 1;
	while (temp[i])
		i++;
	new_temp = malloc(sizeof(char) * (i - start + 1));
	if (!new_temp)
		return (NULL);
	i = 0;
	while (temp[start])
	{
		new_temp[i] = temp[start];
		i++;
		start++;
	}
	new_temp[i] = '\0';
	free(temp);
	return (new_temp);
}
