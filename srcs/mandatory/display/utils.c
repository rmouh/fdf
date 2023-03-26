/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:10:19 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/03/26 16:28:58 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int absolut (double nb)
{
	return (-((int)nb) + 1);
}

int min(double nb1, double nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

void find(t_matrix *mat, t_tran *tr)
{
	double	minx;
	double	miny;
	int		i;
	int		j;

	i = 0;
	minx = 0;
	miny = 0;
	while (i < mat->height)
	{
		j = 0;
		while (j < mat->width)
		{
			minx = min(minx, mat->matrix_points[i][j].new_x);
			miny = min(miny, mat->matrix_points[i][j].new_y);
			j++;
		}
		i++;
	}
	tr->x = absolut(minx);
	tr->y = absolut(miny);
}


void        plot_line(int x0, int y0, int x1, int y1, t_data *img, int color)
{
printf("(%d, %d, %d, %d)\n",x0,y0,x0,y0) ;

  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
  int err = dx + dy, e2; /* error value e_xy */
 
  for (;;){  /* loop */
    my_mlx_pixel_put(img, x0, y0,  color);    
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
	ft_printf("laaaaaa\n");
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
		p1.new_x = mat->matrix_points[i][j + 1].new_x;
		p1.new_y = mat->matrix_points[i][j + 1].new_y;
	}
	else
	{
		p2.x = i + 1;
		p2.y = j;
		p1.new_x = mat->matrix_points[i + 1][j].new_x;
		p1.new_y = mat->matrix_points[i + 1][j].new_y;
	}
	//ft_bresenhams(mat, p1, p2, img, color);
	plot_line(p1.new_x, p1.new_y, p2.new_x, p2.new_y, img, color);
	//plot_line(0, 0, 1000, 800, img, 0x6F95A6);

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


void	ft_bresenhams(t_matrix *mat, t_point p1, t_point p2, t_data *img, double color)
{
	t_point	p;
	int		err;
	int		e;

	p.new_x = p1.new_x;
	p.new_y = p1.new_y;
	err = ft_abs(p2.new_x, p1.new_x) - ft_abs(p2.new_y, p1.new_y);
	//ft_set_colors(data, &p1, &p2);
	while (p.new_x != p2.new_x || p.new_x != p2.new_x)
	{
		my_mlx_pixel_put(img, p.new_x, p.new_y, 0xf098876);
		e = 2 * err;
		if (e > -1 * ft_abs(p2.new_y, p1.new_y))
		{
			err -= ft_abs(p2.new_x, p1.new_y);
			p.new_x += ft_slope(p1.new_x, p2.new_x);
		}
		if (e < ft_abs(p2.new_x, p1.new_x))
		{
			err += ft_abs(p2.new_x, p1.new_x);
			p.new_y += ft_slope(p1.new_x, p2.new_y);
		}
	}
	my_mlx_pixel_put(img, p.new_x, p.new_y, color);
	for (int i = 0; i  < 200 ; i++)
	{
		my_mlx_pixel_put(img, 300, i, color);

	}

}

void	draw_vertical_line(int x, int y1, int y2, t_data img, double color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		my_mlx_pixel_put(&img, x, y, color);
		y++;
	}
}

void	draw_horizontal_line(int x1, int y, int x2, t_data img, double color)
{
	int	x;

	x = x1;
	while (x <= x2)
	{
		my_mlx_pixel_put(&img, x, y, color);
		x++;
	}
}

// void	drawline(t_point *p1, t_point *p2, t_data img, double color, t_tran t)
// {
// 	int	dx;
// 	int	dy;
// 	int	p;
// 	int	x;
// 	int	y;

// 	dx = (int)(p2->new_x - p1->new_x);
// 	dy = (int)(p2->new_y - p1->new_y);
// 	x = (int)(p1->new_x);
// 	y = (int)(p1->new_y);
// 	p = 2 * dy - dx;
// 	if (dx == 0)
// 	{
// 		draw_vertical_line(p1->new_x, p1->new_y, p2->new_y, img, color);
// 		return ;
// 	}
// 	if (dy == 0)
// 	{
// 		draw_horizontal_line(p1->new_x, p1->new_y, p2->new_x, img, color);
// 		return ;
// 	}
// 	while (x < (int)(p2->new_x))
// 	{
// 		if (p >= 0)
// 		{
// 			my_mlx_pixel_put(&img, x, y, color);
// 			y++;
// 			p = p + 2 * dy - 2 * dx;
// 		}
// 		else
// 		{
// 			my_mlx_pixel_put(&img, x, y, color);
// 			p = p + 2 * dy;
// 		}
// 		x++;
// 	}
// }
// void drawLine(t_point *p1, t_point *p2, t_data img, double color, t_tran t)
// {
// 	int	dx;
// 	int	dy;
// 	int	p;
// 	int	x;
// 	int	y;

// 	dx = (int)(p2->new_x - p1->new_x)+ t.x;
//     //dx = x2 - x1;
//     //dy = y2 - y1;
// 	dy = (int)(p2->new_y - p1->new_y)+ t.y;
//     //x = x1;
// 	x = (int)(p1->new_x) + t.x;
//     //y = y1;
// 	y = (int)(p1->new_y) + t.y;
//     p = 2 * dy - dx;
	
//     while (x < (int)(p2->new_x) + t.x) {
// 		//printf("(%d, %d)\n",x, y);
//         if (p >= 0) {
// 			my_mlx_pixel_put(&img, x, y , color);
// 			//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//            // putpixel(x, y, WHITE);
//             y++;
//             p = p + 2 * dy - 2 * dx;
//         }
//         else {
//             //putpixel(x, y, WHITE);
//            my_mlx_pixel_put(&img, x, y , color);
// 			//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 			p = p + 2 * dy;
//         }
//         x++;
//     }
// }