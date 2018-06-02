/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 04:29:08 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/20 04:29:09 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 2000
# define HEIGHT 1300

typedef struct	s_pixel
{
	int x;
	int y;
	int z;
	int first_z;
	int color;
}				t_pixel;

typedef struct	s_degree
{
	double rx;
	double ry;
	double rz;
}				t_degree;

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data_addr;
	t_pixel		***map;
	int			max_z;
	int			width;
	int			height;
	t_degree	dgrs;
	float		zoom;
}				t_window;

typedef struct	s_drawline
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
	int x;
}				t_drawline;

int				reader(t_window *window, char *file);
t_pixel			transform_point(t_window *window, int i, int j);
void			draw_line(t_pixel p0, t_pixel p1, t_window *window, int max_z);
void			put_pix_to_img(t_window *window, int x, int y, int color);
void			draw_image(t_window *window);
void			draw_line_to_image(int i, int j, t_window *window);
t_drawline		init_dr(t_pixel p0, t_pixel p1, int max_z);
int				exit_x(void);
int				keyboard(int key, void *param);
void			change_z(t_window *window, int x);
void			change_y(t_window *window, int x);
void			change_x(t_window *window, int x);
void			init(t_window *window);
int				hex_to_digit(char *str);
void			clear(t_window *window);
void			print_help(t_window *window);
void			to_free(char **to_free, int size);
int				is_valid(char *fd_content, t_window *window);
void			give_memory(t_window *window);
int				check_row(int *height, int *words, char **fd_content, int i);
int				check_fd(char *file);
int				end_read(char *fd_content, int fd, t_window *window);
int				reader_optimz(char *fd_content, int fd, t_window *window);

#endif
