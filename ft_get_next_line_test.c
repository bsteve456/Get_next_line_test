/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:24:33 by stbaleba          #+#    #+#             */
/*   Updated: 2019/10/24 23:32:39 by blacking         ###   ########.fr       */
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

static void ft_check_gnl_loop(int fd, char **line)
{
	int i = 0;
	int fd_res = 1;
	printf("fd before gnl : %d\n", fd);
	while(fd_res > 0) {
		printf("---%d loop---\n", i);
		fd_res = get_next_line(fd, line);
		i++;
		printf("fd after gnl : %d\n", fd_res);
		if (fd_res != -1)
			printf("line read by gnl : %s\n", *line);
	}
}


int main()
{
	char *line = NULL;
	int fd = 0;
//	fd = open("./test0", O_RDWR);
//	printf("---Test_GNL_0---\n");
//	ft_check_get_new_line(fd, &line);
//	close(fd);
//	printf("---Test_GNL_1---\n");
//	fd = open("./test1", O_RDWR);
//	ft_check_get_new_line(fd, &line);
//	close(fd);
//	printf("---Test_GNL_2---\n");
//	fd = open("./test2", O_RDWR);
//	ft_check_get_new_line(fd, &line);
//	close(fd);
//	printf("---Test_GNL_3---\n");
//	fd = open("./test3", O_RDWR);
//	ft_check_gnl_loop(fd, &line);
//	close(fd);
//	printf("---Test_GNL_4---\n");
//	fd = open("./test4", O_RDWR);
//	ft_check_gnl_loop(fd, &line);
//	close(fd);
//	printf("----RANDOM-----\n");
//	fd = open("/dev/random", O_RDWR);
//	ft_check_gnl_loop(fd, &line);
//	close(fd);
//	printf("---Test_GNL_5---\n");
//	fd = open("../ft_get_next_line.c", O_RDWR);
//	ft_check_gnl_loop(fd, &line);
//	close(fd);
//	printf("---Test_GNL_6---\n");
//	fd = open("./test_basic_dino.txt", O_RDWR);
//	ft_check_gnl_loop(fd, &line);
//	close(fd);
//	printf("---Test_GNL_7---\n");
//	fd = open("./test_basic.txt", O_RDWR);
//	ft_check_gnl_loop(fd, &line);
//	close(fd);
//	printf("---Test_GNL_8---\n");
//	fd = open("./test_null_cases.txt", O_RDWR);
//	ft_check_gnl_loop(fd, &line);
//	close(fd);
//	printf("---Test_GNL_9---\n");
//	fd = open("./timmy_test_a.txt", O_RDWR);
//	ft_check_gnl_loop(fd, &line);
//	close(fd);
//	printf("---Test_GNL_10---\n");
//	fd = open("./timmy_test_b.txt", O_RDWR);
//	ft_check_gnl_loop(fd, &line);
//	close(fd);
	printf("---Test_GNL_11---\n");
	fd = open("./timmy_test_interleave.txt", O_RDWR);
	ft_check_gnl_loop(fd, &line);
	close(fd);
//	int i = 0;
//	while(i < 3){
//		get_next_line(0, &line);
//		printf("%s\n", line);
//		i++;
//	}
}
