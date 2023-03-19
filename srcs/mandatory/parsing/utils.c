/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:25:20 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/03/19 12:39:17 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab_int(t_tab *tab)
{
	//double	*track;
	int		i;

	i = 0;
	//track = *(tab->tab);
	while (i < tab->height)
		free(tab->tab[i++]);
	free(tab->tab);
	free(tab);
}

void	free_line(char **tab)
{
	//char	*track;
	int		i;

	i = 0;
	//track = *tab;
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
	//return (1);
	// t_list	*track;
	// t_list	*lst;

	// lst = chaine;
	// track = chaine;
	// while (lst != NULL)
	// {
	// 	lst = lst->next;
	// 	free(track);
	// 	track = lst;
	// }
	// free(track);
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
	int		j;

	j = 0;
	while (line_size-- > 0)
	{
		//f (ft_strcontain(*line, ","))
		point = &tab[i][j];
		(*point).z = ft_atoi(line[j]);
		(*point).x = j;
		(*point).y = i;
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
			ft_printf ("%d  ", mat->matrix_points[i][j].z);
			j++;
		}
		i++;
		ft_printf("\n");
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
			printf ("[%lf, %lf]   ", mat->matrix_points[i][j].new_x, mat->matrix_points[i][j].new_y);
			j++;
		}
		i++;
		ft_printf("\n");
	}
}

