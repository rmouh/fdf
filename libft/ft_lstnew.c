/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:14:46 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/16 14:12:15 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content, int index)
{
	t_list	*new;

	new = ft_callloc(1);
	if (!new)
		return (NULL);
	new->content = content;
	new->lower_cost = -1;
	new->index = index;
	new->next = NULL;
	new->ell.ra = 0;
	new->ell.rb = 0;
	new->ell.rra = 0;
	new->ell.rrb = 0;
	new->ell.rrr = 0;
	new->ell.rr = 0;
	new->ell.bok = -1;
	new->ell.bok_index = 0;
	return (new);
}
/*
#include <stdio.h>
int main(void)
{
	int *v;
	//v = &c;
	t_list *t = ft_lstnew ((void *)"c");
	//int c=7;

	//t = ft_lstnew (v);
	printf("%s \n %p", (t->content), t->next);
	free(t);
	
}*/