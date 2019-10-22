/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:41:30 by blacking          #+#    #+#             */
/*   Updated: 2019/10/22 16:02:54 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int ft_newline(char *buf)
{
	while(*buf)
	{
		if(*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

size_t ft_strlen(const char *s) {
	size_t count;

	count = 0;
	if(s == 0)
		return 0;
	while(s[count])
		count++;
	return count;
}


char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	if(!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


int get_next_line(int fd, char **line)
{
	char *buf;
	int  read_file;

	read_file = 1;
	if(!(buf = (char *)malloc(sizeof(char) *(BUFFER_SIZE + 1))) ||
			!line || fd == -1)
		return (-1);
	while(read_file > 0)
	{
		read_file = read(fd, buf, BUFFER_SIZE);
		if(read_file != 0 && *buf != '\n')
		{
			*line = ft_strdup(buf);
			if(ft_newline(buf) == 1)
				return (1);
		} 
		printf("line: %s fd : %d\n", *line,  read_file);
	}
	return (0);
}
