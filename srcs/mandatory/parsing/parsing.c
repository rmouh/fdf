/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:42:38 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/03/16 19:54:17 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//https://cdn.intra.42.fr/users/3043355b639371ff9f7b9eb3f805feb4/rmouhoub.jpg

void	ft_lstclear(t_list **lst, void (*del)(char *))
{
	t_list	*track;
	t_list	*nextt;

	track = *lst;
	*lst = NULL;
	while (track != NULL)
	{
		nextt = track->next;
		(*del)(track->content);
		free(track);
		track = nextt;
	}
}
void clear_list(t_list *chaine)
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
			return (clear_list(chaine), NULL);
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

void 

int	put_in_tab(int nb, int size_all, t_point **tab, t_list *track)
{
	char	**line;
	int		line_size;
	int		j;
	int		i;
	t_point	*point;

	i = 0;
	while (nb-- > 0)
	{
		line = ft_split(track->content, ' ');
		line_size = ft_strlenn(line) - 1;
		track = track->next;
		tab[i] = malloc (sizeof(t_point ) * line_size);
		j = 0;
		while (line_size-- > 0)
		{
			point = &tab[i][j];
			(*point).z = ft_atoi(line[j]);
			(*point).x = j;
			(*point).y = i;
			j++;
		}
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
	printll(chaine);
	track = chaine;
	*size =  put_in_tab(nb, size_all, tab, track);
		// for (int i = 0; i< 10; i++)
	// {
	// 	for (int j = 0; j< 10; j++)
	// 	{
	// 		ft_printf ("[%d][%d] = %d	 ", i, j, tab[i][j]);
	// 	}
	// 	ft_printf("\n");
	//}
	return (tab);
}


int	main(void)
{
	int	size;
	t_point	**tab;
	//chaine = read_map("test_maps/10-2.fdf", &nb);
	tab = creat_table("test_maps/20-60.fdf", &size);
	for (int i = 0; i< 20; i++)
	{
		for (int j = 0; j< 20; j++)
		{
			ft_printf ("[%d][%d] = %d	", (tab[i][j]).y, (tab[i][j]).x, (tab[i][j]).z);
		}
		ft_printf("\n");
	}
	

}