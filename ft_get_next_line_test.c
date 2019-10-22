/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:24:33 by stbaleba          #+#    #+#             */
/*   Updated: 2019/10/22 18:10:40 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../get_next_line.h"

static void 	ft_check_get_new_line(int fd, char **line)
{
	int fd_res = 0;
	printf("fd before gnl : %d\n", fd);
	fd_res = get_next_line(fd, line);
	printf("fd after gnl : %d\n", fd_res);
	if (fd_res != -1)
		printf("line read by gnl : %s\n", *line);
}


int main()
{
	char **line;
	line = (char **)malloc(sizeof(char *));
	int fd = open("./test0", O_RDWR);
	ft_check_get_new_line(fd, line);
	close(fd);
	fd = open("./test1", O_RDWR);
	ft_check_get_new_line(fd, line);
	close(fd);
	fd = open("./test2", O_RDWR);
	ft_check_get_new_line(fd, line);
	close(fd);
}
