/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:10:42 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/16 14:35:09 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_callloc(int nmemb)
{
	t_list	*buf;
	t_list	*temp;

	buf = malloc(sizeof(t_list) * nmemb);
	if (!buf)
		return (0);
	temp = buf;
	while (nmemb-- > 0)
	{
		buf->content = 0;
		buf = buf->next;
	}
	return (temp);
}

long long int	*ft_calloc_tab(int nmemb, int sizeoff)
{
	long long int	*buf;
	int				i;

	i = 0;
	buf = malloc(sizeoff * (nmemb));
	if (!buf)
		return (NULL);
	while (i < nmemb)
	{
		buf[i] = 0;
		i++;
	}
	return (buf);
}

int	*ft_callloc_tab(int nmemb)
{
	int	*buf;
	int	i;

	i = 0;
	buf = malloc(sizeof(int) * (nmemb));
	if (!buf)
		return (NULL);
	while (i < nmemb)
	{
		buf[i] = 0;
		i++;
	}
	return (buf);
}
