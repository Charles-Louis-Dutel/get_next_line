/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:01:37 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/26 12:59:08 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*data;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_new_line(t_list *temp);
void	ft_new_temp(t_list **temp);
t_list	*ft_get_last(t_list *temp);
void	ft_free_list(t_list *temp);
int		ft_slen(char *s);

#endif
