/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 04:52:31 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/20 04:52:32 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			check_row(int *height, int *words, char **fd_content, int i)
{
	*height += 1;
	if (!*words)
		*words = i;
	else if (i % *words)
		return (-1);
	(*fd_content)++;
	return (0);
}

static void	parse_optimz(t_window *window, int k, char **split_row)
{
	int i;
	int j;

	i = 0;
	while (i < window->width)
	{
		window->map[k][i] = (t_pixel *)malloc(sizeof(t_pixel));
		window->map[k][i]->x = i;
		window->map[k][i]->y = k;
		window->map[k][i]->z = ft_atoi(split_row[i]);
		window->map[k][i]->first_z = window->map[k][i]->z;
		j = 0;
		while (split_row[i][j])
		{
			if (split_row[i][j] == ',')
			{
				j++;
				window->map[k][i]->color = hex_to_digit((split_row[i] + j));
				break ;
			}
			window->map[k][i]->color = 0;
			j++;
		}
		i++;
	}
}

static int	parse_content(t_window *window, char *fd_content)
{
	int		i;
	int		j;
	int		k;
	char	**split_map;
	char	**split_row;

	give_memory(window);
	k = 0;
	i = 0;
	j = 0;
	split_map = ft_strsplit(fd_content, '\n');
	while (k < window->height)
	{
		split_row = ft_strsplit(split_map[k], ' ');
		i = 0;
		parse_optimz(window, k, split_row);
		to_free(split_row, window->width);
		k++;
	}
	to_free(split_map, window->height);
	return (0);
}

int			reader_optimz(char *fd_content, int fd, t_window *window)
{
	if (is_valid(fd_content, window))
	{
		free(fd_content);
		close(fd);
		return (-1);
	}
	parse_content(window, fd_content);
	return (0);
}

int			reader(t_window *window, char *file)
{
	int		fd;
	char	*buf;
	char	*fd_content;
	int		check;
	int		words;

	fd_content = NULL;
	words = 0;
	if (check_fd(file))
		return (-1);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	while ((check = get_next_line(fd, &buf)))
	{
		if (check == -1)
			return (-1);
		fd_content = ft_strjoin(fd_content, buf);
		fd_content = ft_strjoin(fd_content, "\n");
		free(buf);
	}
	if (end_read(fd_content, fd, window))
		return (-1);
	return (0);
}
