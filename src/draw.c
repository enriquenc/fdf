/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:19:23 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/31 15:19:24 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		put_pix_to_img(t_window *window, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *)(window->img_data_addr + ((x + y * WIDTH) * 4)) = color;
}

t_pixel		transform_point(t_window *window, int i, int j)
{
	t_pixel p0;
	t_pixel p1;
	t_pixel p2;

	p0.x = window->map[i][j]->x * WIDTH / 2 / window->width;
	p0.y = window->map[i][j]->y * HEIGHT / 2 / window->height *
	cos(window->dgrs.rx) + window->map[i][j]->z * sin(window->dgrs.rx);
	p0.z = window->map[i][j]->z * cos(window->dgrs.rx) - window->map[i][j]->y *
		HEIGHT / 2 / window->height * sin(window->dgrs.rx);
	p1.x = p0.x * cos(window->dgrs.ry) - p0.z * sin(window->dgrs.ry);
	p1.y = p0.y;
	p1.z = p0.z * cos(window->dgrs.ry) + p0.x * sin(window->dgrs.ry);
	p2.x = p1.x * cos(window->dgrs.rz) + p1.y * sin(window->dgrs.rz);
	p2.y = p1.y * cos(window->dgrs.rz) - p1.x * sin(window->dgrs.rz);
	p2.z = window->map[i][j]->z;
	p2.color = window->map[i][j]->color;
	p2.x = p2.x * window->zoom + WIDTH / 2;
	p2.y = p2.y * window->zoom + HEIGHT / 2;
	return (p2);
}

void		draw_line(t_pixel p0, t_pixel p1, t_window *window, int max_z)
{
	t_drawline dr;

	dr = init_dr(p0, p1, max_z);
	while (1)
	{
		if (!p0.color && !p0.color)
			put_pix_to_img(window, p0.x, p0.y, 0xCCFF00 + dr.x *
			(abs(p0.z) > abs(p1.z) ? abs(p0.z) : abs(p1.z)));
		else
			put_pix_to_img(window, p0.x, p0.y, p0.color ? p0.color : p1.color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		dr.e2 = dr.err;
		if (dr.e2 > -dr.dx)
		{
			dr.err -= dr.dy;
			p0.x += dr.sx;
		}
		if (dr.e2 < dr.dy)
		{
			dr.err += dr.dx;
			p0.y += dr.sy;
		}
	}
}

void		draw_line_to_image(int i, int j, t_window *window)
{
	t_pixel p0;
	t_pixel p1;

	if (i)
	{
		p0 = transform_point(window, i - 1, j);
		p1 = transform_point(window, i, j);
		draw_line(p0, p1, window, window->max_z);
	}
	if (j)
	{
		p0 = transform_point(window, i, j - 1);
		p1 = transform_point(window, i, j);
		draw_line(p0, p1, window, window->max_z);
	}
}

void		draw_image(t_window *window)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < window->height)
	{
		j = 0;
		while (j < window->width)
		{
			draw_line_to_image(i, j, window);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->img_ptr, 0, 0);
}
