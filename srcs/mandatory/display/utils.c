/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:10:19 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/05/26 18:00:08 by rmouhoub         ###   ########.fr       */
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

void	plot_line(t_point p0, t_point p1, t_data *img, int color)
{
	t_coor	coor;
	int		err;
	int		res;

	coor.dx = abs (p1.x - p0.x);
	coor.sx = min_and_val(p0.x, p1.x);
	coor.dy = -abs (p1.y - p0.y);
	coor.sy = min_and_val(p0.y, p1.y);
	err = coor.dx + coor.dy;
	while (1)
	{
		my_mlx_pixel_put(img, p0.x, p0.y, color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		coor.e2 = 2 * err;
		if (coor.e2 >= coor.dy)
		{
			err += coor.dy;
			p0.x += coor.sx;
		}
		if (coor.e2 <= coor.dx)
		{
			err += coor.dx;
			p0.y += coor.sy;
		}
	}
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

void	bresenhams(t_point p1, t_point p2, t_matrix *mat)
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
		ft_pixel(&(mat->imgg), p.new_x, p.new_y, ft_color(p1, p2, p));
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
	ft_pixel(&(mat->imgg), p.new_x, p.new_y, ft_color(p1, p2, p));
}

void	ft_draw_line_vertical(t_matrix *mat, int i, int j, t_trans p)
{
	t_point	p1;
	t_point	p2;

	p1.x = i;
	p1.y = j;
	p1.new_x = mat->matrix_points[i][j].new_x + 1920 / 2 - p.tr_x;
	p1.new_y = mat->matrix_points[i][j].new_y + 1080 / 2 - p.tr_y;
	p2.x = i + 1;
	p2.y = j;
	p2.new_x = mat->matrix_points[i + 1][j].new_x + 1920 / 2 - p.tr_x;
	p2.new_y = mat->matrix_points[i + 1][j].new_y + 1080 / 2 - p.tr_y;

	bresenhams(p1, p2, mat);
}

void	ft_draw_line_horizental(t_matrix *mat, int i, int j, t_trans p)//1
{
	t_point	p1;
	t_point	p2;

	p1.x = i;
	p1.y = j;
	p1.new_x = mat->matrix_points[i][j].new_x +1920 / 2 - p.tr_x;
	p1.new_y = mat->matrix_points[i][j].new_y +1080/2 - p.tr_y;
	p2.x = i;
	p2.y = j + 1;
	p2.new_x = mat->matrix_points[i][j + 1].new_x + 1920 / 2 - p.tr_x;
	p2.new_y = mat->matrix_points[i][j + 1].new_y + 1080 / 2 -  p.tr_y;

	bresenhams(p1, p2, mat);
}


/*
	This algo uses Bresenham's algorithm
*/

