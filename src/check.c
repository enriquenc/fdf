/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 17:02:21 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/06/02 17:02:21 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	check_fd(char *file)
{
	int fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
		return (1);
	return (0);
}

int	end_read(char *fd_content, int fd, t_window *window)
{
	if (!fd_content)
		return (-1);
	if (reader_optimz(fd_content, fd, window))
		return (-1);
	free(fd_content);
	return (0);
}
