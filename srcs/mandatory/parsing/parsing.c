/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:42:38 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/03/19 12:39:50 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//https://cdn.intra.42.fr/users/3043355b639371ff9f7b9eb3f805feb4/rmouhoub.jpg

// int	ft_atoi_base(char *nb, unsigned long base)
// {
// 	if (nb > base - 1)
// 		return (ft_putnbrr((nb / base), base));
// 	return ((HEXA_DECIM[nb % base]));
// }

/*
		nb is the nember of lignes in the map (the hight)
*/
t_list	*read_map(char *file, int *nb)
{
	int		fd;
	char	*read;
	t_list	*temp;
	t_list	*chaine;

	chaine = NULL;
	*nb = 0;
	fd = open(file, O_RDONLY);
	read = get_next_line(fd, 0);
	while (read)
	{
		temp = ft_lstnew(read, (*nb)++);
		if (!temp)
			return (free_list(&chaine), NULL);
		ft_lstadd_back(&chaine, temp);
		//free(read);
		read = get_next_line(fd, 0);
	}
	get_next_line(fd, 1);
	//free(read);
	return (chaine);

}



int	put_in_tab(int nb, int size_all, t_point **tab, t_list *track)
{
	char	**line;
	int		line_size;
	//t_list	**lst;
	int		i;

	i = 0;
	//lst = &track;
	while (nb-- > 0)
	{
		line = ft_split(track->content, ' ');
		line_size = ft_strlenn(line) - 1;
		//printf("line size %d\n", line_size);
		size_all += line_size;
		track = track->next;
		tab[i] = malloc (sizeof(t_point) * line_size);
		if (!tab[i])
			return (0);
		get_cords_colors(line_size, tab, line, i);
		free_line(line);
		i++;
	}
	//free(lst);
	return (line_size);
}

/*
		this fonction reades the file and store a linked list of linesin strings (chaine)
		create a matrix 
		store in mat->mat_point a 2D array of points
		return 

*/

t_matrix	*creat_table(char *file, int *size)
{
	t_matrix	*mat;
	int			nb;
	int			size_all;
	t_list		*chaine;
	t_list		*track;

	size_all = 0;
	chaine = read_map(file, &nb);
	mat = malloc (sizeof(t_matrix));
	if (!mat)
		free_list(&chaine);
	mat->matrix_points = malloc(sizeof(t_point *) * nb);
	if (!(mat->matrix_points))
		return (free_list(&chaine), free(mat), NULL);
	track = chaine;
	*size = put_in_tab(nb, size_all, mat->matrix_points, track);
	if (*size == 0)
		return (free_matrix (mat),free_list(&chaine), NULL);
	free_list(&chaine);
	printll(chaine);
	mat->width = *size;
	mat->height = nb;
	return (mat);
}

int	main(void)
{
	int	size;
	t_point	**tab;
	t_matrix	*mat;
	//chaine = read_map("test_maps/10-2.fdf", &nb);

	
	mat = creat_table("test_maps/42.fdf", &size);
	printf(" hi %d  w %d\n", mat->height, mat->width);
	//print_matr_double_z(mat);
	free_matrix(mat);
	
	//the_formula(mat, 0.5, 1.3);
	//tab = mat->matrix_points;
	//print_tab(mat->height, mat->width, tab);
	// for (int i = 0; i<11; i++)
	// {
	// 	for (int j = 0; j< 19; j++)
	// 	{
	// 		printf ("%d ", (tab[i][j]).z);
	// 		//ft_printf ("[%d][%d] = %d	", (tab[i][j]).y, (tab[i][j]).x, (tab[i][j]).z);
	// 	}
	// 	printf("\n");
	// }
	// int r = ft_putnbrr(ff, 16);
	// unsigned  r = oxff;
	//printf(" hi %d  w %d\n", mat->height, mat->width);

	

}