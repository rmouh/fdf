/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:42:38 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/03/17 20:34:53 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//https://cdn.intra.42.fr/users/3043355b639371ff9f7b9eb3f805feb4/rmouhoub.jpg

int	ft_atoi_base(char *nb, unsigned long base)
{
	if (nb > base - 1)
		return (ft_putnbrr((nb / base), base));
	return ((HEXA_DECIM[nb % base]));
}


t_list	*read_map(char *file, int *nb)
{
	int		fd;0x00FF0000
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
			return (free_list(chaine), NULL);
		ft_lstadd_back(&chaine, temp);
		read = get_next_line(fd, 0);
	}
	
	get_next_line(fd, 1);
	return (chaine);
	// points_list = ft_malloc(sizeof(t_point)*)
	// if (dd < 0)
	// 	exite(1);
	// read = get_next_line(fd);
	// if (ft_strncmp(",", read, 1) == 0)

}



int	put_in_tab(int nb, int size_all, t_point **tab, t_list *track)
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
		tab[i] = malloc (sizeof(t_point) * line_size);
		if (!tab[i])
			return (free_tab(tab), 0);
		get_cords_colors(line_size, tab, line, i);
		i++;
	}
	return (size_all);
}

t_point	**creat_table(char *file, int *size)
{
	t_point	**tab;
	int		nb;
	int		size_all;
	t_list	*chaine;
	t_list	*track;

	size_all = 0;
	chaine = read_map(file, &nb);
	tab = malloc(sizeof(t_point *) * nb);
	if (!tab)
		return (free (tab), free_list(chaine), NULL);
	printll(chaine);
	track = chaine;
	*size = put_in_tab(nb, size_all, tab, track);
	if (*size == 0)
		return (free (tab), free_list(chaine), NULL);
	return (tab);
}


// int	main(void)
// {
// 	int	size;
// 	t_point	**tab;
// 	//chaine = read_map("test_maps/10-2.fdf", &nb);
// 	tab = creat_table("test_maps/10-2.fdf", &size);
// 	for (int i = 0; i< 10; i++)
// 	{
// 		for (int j = 0; j< 10; j++)
// 		{
// 			ft_printf ("[%d][%d] = %d	", (tab[i][j]).y, (tab[i][j]).x, (tab[i][j]).z);
// 		}
// 		ft_printf("\n");
// 	}
// 	// int r = ft_putnbrr(ff, 16);
// 	// unsigned  r = oxff;
// 	// printf("%d\n", r);
	

// }