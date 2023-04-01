/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:10:19 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/04/01 17:38:31 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return ;
	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}


int min_and_val(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (1);
	return (-1);
}

void	plot_line(int x0, int y0, int x1, int y1, t_data *img, int color)
{
	t_coor	coor;
	int		err;

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
		if (coor.e2>= coor.dy)
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
