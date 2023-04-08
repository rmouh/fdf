/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:42:38 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/04/08 16:55:07 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//https://cdn.intra.42.fr/users/3043355b639371ff9f7b9eb3f805feb4/rmouhoub.jpg

int	is_upper(char c)
{
	return ((c >= 'A' && c <= 'Z'));
}

double	conversion(char *p, int sign, int base)
{
	double	result;
	int		digit;

	result = 0;
	while (ft_isalnum(*p))
	{
		if (ft_isdigit(*p))
			digit = (*p - '0');
		else
		{
			if (is_upper(*p))
				digit = (*p - 'A' + 10);
			else
				digit = (*p - 'a' + 10);
		}
		if (digit >= base)
			break ;
		result = result * base + digit;
		++p;
	}
	return (result * sign);
}

double	ft_atoi_base(char *str, int base)
{
	char	*p;
	int		sign;

	p = str;
	sign = 1;
	while (*p == ' ' || *p != ',')
		++p;
	p++;
	if (*p++ == '-')
		sign = -1;
	else
		sign = 1;
	if (*p == '0')
		++p;
	if (*p == 'x' || *p == 'X')
			++p;
	return (conversion(p, sign, base));
}

// int	ft_atoi_base(char *nb, unsigned long base, double *res)
// {
// 	if (nb > base - 1)
// 		return (ft_atoi_base((nb / base), base));
// 	return (res(HEXA_DECIM[nb % base]));
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



int	put_in_tab(int nb, int size_all, t_matrix *mat, t_list *track)
{
	char	**line;
	int		line_size;
	int		i;

	i = 0;
	while (nb-- > 0)
	{
		line = ft_split(track->content, ' ');
		line_size = ft_strlenn(line) - 1;
		size_all += line_size;
		track = track->next;
		mat->matrix_points[i] = malloc (sizeof(t_point) * line_size);
		if (!mat->matrix_points[i])
			return (0);
		get_cords_colors(line_size, mat, line, i);
		free_line(line);
		i++;
	}
	return (line_size);
}

/*
		this fonction reades the file and store a
		 linked list of linesin strings (chaine)
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
	*size = put_in_tab(nb, size_all, mat, track);
	if (*size == 0)
		return (free_matrix (mat), free_list(&chaine), NULL);
	free_list(&chaine);
	printll(chaine);
	mat->width = *size;
	mat->height = nb;
	return (mat);
}

/*
int	main(void)
{

	//double d  = ft_atoi_base("0x0FF0000", 16);
	//printf(" %lf\n", d);
	int	size;
	t_point	**tab;
	t_matrix	*mat;
	//chaine = read_map("test_maps/10-2.fdf", &nb);

	
	mat = creat_table("test_maps/pyramide.fdf", &size);
	//printf(" hi %d  w %d\n", mat->height, mat->width);
	print_matr_double_z(mat);

	//print_matr_double_z(mat);
	the_formula(mat, 35.264, 45);
	print_matr_double_new_x_y(mat);
	//ft_printf("%d", ft_strcontain("200xFF0000", ","));
	free_matrix(mat);

	

}
*/