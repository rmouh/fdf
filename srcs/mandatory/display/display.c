/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:58:29 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/05/26 17:58:42 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_7(t_matrix *mat, int i, int j, t_trans p)
{
	ft_draw_line_vertical(mat, i, j, p);
	ft_draw_line_horizental(mat, i, j, p);
}

t_trans	translate(t_point	**mat, int height, int width)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	t_trans	p;

	x1 = mat[0][0].new_x;
	y1 = mat[0][0].new_y;
	x2 = mat[height - 1][width - 1].new_x;
	y2 = mat[height - 1][width - 1].new_y;
	p.tr_x = (x1 + x2) / 2;
	p.tr_y = (y1 + y2) / 2;
	printf("%f   %f\n", p.tr_x, p.tr_y);
	return (p);
}

int	main(void)
{
	int	size;
	t_tran	t;
	int		i;
	int		j;
	t_point	p1;
	t_point	p0;
	t_point	**tab;
	t_matrix	*mat;
	t_trans	p;

	i = 0;
	mat = creat_table("test_maps/10-2.fdf", &size);
	the_formula(mat, 20, 50, t);
	p = translate(mat->matrix_points, mat->height, mat->width);
	printf("%f   %f\n", p.tr_x, p.tr_y);
	mat->mlx = mlx_init();
	mat->mlx_win = mlx_new_window(mat->mlx, 2000, 1200, "Hello world!");
	mlx_hook(mat->mlx_win, 17, 0, &free_close, mat);
	mat->imgg.img = mlx_new_image(mat->mlx, 2000, 1200);
	mat->imgg.addr = mlx_get_data_addr(mat->imgg.img, &(mat->imgg).bpp, &(mat->imgg).len, &(mat->imgg).endian);
	p0.x = mat->matrix_points[mat->height -1][0].new_x + 1920 / 2 - p.tr_x;
	p0.y = mat->matrix_points[mat->height -1][0].new_y + 1080 / 2 - p.tr_y;
	p1.x =  mat->matrix_points[mat->height -1][mat->width-1].new_x+ 1920 / 2 - p.tr_x;
	p1.y =  mat->matrix_points[mat->height-1][mat->width-1].new_y + 1080 / 2 - p.tr_y;
	plot_line(p0, p1, &(mat->imgg), 0x0FFFFFF);
	p0.x = mat->matrix_points[0][mat->width-1].new_x + 1920 / 2 - p.tr_x;
	p0.y = mat->matrix_points[0][mat->width-1].new_y + 1080 / 2 - p.tr_y;
	p1.x =  mat->matrix_points[mat->height -1][mat->width-1].new_x + 1920 / 2 - p.tr_x;
	p1.y =  mat->matrix_points[mat->height-1][mat->width-1].new_y + 1080 / 2 - p.tr_y;
	plot_line(p0, p1, &(mat->imgg), 0x0FFFFFF);
	while (i < mat->height - 1)
	{
		j = 0;
		while (j < mat->width - 1)
		{
			draw_7(mat, i, j, p);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mat->mlx, mat->mlx_win, mat->imgg.img, 0, 0);
	mlx_loop(mat->mlx);
	free_matrix(mat);
}
