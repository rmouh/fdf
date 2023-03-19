/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:53:34 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/03/19 12:39:12 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx/mlx.h"
# include<stdio.h> 
# include <fcntl.h>
# include <math.h> 
# include "libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
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

typedef struct s_matrix{
	t_point	**matrix_points;
	int		width;
	int		height;
}				t_matrix;

typedef struct s_tab{
	double	**tab;
	int		height;
	int		width;
}				t_tab;

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
void		third_mult(t_point *point, t_tab *vect);
int			the_formula(t_matrix *matrix, double alpha, double beta);
t_tab		*multiplicate(double **tab1, double **tab2, int n, int q, int m);


#endif

/*

t_point	**my = (t_point **)malloc (sizeof(t_point *) * num);

i = 0;
while (i < num)
{
	my[i] = (t_point *)malloc (sizeof(t_point) * width);
}

*/