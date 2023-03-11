/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:13:59 by rmouhoub          #+#    #+#             */
/*   Updated: 2022/11/11 18:44:42 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}
/*
#include <stdio.h>
int main ()
{
	t_list	*chaine ;

	// *chaine = ft_lstnew ((void *)"c");
	// printf("%s \n %p", **((chaine)->content), *(chaine->next));
	// free(*chaine);
	
	chaine = ft_lstnew("c");
	
	ft_lstadd_front(&chaine, ft_lstnew("h"));
	//printf("%s \n %s", (char *)(chaine->next->content), (char *)chaine->content);
	 
	ft_lstadd_front(&chaine, ft_lstnew("g"));
	ft_lstadd_front(&chaine, ft_lstnew("l"));
	ft_lstadd_front(&chaine, ft_lstnew("l"));
	ft_lstadd_back(&chaine, ft_lstnew("o"));
	
	
	while (chaine )
	{
		//printf("true");

		printf("element :: %s\n", (char *)(chaine)->content);
		chaine = (chaine)->next;
	}
}
*/