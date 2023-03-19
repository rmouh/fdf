/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:58:29 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/03/19 17:35:08 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}



void drawline(t_point *p1, t_point *p2, t_data img, double color, void	*mlx, void	*mlx_win)
{
	// double	dx;
	// double	p;
	// double	dy;
	// double	x;
	// double	y;

	// dx = p2->new_x - p1->new_x;
	// dy = p2->new_y - p1->new_y;
	// x = p1->new_x;
	// y = p1->new_y;
	// p = 2 * dy - dx;
	// while (x < p2->new_x)
	// {
	// 	if (p >= 0)
	// 	{
	// 		my_mlx_pixel_put(&img, x + 100, y + 200, color);
	// 		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// //putpixel(x,y,7);
	// 		y = y + 1;
	// 		p = p + 2 * dy - 2 * dx;
	// 	}
	// 	else
	// 	{
	// 		my_mlx_pixel_put(&img, x + 300, y + 800, color);
	// 		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// 		p = p + 2 * dy;
	// 	}
	// 	x = x + 1;
	// }
	
	int x0,y0, x1,y1;
	x0 = p1->new_x;
	y0 = p1->new_y;
	x1 = p2->new_x;
	y1 = p2->new_y;
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
  int err = dx + dy, e2; /* error value e_xy */
 
  for (;;){  /* loop */
   // setPixel (x0,y0);
	my_mlx_pixel_put(&img, x0, y0 , color);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}

void	draw_7(t_matrix *mat, int i, int j, t_data img, double color, void	*mlx, void	*mlx_win)
{
	//drawline(&mat->matrix_points[i][j], &mat->matrix_points[i][j + 1], img, color, mlx, mlx_win);
	drawline(&mat->matrix_points[i][j + 1], &mat->matrix_points[i + 1][j + 1], img, color, mlx, mlx_win);
}

int	main(void)
{
	int	size;
	void	*mlx;
	int		i;
	int		j;
	t_point	**tab;
	t_matrix	*mat;
	void	*mlx_win;
	t_data	img;

	i = 0;
	mat = creat_table("test_maps/elem-col.fdf", &size);
	//print_matr_double_z(mat);

	//print_matr_double_z(mat);
	the_formula(mat, 35.264, 45);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	// while (i < mat->height - 1)
	// {
	// 	j = 0;
	// 	while (j < mat->width - 1)
	// 	{
	// 		//my_mlx_pixel_put(&img, i + (1920 / 2), j + (1080 / 2) ,0x0FF0000);
	// 		//my_mlx_pixel_put(&img, (mat->matrix_points[i][j].new_x + 300) , (mat->matrix_points[i][j].new_y + 800),mat->matrix_points[i][j].color);
	// 		//printf("[%lf, %lf] ", mat->matrix_points[i][j].new_x + (1920 / 2), mat->matrix_points[i][j].new_y + (1080 / 2));
	// 		//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	my_mlx_pixel_put(&img, 200 , 40, 0x0FFFFFF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// my_mlx_pixel_put(&img, 0 , 0, 0x0FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 2, 2);
	// my_mlx_pixel_put(&img, 0 , 0, 0x0FFFFFF);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 2, 2);
	drawline(&mat->matrix_points[5][5], &mat->matrix_points[0][0],img, 0x0FF0000, mlx, mlx_win);
	//draw_7(mat, 2, 3, img ,  0x0FF0000, mlx, mlx_win);
	//print_matr_double_new_x_y(mat);
	//ft_printf("%d", ft_strcontain("200xFF0000", ","));
									
	mlx_loop(mlx);
	free_matrix(mat);
}