/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:27:15 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/03/16 14:09:27 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
