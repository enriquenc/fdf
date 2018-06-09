/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:56:35 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/31 16:56:37 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	keyboard_2(int key, t_window *window)
{
	if (key == 69)
	{
		clear(window);
		change_z(window, 3);
	}
	else if (key == 78)
	{
		clear(window);
		change_z(window, -3);
	}
	else if (key == 126)
	{
		clear(window);
		change_y(window, -2);
	}
	else if (key == 125)
	{
		clear(window);
		change_y(window, 2);
	}
	else if (key == 123)
	{
		clear(window);
		change_x(window, -2);
	}
}

static void	keyboard_3(int key, t_window *window)
{
	if (key == 124)
	{
		clear(window);
		change_x(window, 2);
	}
	else if (key == 91)
	{
		clear(window);
		window->dgrs.rx += 0.2;
		draw_image(window);
	}
	else if (key == 84)
	{
		clear(window);
		window->dgrs.rx -= 0.2;
		draw_image(window);
	}
	else if (key == 86)
	{
		clear(window);
		window->dgrs.ry += 0.2;
		draw_image(window);
	}
}

static void	keyboard_4(int key, t_window *window)
{
	if (key == 88)
	{
		clear(window);
		window->dgrs.ry -= 0.2;
		draw_image(window);
	}
	else if (key == 116)
	{
		clear(window);
		window->zoom *= 1.2;
		draw_image(window);
	}
	else if (key == 121)
	{
		clear(window);
		window->zoom *= 0.8;
		draw_image(window);
	}
	else if (key == 53)
	{
		exit(EXIT_SUCCESS);
	}
}

int			keyboard(int key, void *param)
{
	t_window *window;

	window = (t_window *)param;
	window->clear = 0;
	keyboard_2(key, window);
	keyboard_3(key, window);
	keyboard_4(key, window);
	if (window->clear)
		print_help(window);
	return (0);
}

int			exit_x(void)
{
	exit(1);
}
