void	ft_bresenhams(t_matrix *mat, t_point p1, t_point p2, t_data *img, double color)
{
	t_point	p;
	int		err;
	int		e;

	p.new_x = p1.new_x;
	p.new_y = p1.new_y;
	err = ft_abs(p2.new_x, p1.new_x) - ft_abs(p2.new_y, p1.new_y);
	while (p.new_x != p2.new_x || p.new_x != p2.new_x){
		my_mlx_pixel_put(img, p.new_x, p.new_y, 0xf098876);
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
	my_mlx_pixel_put(img, p.new_x, p.new_y, color);
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
// int	ft_abs(int a, int b)
// {
// 	if (a - b < 0)
// 		return (b - a);
// 	else
// 		return (a - b);
// }

// int	ft_slope(int a, int b)
// {
// 	if (a < b)
// 		return (1);
// 	else
// 		return (-1);
// }

// int absolut (double nb)
// {
// 	return (-((int)nb) + 1);
// }

// int min(double nb1, double nb2)
// {
// 	if (nb1 < nb2)
// 		return (nb1);
// 	return (nb2);
// }

// void find(t_matrix *mat, t_tran *tr)
// {
// 	double	minx;
// 	double	miny;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	minx = 0;
// 	miny = 0;
// 	while (i < mat->height)
// 	{
// 		j = 0;
// 		while (j < mat->width)
// 		{
// 			minx = min(minx, mat->matrix_points[i][j].new_x);
// 			miny = min(miny, mat->matrix_points[i][j].new_y);
// 			j++;
// 		}
// 		i++;
// 	}
// 	tr->x = absolut(minx);
// 	tr->y = absolut(miny);
// }


void	drawL(int x1, int y1, int x2, int y2, t_data img, double color)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;
	
	dx = x2 - x1;
	dy = y2 - y1;
	x = x1;
	y = y1;
	p = 2 * dy - dx;
	
	if (dx == 0) {
		printf("hrerer");
		draw_vertical_line(x1, y1, y2, img, color);
		return;
	}
	 if (dy == 0)
	 {
        draw_horizontal_line(x1, y1, x2, img, color);
        return;
		}
	
	while (x < x2) {
		if (p >= 0) {
			my_mlx_pixel_put(&img, x, y , color);
			y++;
			p = p + 2 * dy - 2 * dx;
		}
		else {
			my_mlx_pixel_put(&img, x, y , color);
			p = p + 2 * dy;
		}
		x++;
	}
}



void	plot_line(t_point *p1, t_point *p2, t_data *img, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;

	dx = abs (p2->new_x - p1->new_x);
	//sx = min_and_val(p1->new_x, p2->new_x);
	dy = -abs (p2->new_y - p1->new_y);
	//sy = min_and_val(p1->new_y, p2->new_y);
	err = dx + dy;
	while (1)
	{
		my_mlx_pixel_put(img, p1->new_x, p1->new_y, color);
		auxl(p1, p2, dx, dy)
		// if (p1->new_x == p2->new_x && p1->new_y == p2->new_y)
		// 	break ;
		// e2 = 2 * err;
		// if ((e2) >= dy)
		// {
		// 	err += dy;
		// p1->new_x += sx;
		// }
		// if ((e2) <= dx)
		// {
		// 	err += dx;
		// p1->new_y += sy;
		// }
	}
}

void auxl(t_point *p1, t_point *p2, int dx, int dy)
{
	int	e2;
	int	sx;
	int	sy;
	int	err;

	sx = min_and_val(p1->new_x, p2->new_x);
	sy = min_and_val(p1->new_y, p2->new_y);-
	err = dx + dy;
	e2 = 2 * err;
	if ((e2) >= dy)
	{
		err += dy;
		p1->new_x += sx;
	}
	if ((e2) <= dx)
	{
		err += dx;
		p1->new_y += sy;
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:10:19 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/04/01 15:42:44 by rmouhoub         ###   ########.fr       */
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


int min_and_val(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (1);
	return (-1);
}

int	ft_abs(double a)
{
	if (a  < 0)
		return (-a);
	else
		return (a);
}

// void	plot_line(intp1.new_x, intp1.new_y, intp2.new_x, int p2.new_y, t_data *img, int color)
// {
// //printf("(%d, %d, %d, %d)\n"p1.new_xp1.new_yp1.new_xp1.new_y) ;

//   int dx =  abs p2.new_x -p1.new_x), sx =p1.new_x <p2.new_x ? 1 : -1;
//   int dy = -abs (p2.new_y -p1.new_y), sy =p1.new_y < p2.new_y ? 1 : -1; 
//   int err = dx + dy, e2; /* error value e_xy */
 
//   for (;;){  /* loop */
//     my_mlx_pixel_put(img,p1.new_x,p1.new_y,  color);    
//     if p1.new_x ==p2.new_x &&p1.new_y == p2.new_y) break;
//     e2 = 2 * err;
//     if (e2 >= dy) { err += dy;p1.new_x += sx; } /* e_xy+e_x > 0 */
//     if (e2 <= dx) { err += dx;p1.new_y += sy; } /* e_xy+e_y < 0 */
//   }
// 	//ft_printf("laaaaaa\n");
// }plot_line(p1.new_x, p1.new_y, p2.new_x, p2.new_y, img, color)

void	plot_line(t_point *p1, t_point *p2, t_data *img, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	e2;
	int err;

	dx = ft_abs(p2->new_x - p1->new_x);
	sx = min_and_val(p1->new_x, p2->new_x);
	dy = -ft_abs(p2->new_y - p1->new_y);
	sy = min_and_val(p1->new_y, p2->new_y);
	err = dx + dy;
	while (1)
	{
		my_mlx_pixel_put(img, p1->new_x,p1->new_y, color);
		if (p1->new_x == p2->new_x &&p1->new_y == p2->new_y)
			break ;
		e2 = 2 * err;
		if ((e2) >= dy)
		{
			err += dy;
		p1->new_x += sx;
		}
		if ((e2) <= dx)
		{
			err += dx;
		p1->new_y += sy;
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
//ft_bresenhams(mat, p1, p2, img, color);
	plot_line(&p1, &p2, img, color);
	//plot_line(0, 0, 1000, 800, img, 0x6F95A6);

}



// int	main(void)
// {
// 	void	*mlx;

// 	mlx = mlx_init();
// }
// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);
//





// void	plot_line(int x0, int y0, int x1, int y1, t_data *img, int color)
// {
// //printf("(%d, %d, %d, %d)\n",x0,y0,x0,y0) ;

//   int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
//   int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
//   int err = dx + dy, e2; /* error value e_xy */
 
//   for (;;){  /* loop */
//     my_mlx_pixel_put(img, x0, y0,  color);    
//     if (x0 == x1 && y0 == y1) break;
//     e2 = 2 * err;
//     if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
//     if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
//   }
// 	//ft_printf("laaaaaa\n");
// }

 //void drawline(t_point *p1, t_point *p2, t_data img, double color, void	*mlx, void	*mlx_win)
// {
// 	// double	dx;
// 	// double	p;
// 	// double	dy;
// 	// double	x;
// 	// double	y;

// 	// dx = p2->new_x - p1->new_x;
// 	// dy = p2->new_y - p1->new_y;
// 	// x = p1->new_x;
// 	// y = p1->new_y;
// 	// p = 2 * dy - dx;
// 	// while (x < p2->new_x)
// 	// {
// 	// 	if (p >= 0)
// 	// 	{
// 	// 		my_mlx_pixel_put(&img, x + 100, y + 200, color);
// 	// 		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	// //putpixel(x,y,7);
// 	// 		y = y + 1;
// 	// 		p = p + 2 * dy - 2 * dx;
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		my_mlx_pixel_put(&img, x + 300, y + 800, color);
// 	// 		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	// 		p = p + 2 * dy;
// 	// 	}
// 	// 	x = x + 1;
// 	// }
	
// 	int x0,y0, x1,y1;
// 	x0 = p1->new_x;
// 	y0 = p1->new_y;
// 	x1 = p2->new_x;
// 	y1 = p2->new_y;
//   int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
//   int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
//   int err = dx + dy, e2; /* error value e_xy */
 
//   for (;;){  /* loop */
//    // setPixel (x0,y0);
// 	my_mlx_pixel_put(&img, x0, y0 , color);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//     if (x0 == x1 && y0 == y1) break;
//     e2 = 2 * err;
//     if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
//     if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
//   }
// }





// int	the_formula(t_matrix *matrix, double alpha, double beta, t_tran tr)
// {
// 	t_tab		*res;
// 	int			i;
// 	int			j;
// 	t_tab		*tab1;
// 	t_tab		*tab2;
// 	t_tab 		*t;
// 	t_point		*p;
// 	t_camera	*cam;

// 	i = 0;
// 	tab1 = NULL;
// 	tab2 = NULL;
// 	cam = initialize_cam(alpha, beta);
// 	res = first_mult(cam, tab1, tab2);
// 	free(cam);
// 	if (!res)
// 		return (free(cam), -1);
// 	printf(" hi %d  w %d\n", matrix->height, matrix->width);
// 	while (i < matrix->height)
// 	{
// 		j = 0;
// 		while (j < matrix->width)
// 		{
// 			p = &(matrix->matrix_points[i][j]);
// 			t = second_mult(res->tab, p);
// 			third_mult(p, t, tr);
// 			j++;
// 		}
// 		i++;
// 	}
// 	free_tab_int(res);
// 	return (1);
// }