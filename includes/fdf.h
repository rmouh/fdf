/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:53:34 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/04/01 17:36:59 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx/mlx.h"
# include<stdio.h> 
# include <fcntl.h>
# include <math.h> 
# include "libft.h"
# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 1080
# endif
# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1920
# endif

typedef struct s_data {
	// void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}				t_data;

typedef struct s_point {
	int		x;
	int		y;
	int		z;
	double	color;
	double	new_x;
	double	new_y;
}				t_point;

typedef struct s_camera{
	double	alpha;
	double	beta;
}				t_camera;

typedef struct s_translation{
	int	x;
	int	y;
}				t_tran;

typedef struct s_matrix{
	t_point	**matrix_points;
	int		width;
	int		height;
	void	*mlx;
	void	*mlx_win;
	void	*img;
}				t_matrix;

typedef struct s_tab{
	double	**tab;
	int		height;
	int		width;
}				t_tab;

typedef struct s_coor
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	e2;	
}	t_coor;

/*

		parsing fonctions

*/
void		free_line(char **tab);
void		free_tab_int(t_tab *tab);
void		free_list(t_list **chaine);
void		free_matrix(t_matrix *mat);
t_list		*read_map(char *file, int *nb);
void		get_cords_colors(int line_size, t_point **tab, char **line, int i);
int			put_in_tab(int nb, int size_all, t_point **tab, t_list *track);
t_matrix	*creat_table(char *file, int *size);
void		print_tab_int(int hi, int wi, int **tab);
void		print_matr_double_z(t_matrix *mat);
void		print_matr_double_new_x_y(t_matrix *mat);
void		print_tab_double(int hi, int wi, double **tab);
void		free_close(t_matrix *mat);

/*
		hexa conversion
*/

double		ft_atoi_base(char *str, int base);
double		conversion(char *p, int sign, int base);
int			is_upper(char c);

/*

		mapping fonctions

*/

void		initialise_p(t_point *p);
// int		malloc_matric_n(int n, int p, int **res);
t_tab		*malloc_matric_n(int n, int p, t_tab *res);
t_tab		*multiplicate(double **tab1, double **tab2, int n, int q, int m);
t_camera	*initialize_cam(double alpha, double beta);

		/* multiplications */

t_tab		*first_mult(t_camera *cam, t_tab*tab1, t_tab *tab2);
t_tab		*second_mult(double **tab, t_point *point);
void		third_mult(t_point *point, t_tab *vect, t_tran t);
int			the_formula(t_matrix *matrix, double alpha, double beta, t_tran tr);
t_tab		*multiplicate(double **tab1, double **tab2, int n, int q, int m);



/*			
			display
							*/
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			absolut (double nb);
void		draw_7(t_matrix *mat, int i, int j, t_data *img, double color);
int			min(double nb1, double nb2);
void		find(t_matrix *mat, t_tran *tr);
void	ft_drawline(t_matrix *mat, int i, int j, int direct, t_data *img, double color);
void		draw_vertical_line(int x, int y1, int y2, t_data img, double color);
void		draw_horizontal_line(int x1, int y, int x2, t_data img, double color);
void		set_translations(t_tran *t);
void	ft_bresenhams(t_matrix *mat, t_point p1, t_point p2, t_data *img, double color);
void        plot_line(int x0, int y0, int x1, int y1, t_data *img, int color);

#endif

/*

t_point	**my = (t_point **)malloc (sizeof(t_point *) * num);

i = 0;
while (i < num)
{
	my[i] = (t_point *)malloc (sizeof(t_point) * width);
}

*/