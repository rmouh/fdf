/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:58:29 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/04/08 18:10:02 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_translations(t_tran *t)
{
	t->x = WINDOW_WIDTH / 2;
	t->y = WINDOW_HEIGHT / 2;
}

void	draw_7(t_matrix *mat, int i, int j, t_data *img, double color)
{
	// ft_drawline(mat, i, j, 0, img, color);
	// ft_drawline(mat, i, j, 1, img, color);
	ft_draw_line(mat,  i,  j,  0,  img);
	ft_draw_line(mat,  i,  j,  1, img);
}

int	main(void)
{
	int	size;
	t_tran	t;
	// void	*mlx;
	int		i;
	int		j;
	t_point	**tab;
	t_matrix	*mat;
	// void	*mlx_win;
	t_data	img;

	i = 0;
	mat = creat_table("test_maps/42.fdf", &size);
	set_translations(&t);
	the_formula(mat, 20, 50, t);

	mat->mlx = mlx_init();
	mat->mlx_win = mlx_new_window(mat->mlx, 1920, 1080, "Hello world!");
	mlx_hook(mat->mlx_win, 17, 0, &free_close, mat);
	mat->img = mlx_new_image(mat->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(mat->img, &img.bpp, &img.len, &img.endian);
	//print_matr_double_z( mat);
	//mat->matrix_points[mat->height -1][0].new_x, mat->matrix_points[mat->height -1][0].new_y,
	plot_line(mat->matrix_points[mat->height -1][0].new_x, mat->matrix_points[mat->height -1][0].new_y, mat->matrix_points[mat->height -1][mat->width-1].new_x, mat->matrix_points[mat->height-1][mat->width-1].new_y, &img, 0x0FFFFFF);
	plot_line(mat->matrix_points[0][mat->width-1].new_x, mat->matrix_points[0][mat->width-1].new_y, mat->matrix_points[mat->height -1][mat->width-1].new_x, mat->matrix_points[mat->height-1][mat->width-1].new_y, &img, 0x0FFFFFF);
	//plot_line(mat->matrix_points[0][0].new_x, mat->matrix_points[0][0].new_y, 50, 2, &img, 0x0FFFFFF);
	
	while (i < mat->height - 1)
			{
			j = 0;
			while (j < mat->width - 1)
			{
				draw_7(mat, i, j, &img, mat->matrix_points[i][j].color);
			//draw_7(mat, i, j, &img, 0x0FFFFFF);						
			j++;
		}
		printf("\n");
		i++;
	}
	my_mlx_pixel_put(&img, 200 , 40, 0x0FFFFFF);
	//printf("(%lf, %lf)\n",mat->matrix_points[9][6].new_x, mat->matrix_points[9][6].new_y);
	mlx_put_image_to_window(mat->mlx, mat->mlx_win, mat->img, 0, 0);
	mlx_loop(mat->mlx);
	free_matrix(mat);
}



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