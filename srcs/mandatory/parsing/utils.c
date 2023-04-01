/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:25:20 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/04/01 18:16:40 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab_int(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->height)
		free(tab->tab[i++]);
	free(tab->tab);
	free(tab);
}

void	free_line(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}


void	free_list(t_list **lst)
{
	t_list	*track;
	t_list	*nextt;

	track = *lst;
	*lst = NULL;
	while (track != NULL)
	{
		nextt = track->next;
		free(track->content);
		free(track);
		track = nextt;
	}
}

void	free_matrix(t_matrix *mat)
{
	int			i;

	i = 0;
	while (i < mat->height)
		free(mat->matrix_points[i++]);
	free(mat->matrix_points);
	free(mat);
}

void	get_cords_colors(int line_size, t_point **tab, char **line, int i)
{
	t_point	*point;
	int count =0;
	int		j;

	j = 0;
	while (line_size-- > 0)
	{
		point = &tab[i][j];
		(*point).z = ft_atoi(line[j]);
		(*point).x = j * 40;
		(*point).y = i * 40;
		if (ft_strcontain(line[j], ","))
		{
			printf("heree");
			(*point).color = ft_atoi_base(line[j], 16);
			count++;
		}
		else
			(*point).color =(*point).x *(*point).y;
		printf("%lf [%d]\n", (*point).color, count);
		j++;
	}
}

void	print_tab_int(int hi, int wi, int **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < hi)
	{
		j = 0;
		while (j < wi)
		{
			ft_printf ("tab[%d][%d] = %d        ", i, j, tab[i][j]);
			j++;
		}
		i++;
		ft_printf("\n");
	}
}

void	print_tab_double(int hi, int wi, double **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < hi)
	{
		j = 0;
		while (j < wi)
		{
			printf ("tab[%d][%d] = %lf        ", i, j, tab[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	print_matr_double_z(t_matrix *mat)
{
	int	i;
	int	j;

	i = 0;
	while (i < mat->height)
	{
		j = 0;
		while (j < mat->width)
		{
			printf ("%d  ", mat->matrix_points[i][j].z);
			if (mat->matrix_points[i][j].color != 0)
				printf ("->{%lf}  ", mat->matrix_points[i][j].color);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	print_matr_double_new_x_y(t_matrix *mat)
{
	int	i;
	int	j;

	i = 0;
	while (i < mat->height)
	{
		j = 0;
		while (j < mat->width)
		{
			printf ("[%d, %d]->[%lf, %lf]   ",i, j, mat->matrix_points[i][j].new_x, mat->matrix_points[i][j].new_y);
			j++;
		}
		i++;
		printf("\n");
	}
}

