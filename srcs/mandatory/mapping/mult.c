/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:26:59 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/03/19 11:12:54 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void	initialise_p(t_point *p)
{
	p->x = 0;
	p->y = 0;
	p->z = 0;
}
/*
	n : is the hight of matrix 
	p : is the width of matrix
	 1 2 3 4
	 0 2 1 6 
	  n == 2
	  p == 4
*/

t_tab	*malloc_matric_n(int n, int p, t_tab *res)
{
	int	i;

	i = 0;
	res = malloc (sizeof(t_tab));
	if (!res)
		return (NULL);
	res->tab = malloc(sizeof(double *) * n);
	if (!(res->tab))
		return (free(res), NULL);
	res->height = n;
	res->width = p;
	while (i < n)
	{
		res->tab[i] = calloc(sizeof(double), p);
		if (!res->tab[i])
			return (free_tab_int(res), NULL);
		i++;
	}
	return (res);
}

int	the_formula(t_matrix *matrix, double alpha, double beta)
{
	t_tab		*res;
	int			i;
	int			j;
	t_tab		*tab1;
	t_tab		*tab2;
	t_point		*p;
	t_camera	*cam;

	i = 0;
	tab1 = NULL;
	tab2 = NULL;
	cam = initialize_cam(alpha, beta);
	res = first_mult(cam, tab1, tab2);
	//print_tab_double(res->height, res->width, res->tab);
	if (!res)
		return (free(cam), -1);
	printf(" hi %d  w %d\n", matrix->height, matrix->width);
	//print_tab_int(matrix->height, matrix->width, matrix->matrix_points);
	// while (i < matrix->height)
	// {
	// 	j = 0;
	// 	while (j < matrix->width)
	// 	{
	// 		*p = (matrix->matrix_points[i][j]);
	// 		third_mult(p, second_mult(res->tab, p));
	// 		j++;
	// 	}
	// 	i++;
	// }
	return (1);
}

// void	multiplicate(t_point *p1, t_point *p2)

/*
	n : is the hight of matrix tab1
	q : is the width of matrix tab2
	m : is the width of matrix tab1
	
*/

t_tab	*multiplicate(double **tab1, double **tab2, int n, int q, int m)
{
	int		i;
	int		j;
	int		k;
	t_tab	*res;

	i = 0;
	res = NULL;
	res = malloc_matric_n(3, 3, res);
	while (i < n)
	{
		j = 0;
		while (j < q)
		{
			k = 0;
			while (k < m)
			{
				res->tab[i][j] += tab1[i][k] * tab2[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (res);
}

// int	main(void)
// {
// 	t_camera 	*cam;
// 	// int	**tab=NULL;
// 	// int	**tab1=NULL;
// 	// int	**tab2=NULL;

	
// 	// int A[3][3] = [[1, 2, 5], [3, 4, 2], [5, 6, 0]];
//     // int B[3][3] = [[1, 2, 3], [5, 6, 7], [0, 0, 0]];
// 	// tab1 = malloc_matric_n(3,3, tab1);
// 	// tab2 = malloc_matric_n(3,3, tab2);
	
// 	// tab1[0][0] = 2;
// 	// tab1[0][1] = 6;
// 	// tab1[0][2] = 8;
// 	// tab1[1][0] = 4;
// 	// tab1[1][1] = 55;
// 	// tab1[1][2] = 5;
// 	// tab1[2][0] = 0;
// 	// tab1[2][1] = 2;
// 	// tab1[2][2] = 1;
// 	// print_tab(3, 3, tab1);

	
// 	// tab2[0][0] = 1;
// 	// tab2[0][1] = 0;
// 	// // tab2[0][2] = 5;
// 	// tab2[1][0] = -8;
// 	// tab2[1][1] = 6;
// 	// // tab2[1][2] = 3;
// 	// tab2[2][0] = 4;
// 	// tab2[2][1] = 2;
// 	// // tab2[2][2] = 1;

// 	// print_tab(3, 3, tab2);

// 	// tab = multiplicate(tab1, tab2, 3, 2, 3);
// 	// ft_printf("res\n");
// 	// print_tab(3, 2, tab);

// 	printf("%lf  %lf\n", cam->alpha, cam->beta);
// }