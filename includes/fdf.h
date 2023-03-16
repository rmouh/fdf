/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:53:34 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/03/16 19:23:01 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx/mlx.h"
# include<stdio.h> 
# include <fcntl.h> 
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

#endif

/*

t_point	**my = (t_point **)malloc (sizeof(t_point *) * num);

i = 0;
while (i < num)
{
	my[i] = (t_point *)malloc (sizeof(t_point) * width);
}

*/