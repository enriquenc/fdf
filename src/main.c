/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 02:12:37 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/20 02:12:38 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int ac, char **av)
{
	t_window *window;

	if (ac != 2)
	{
		ft_printf("usage: ./fdf [file]\n");
		return (1);
	}
	window = (t_window *)malloc(sizeof(t_window));
	if (reader(window, av[1]) == -1)
	{
		ft_printf("Error! Wrong file.\n");
		free(window);
		return (0);
	}
	init(window);
	draw_image(window);
	print_help(window);
	mlx_hook(window->win_ptr, 2, 1L << 0, keyboard, window);
	mlx_hook(window->win_ptr, 17, 1L << 17, exit_x, 0);
	mlx_loop(window->mlx_ptr);
	mlx_clear_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	free(window);
	return (0);
}
