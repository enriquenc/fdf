/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:37:06 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/31 18:37:07 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	change_z(t_window *window, int x)
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
			if (abs(window->map[i][j]->first_z) >= 10)
				window->map[i][j]->z = window->map[i][j]->z + x;
			draw_line_to_image(i, j, window);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(window->mlx_ptr,
		window->win_ptr, window->img_ptr, 0, 0);
}

void	change_y(t_window *window, int x)
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
			window->map[i][j]->y = window->map[i][j]->y + x;
			draw_line_to_image(i, j, window);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(window->mlx_ptr,
		window->win_ptr, window->img_ptr, 0, 0);
}

void	change_x(t_window *window, int x)
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
			window->map[i][j]->x = window->map[i][j]->x + x;
			draw_line_to_image(i, j, window);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(window->mlx_ptr,
		window->win_ptr, window->img_ptr, 0, 0);
}
