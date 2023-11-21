/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:01:32 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/21 08:25:14 by cdutel           ###   ########.fr       */
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

static char	*ft_check_newline(char *s)
{
	int	i;
	int	start;
	char	*after_new_line;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	start = i;
	while (s[i])
		i++;
	if (s[start] == '\n')
	{
		after_new_line = malloc(sizeof(char) * (i - start));
		if (!after_new_line)
			return (NULL);
		i = 0;
		while (s[start + 1])
		{
			after_new_line[i] = s[start + 1];
			i++;
			start++;
		}
		return (after_new_line);
	}
	return (s);
}

static char *ft_return_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n' || s[i + 1] == '\0')
	{
		line = malloc(sizeof(char) * i + 1);
		if (!line)
			return (NULL);
		i = 0;
		while (s[i] && s[i] != '\n')
		{
			line[i] = s[i];
			i++;
		}
		line[i] = s[i];
		i++;
		line[i] = '\0';
		return (line);
	}
	return (NULL);
}

int	ft_check_backslash_n(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*dest = NULL;
	char		*line = NULL;
	static char	*temp;
	int			i;
	int			j;
	int			value;

	dest = malloc(sizeof(char) * BUFFER_SIZE);
	value = read(fd, dest, BUFFER_SIZE);
	/*if (value == 0)
		return(NULL);*/
	//printf("%s\n", dest);
	if (temp)
		line = ft_check_newline(temp);
	//printf("%s\n", line);
	temp = malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(line) + 1));
	if (!temp)
	{
		free(temp);
		return (NULL);
	}
	i = 0;
	if (line != NULL)
	{
		while (line[i])
		{
			temp[i] = line[i];
			i++;
		}
	}
	j = 0;
	while (dest[j])
	{
		temp[i] = dest[j];
		i++;
		j++;
	}
	free(dest);
	free(line);
	//printf("%s\n", temp);
	//printf("%d\n", ft_check_backslash_n(temp));
	if (ft_check_backslash_n(temp) == 0)
		get_next_line(fd);
	if (ft_check_backslash_n(temp) == 1)
	{
		line = ft_return_line(temp);
		return(line);
	}
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
