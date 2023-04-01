/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:58:29 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/04/01 14:50:51 by rmouhoub         ###   ########.fr       */
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
void set_translations(t_tran *t)
{
	t->x = WINDOW_WIDTH / 2;
	t->y = WINDOW_HEIGHT / 2;
}


// void drawL(int x1, int y1, int x2, int y2, t_data img, double color) 
// {
// 	int	dx;
// 	int	dy;
// 	int	p;
// 	int	x;
// 	int	y;
	
//     dx = x2 - x1;
//     dy = y2 - y1;
//     x = x1;
//     y = y1;
//     p = 2 * dy - dx;
	
//     while (x < x2) {
//         if (p >= 0) {
//             my_mlx_pixel_put(&img, x, y , color);
// 			//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//             y++;
//             p = p + 2 * dy - 2 * dx;
//         }
//         else {
			
// 			my_mlx_pixel_put(&img, x, y , color);
// 			//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
			
// 			p = p + 2 * dy;
//         }
//         x++;
//     }
// 	x = x1;
//     y = y1;
// 	p = 2 * dy - dx;
// 	while (y < y2)
// 	{
// 		if (p >= 0)
// 		{
// 			my_mlx_pixel_put(&img, x, y, color);
// 			y++;
// 			p = p + 2 * dy - 2 * dx;
// 		}
// 		else
// 		{
// 		   my_mlx_pixel_put(&img, x, y , color);
// 			p = p + 2 * dy;
// 		}
// 		y++;
// 	}
// }




void	draw_7(t_matrix *mat, int i, int j, t_data *img, double color)
{
	//drawL(i,j, i, j+1, img, 0x0FFFFFF);
	//drawL(i, j+1, i+1, j+1, img, 0x0FFFFFF);
	//drawL(120, 120, 145, 85, img, 0x0FFFFFF);
	//plot_line( 0, 0, p2.new_x, p2.new_y, img, color);
	ft_drawline(mat, i, j, 0, img, color);
	ft_drawline(mat, i, j, 1, img, color);
	// drawline(&mat->matrix_points[i][j], &mat->matrix_points[i][j + 1], img, color, t);
	// drawline(&mat->matrix_points[i][j + 1], &mat->matrix_points[i + 1][j + 1], img, color, t);
	// drawline(, &mat->matrix_points[i][j + 1], img, color, mlx, mlx_win);
	// drawline(&mat->matrix_points[i][j + 1], &mat->matrix_points[i + 1][j + 1], img, color, mlx, mlx_win);
}

int	main(void)
{
	int	size;
	t_tran	t;
	void	*mlx;
	int		i;
	int		j;
	t_point	**tab;
	t_matrix	*mat;
	void	*mlx_win;
	t_data	img;

	i = 0;
	mat = creat_table("test_maps/42.fdf", &size);
	//print_matr_double_z(mat);
	set_translations(&t);
	the_formula(mat, 35.264, 45, t);
	//find(mat, &t);
	//printf("{%d, %d}\n", t.x, t.y);
	//print_matr_double_new_x_y(mat);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	while (i < mat->height - 1)
	{
		j = 0;
		while (j < mat->width - 1)
		{
			//my_mlx_pixel_put(&img, i + (1920 / 2), j + (1080 / 2) ,0x0FF0000);
			//my_mlx_pixel_put(&img, ((int)(mat->matrix_points[i][j].new_x)) , (int)(mat->matrix_points[i][j].new_y),mat->matrix_points[i][j].color);
			//printf("[%lf, %lf] ", mat->matrix_points[i][j].new_x + (1920 / 2), mat->matrix_points[i][j].new_y + (1080 / 2));
			draw_7(mat, i, j, &img, 0x0FFFFFF);
			draw_7(mat, i, j, &img, 0x0FFFFFF);						
			//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
			j++;
		}
		printf("\n");
		i++;
	}
	my_mlx_pixel_put(&img, 200 , 40, 0x0FFFFFF);
	//drawline(&mat->matrix_points[1][1], &mat->matrix_points[6][1], img, 0x0FFFFFF, t);
	//drawL(981, 647, 981, 495, img, 0x0FFFFFF);
	
	 //drawL(0,0, 0, 200, img, 0x0FFFFFF);981.012880, 647.479023)
	 //drawL(0, 0, 500, 0, img, 0x0FFFFFF);
	printf("(%lf, %lf)\n",mat->matrix_points[9][6].new_x, mat->matrix_points[9][6].new_y);
	//ft_drawline(mat, 9, 6, 1, &img, 0x0FFFFFF);
	//printf("(%lf, %lf)\n",mat->matrix_points[6][1].new_x, mat->matrix_points[6][1].new_y);
	//print_matr_double_new_x_y(mat);
	// ft_printf("laaaaaa\n")r;
	// for (int i = 0; i  < 200 ; i++)
	// {
	// 	for (int j = 0; j < 400; j++)
	// 		my_mlx_pixel_put(&img, j, i, 0x6F95A6);
	// }
	// plot_line(0, 0, 1000, 800, &img, 0x6F95A6);
	//ft_drawline(mat, 5,10, 0, &img,  0x0FFFFFF);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);


	mlx_loop(mlx);
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