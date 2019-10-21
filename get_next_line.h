/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:29:52 by blacking          #+#    #+#             */
/*   Updated: 2019/10/21 19:35:41 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H
#	include <unistd.h>
#	include <stdlib.h>

int get_next_line(int fd, char **line);

#endif
