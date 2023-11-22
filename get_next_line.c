/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:01:32 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/22 10:05:21 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_strlen(char *s)
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

char	*ft_update_temp(char *dest, char *temp)
{
	int	i;
	int	j;

	if (temp == NULL)
		i = 0;
	else
		i = ft_strlen(temp);
	j = 0;
	while (dest[j])
	{
		temp[i] = dest[j];
		i++;
		j++;
	}
	temp[i] = '\0';
	return (temp);
}

int	ft_check_temp(char *temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n' || temp[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*dest;
	char		*line;
	int			trigger;
	int			value;

	if (!temp)
	{
		temp = malloc(sizeof(char) * 1000);
		if (!temp)
			return (NULL);
	}
	trigger = 0;
	while (trigger == 0)
	{
		dest = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!dest)
			return(NULL);
		value = read(fd, dest, BUFFER_SIZE);
		temp = ft_update_temp(dest, temp);
		if (ft_check_temp(temp) == 1)
			trigger = 1;
		if (value < BUFFER_SIZE)
			trigger = 1;
	}
	if (ft_check_temp(temp) == 1)
	{
		line = ft_new_line(temp);
		temp = ft_new_temp(temp);
		return (line);
	}
	if (value == 0)
		return (NULL);
	return (NULL);
}

int main()
{
	int	fd;
	char *test;
	int i = 0;

	fd = open("caca.txt", O_RDONLY);
	test = get_next_line(fd);
	printf("%s", test);
	while (i < 6)
	{
		test = get_next_line(fd);
		printf("%s", test);
		i++;
	}
	return 0;
}
