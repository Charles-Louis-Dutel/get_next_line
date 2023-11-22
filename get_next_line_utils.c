/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:01:19 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/22 15:11:22 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line(char temp[])
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

void	ft_new_temp(char temp[])
{
	int		i;
	int		start;

	i = 0;
	while (temp[i] != '\n')
		i++;
	start = i + 1;
	i = 0;
	while (temp[start])
	{
		temp[i] = temp[start];
		i++;
		start++;
	}
	while (temp[i])
	{
		temp[i] = '\0';
	}
}
