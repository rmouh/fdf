/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:26:59 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/05/24 19:05:52 by rmouhoub         ###   ########.fr       */
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

// int	the_formula(t_matrix *matrix, double alpha, double beta, t_tran tr)
// {
// 	t_tab		*res;
// 	int			i;
// 	int			j;
// 	t_form		x;

// 	i = 0;
// 	x.tab1 = NULL;
// 	x.tab2 = NULL;
// 	x.cam = initialize_cam(alpha, beta);
// 	res = first_mult(x.cam, x.tab1, x.tab2);
// 	free(x.cam);
// 	if (!res)
// 		return (free(x.cam), -1);
// 	// 	aux(matrix, res, &x, tr);
// 	while (i < matrix->height)
// 	{
// 		j = 0;
// 		while (j < matrix->width)
// 		{
// 			x.p = &(matrix->matrix_points[i][j]);
// 			x.t = second_mult(res->tab, x.p);
// 			third_mult(x.p, x.t, tr);
// 			j++;
// 		}
// 		i++;
// 	}
// 	free_tab_int(res);
// 	return (1);
// }


void	aux(t_matrix *matrix, t_tab *res, t_form	*x, t_tran tr)
{
	int			i;
	int			j;

	i = 0;
	while (i < matrix->height)
	{
		j = 0;
		while (j < matrix->width)
		{
			x->p = &(matrix->matrix_points[i][j]);
			x->t = second_mult(res->tab, x->p);
			third_mult(x->p, x->t, tr);
			j++;
		}
		i++;
	}
}

int	the_formula(t_matrix *matrix, double alpha, double beta, t_tran tr)
{
	t_tab		*res;
	int			i;
	int			j;
	t_form		x;

	x.tab1 = NULL;
	x.tab2 = NULL;
	x.p = NULL;
	x.t = NULL;
	x.cam = initialize_cam(alpha, beta);
	res = first_mult(x.cam, x.tab1, x.tab2);
	free(x.cam);
	if (!res)
		return (free(x.cam), -1);
	aux(matrix, res, &x, tr);
	free_tab_int(res);
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
