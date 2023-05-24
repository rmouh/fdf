/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:10:19 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/05/24 18:30:25 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		i;
	
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return ;
	i = data->bpp - 8;
	pixel = data->addr + (y * data->len + x * (data->bpp / 8));
	while (i >= 0)
	{
		if (data->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (data->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	min_and_val(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (1);
	return (-1);
}

void	plot_line(int x0, int y0, int x1, int y1, t_data *img, int color)
{
	t_coor	coor;
	int		err;
	int		res;

	coor.dx = abs (x1 - x0);
	coor.sx = min_and_val(x0, x1);
	coor.dy = -abs (y1 - y0);
	coor.sy = min_and_val(y0, y1);
	err = coor.dx + coor.dy;
	while (1)
	{
		my_mlx_pixel_put(img, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		coor.e2 = 2 * err;
		if (coor.e2 >= coor.dy)
		{
			err += coor.dy;
			x0 += coor.sx;
		}
		if (coor.e2 <= coor.dx)
		{
			err += coor.dx;
			y0 += coor.sy;
		}
	}
}

void	ft_drawline(t_matrix *mat, int i, int j, int direct, t_data *img, double color)
{
	t_point	p1;
	t_point	p2;

	p1.x = i;
	p1.y = j;
	p1.new_x = mat->matrix_points[i][j].new_x;
	p1.new_y = mat->matrix_points[i][j].new_y;
	if (direct == 1)
	{
		p2.x = i;
		p2.y = j + 1;
		p2.new_x = mat->matrix_points[i][j + 1].new_x;
		p2.new_y = mat->matrix_points[i][j + 1].new_y;
	}
	else
	{
		p2.x = i + 1;
		p2.y = j;
		p2.new_x = mat->matrix_points[i + 1][j].new_x;
		p2.new_y = mat->matrix_points[i + 1][j].new_y;
	}
	plot_line(p1.new_x, p1.new_y, p2.new_x, p2.new_y, img, color);
}
int	ft_abs(int a, int b)
{
	if (a - b < 0)
		return (b - a);
	else
		return (a - b);
}

int	ft_slope(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

void	ft_pixel(t_data *data, int x, int y, int color)
{
	my_mlx_pixel_put(data, x, y, color);
}

int	ft_color(t_point p1, t_point p2, t_point p)
{
	int		color;
	float	ratio;

	if (p2.new_x - p1.new_x == 0 && p2.new_y - p1.new_y == 0)
		ratio = 1.0;
	else if (p2.new_x - p1.new_x == 0)
		ratio = (float)(p.new_y - p1.new_y) / (p2.new_y - p1.new_y);
	else
		ratio = (float)(p.new_x - p1.new_x) / (p2.new_x - p1.new_x);
	color = (p2.color - p1.color) * ratio + p1.color;
	return (color);
}
void	ft_set_colors_sep(t_matrix *data, t_point *p1)
{
	p1->color = data->matrix_points[p1->x][p1->y].color;
	
}

void	ft_set_colors(t_matrix *data, t_point *p1, t_point *p2)
{
	ft_set_colors_sep(data, p1);
	ft_set_colors_sep(data, p2);
}

void	bresenhams(t_data *data, t_point p1, t_point p2, t_matrix *mat)
{
	t_point	p;
	int		err;
	int		e;

	p.new_x = p1.new_x;
	p.new_y = p1.new_y;
	err = ft_abs(p2.new_x, p1.new_x) - ft_abs(p2.new_y, p1.new_y);
	ft_set_colors(mat, &p1, &p2);
	while ((int)p.new_x != (int)p2.new_x || (int)p.new_y != (int)p2.new_y)
	{
		// printf("%lf and %lf \n",p.new_y, p2.new_y);
		ft_pixel(data, p.new_x, p.new_y, ft_color(p1, p2, p));
		e = 2 * err;
		if (e > -1 * ft_abs(p2.new_y, p1.new_y))
		{
			err -= ft_abs(p2.new_y, p1.new_y);
			p.new_x += ft_slope(p1.new_x, p2.new_x);
		}
		if (e < ft_abs(p2.new_x, p1.new_x))
		{
			err += ft_abs(p2.new_x, p1.new_x);
			p.new_y += ft_slope(p1.new_y, p2.new_y);
		}
	}
	ft_pixel(data, p.new_x, p.new_y, ft_color(p1, p2, p));
}

void	ft_draw_line(t_matrix *mat, int i, int j, int direct, t_data *data)
{
	t_point	p1;
	t_point	p2;

	p1.x = i;
	p1.y = j;
	p1.new_x = mat->matrix_points[i][j].new_x;
	p1.new_y = mat->matrix_points[i][j].new_y;
	if (direct == 1)
	{
		p2.x = i;
		p2.y = j + 1;
		p2.new_x = mat->matrix_points[i][j + 1].new_x;
		p2.new_y = mat->matrix_points[i][j + 1].new_y;
	}
	else
	{
		p2.x = i + 1;
		p2.y = j;
		p2.new_x = mat->matrix_points[i + 1][j].new_x;
		p2.new_y = mat->matrix_points[i + 1][j].new_y;
	}
	bresenhams(data, p1, p2, mat);
}

/*
	This algo uses Bresenham's algorithm
*/

