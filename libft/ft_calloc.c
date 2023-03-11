/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:10:42 by rmouhoub          #+#    #+#             */
/*   Updated: 2022/11/17 14:38:56 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buf;

	if (nmemb > MAXSIZE || size > MAXSIZE)
		return (NULL);
	buf = malloc(size * nmemb);
	if (!buf)
		return (NULL);
	if (buf)
		ft_bzero(buf, size * nmemb);
	return (buf);
}
