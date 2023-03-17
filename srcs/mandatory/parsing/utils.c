/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:25:20 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/03/17 19:10:40 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(t_point **tab)
{
	t_point	*track;
	int		i;

	i = 0;
	track = *tab;
	while (tab[i++])
		free(tab[i]);
	free(track);
}

void	free_tab_int(int **tab)
{
	int	*track;
	int		i;

	i = 0;
	track = *tab;
	while (tab[i++])
		free(tab[i]);
	free(track);
}

void	free_list(t_list *chaine)
{
	t_list	*track;
	t_list	*lst;

	lst = chaine;
	track = lst;
	while (lst)
	{
		lst = lst->next;
		free(track);
		track = lst;
	}
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

void	print_tab(int hi, int wi, int **tab)
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
