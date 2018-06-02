/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:45:38 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/31 16:45:39 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_drawline	init_dr(t_pixel p0, t_pixel p1, int max_z)
{
	t_drawline dr;

	dr.dx = abs(p1.x - p0.x);
	dr.sx = (p0.x < p1.x) ? 1 : -1;
	dr.dy = abs(p1.y - p0.y);
	dr.sy = (p0.y < p1.y) ? 1 : -1;
	dr.err = (dr.dx > dr.dy ? dr.dx : -dr.dy) / 2;
	if (max_z)
		dr.x = (0xFFFFFF - 0xBC0505) / max_z;
	else
		dr.x = 0xffffff;
	return (dr);
}

static int	find_max_z(t_window *window)
{
	int i;
	int j;
	int res;

	i = 0;
	j = 0;
	res = window->map[0][0]->z;
	while (i < window->height)
	{
		j = 0;
		while (j < window->width)
		{
			if (window->map[i][j]->z > res)
				res = window->map[i][j]->z;
			j++;
		}
		i++;
	}
	return (res);
}

void		init(t_window *window)
{
	int size;

	size = 32;
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr,
	WIDTH, HEIGHT, "tmaslyan's fdf");
	window->img_ptr = mlx_new_image(window->mlx_ptr, WIDTH, HEIGHT);
	window->img_data_addr = mlx_get_data_addr(window->img_ptr,
	&size, &size, &size);
	window->max_z = find_max_z(window);
	window->dgrs.rx = -1;
	window->dgrs.ry = 0.5;
	window->dgrs.rz = 0;
	window->zoom = 1;
}

int			is_valid(char *fd_content, t_window *window)
{
	int words;
	int height;
	int i;

	i = 0;
	height = 0;
	words = 0;
	while (*fd_content)
	{
		pass_spaces((const char **)&fd_content);
		if (!ft_isdigit(*fd_content))
			return (-1);
		i++;
		while (is_str(*fd_content, ",0123456789abcdefxABCDEF"))
			fd_content++;
		pass_spaces((const char **)&fd_content);
		if (*fd_content == '\n')
			if (check_row(&height, &words, &fd_content, i))
				return (-1);
	}
	window->width = words;
	window->height = height;
	return (0);
}

void		give_memory(t_window *window)
{
	int i;

	window->map = (t_pixel ***)malloc(sizeof(t_pixel **) * window->height);
	i = -1;
	while (++i < window->height)
		window->map[i] = (t_pixel **)malloc(sizeof(t_pixel *) * window->width);
}
