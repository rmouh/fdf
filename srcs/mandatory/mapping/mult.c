/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:26:59 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/03/17 20:31:05 by rmouhoub         ###   ########.fr       */
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

int	**malloc_matric_n(int n, int p, int **res)
{
	int	i;

	i = 0;
	res = malloc(sizeof(int *) * n);
	if (!res)
		return (free(res), NULL);
	while (i < n)
	{
		res[i] = calloc(sizeof(int), p);
		if (!res[i])
			return (free_tab_int(res), NULL);
		i++;
	}
	return (res);
}

// void	multiplicate(t_point *p1, t_point *p2)

/*
	n : is the hight of matrix tab1
	q : is the width of matrix tab2
	m : is the width of matrix tab1
	
*/

int	**first_mult(t_camera cam, int	**tab1, int	**tab2)
{
	int	**res;

	tab1 = malloc_matric_n(3, 3, tab1);
	tab2 = malloc_matric_n(3, 3, tab2);
	tab1[0][0] = 1;
	tab1[1][1] = cos(cam.alpha);
	tab1[1][2] = sin(cam.alpha);
	tab1[2][1] = -sin(cam.alpha);
	tab1[2][2] = cos(cam.alpha);
	tab2[0][0] = cos(cam.beta);
	tab2[0][2] = -sin(cam.beta);
	tab2[1][1] = 1;
	tab2[2][0] = sin(cam.beta);
	tab2[2][2] = coss(cam.beta);
	res = multiplicate(tab1, tab1, 3, 3, 3);
	return (res);
}

int	**multiplicate(int **tab1, int **tab2, int n, int q, int m)
{
	int	i;
	int	j;
	int	k;
	int	**res;

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
				res[i][j] += tab1[i][k] * tab2[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (res);
}

int	main(void)
{
	int	**tab=NULL;
	int	**tab1=NULL;
	int	**tab2=NULL;

	
	// int A[3][3] = [[1, 2, 5], [3, 4, 2], [5, 6, 0]];
    // int B[3][3] = [[1, 2, 3], [5, 6, 7], [0, 0, 0]];
	tab1 = malloc_matric_n(3,3, tab1);
	tab2 = malloc_matric_n(3,3, tab2);
	
	tab1[0][0] = 2;
	tab1[0][1] = 6;
	tab1[0][2] = 8;
	tab1[1][0] = 4;
	tab1[1][1] = 55;
	tab1[1][2] = 5;
	tab1[2][0] = 0;
	tab1[2][1] = 2;
	tab1[2][2] = 1;
	print_tab(3, 3, tab1);

	
	tab2[0][0] = 1;
	tab2[0][1] = 0;
	// tab2[0][2] = 5;
	tab2[1][0] = -8;
	tab2[1][1] = 6;
	// tab2[1][2] = 3;
	tab2[2][0] = 4;
	tab2[2][1] = 2;
	// tab2[2][2] = 1;

	print_tab(3, 3, tab2);

	tab = multiplicate(tab1, tab2, 3, 2, 3);
	ft_printf("res\n");
	print_tab(3, 2, tab);

}