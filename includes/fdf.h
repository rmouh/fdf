/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:53:34 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/03/17 20:26:16 by rmouhoub         ###   ########.fr       */
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
	int	x;
	int	y;
	int	z;
	int	color;
	int	new_x;
	int	new_y;
}				t_point;

typedef struct s_camera{
	int	alpha;
	int	beta;
}				t_camera;

/*

		parsing fonctions

*/
void	free_tab(t_point **tab);
void	free_tab_int(int **tab);
void	free_list(t_list *chaine);
t_list	*read_map(char *file, int *nb);
void	get_cords_colors(int line_size, t_point **tab, char **line, int i);
int		put_in_tab(int nb, int size_all, t_point **tab, t_list *track);
t_point	**creat_table(char *file, int *size);
void	print_tab(int hi, int wi, int **tab);


/*

		mapping fonctions

*/

void	initialise_p(t_point *p);
// int		malloc_matric_n(int n, int p, int **res);
int		**malloc_matric_n(int n, int p, int **res);
int		**multiplicate(int **tab1, int **tab2, int n, int q, int m);


#endif

/*

t_point	**my = (t_point **)malloc (sizeof(t_point *) * num);

i = 0;
while (i < num)
{
	my[i] = (t_point *)malloc (sizeof(t_point) * width);
}

*/