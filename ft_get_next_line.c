/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:41:30 by blacking          #+#    #+#             */
/*   Updated: 2019/10/22 18:37:46 by blacking         ###   ########.fr       */
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

void	*ft_calloc(size_t count, size_t size) {
	size_t i;
	unsigned char *data;

	i = 0;
	if(!(data = (unsigned char *)malloc(size * count)))
		return (NULL);
	while(i < size * count)
	{
		data[i] = '\0';
		i++;
	}
	return (data);
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


char	*ft_strmcat(const char *line, const char *buf)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if(!(dest = (char *)malloc(sizeof(char) *
	(ft_strlen(line) + ft_strlen(buf) + 1))))
		return (NULL);
	while (line[i] || (buf[j] && buf[j] != '\n'))
	{
		if(line[i])
			dest[i] = line[i];
		else
		{
			dest[i] = buf[j];
			j++;
		}
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
	if(!(buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1))) ||
	!line || fd == -1 || !(*line = ft_calloc(sizeof(char), (BUFFER_SIZE + 1))))
		return (-1);
	while(read_file > 0)
	{
		read_file = read(fd, buf, BUFFER_SIZE);
		if(read_file != 0 && *buf != '\n')
		{
			*line = ft_strmcat(*line, buf);
			if(ft_newline(buf) == 1)
				return (1);
		}
		printf("line: %s fd : %d\n", *line,  read_file);
	}
	if(**line)
		return (1);
	return (0);
}
