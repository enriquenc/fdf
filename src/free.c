/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 22:01:51 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/31 22:01:53 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	clear(t_window *window)
{
	mlx_clear_window(window->mlx_ptr, window->win_ptr);
	ft_bzero(window->img_data_addr, WIDTH * HEIGHT * 4);
}

void	print_help(t_window *window)
{
	mlx_string_put(window->mlx_ptr, window->win_ptr,
		0, 0, 0xe08600, "NumPad:\n");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
		0, 20, 0xe08600, "1) + and - for change z.");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
		0, 40, 0xe08600, "2) 2, 4, 6, 8 and arrows - for rotation.");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
		0, 60, 0xe08600, "3) Page-up and Page-down for zoom.");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
		0, 80, 0xe08600, "@tmaslyan's project fdf.");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
		0, 100, 0xe08600, "P.S. press 1 to open this prompt.");
}

void	to_free(char **to_free, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}
