/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:25:19 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/03/11 18:31:49 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	reached_eol(char *str)
{
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*reading(int fd, char *reading_buf, char *stock)
{
	int	readed;

	readed = 1;
	while (readed > 0 && !reached_eol(stock))
	{
		readed = read (fd, reading_buf, BUFFER_SIZE);
		if (readed < 0)
			return (NULL);
		reading_buf[readed] = '\0';
		stock = ft_strjoin2(stock, reading_buf);
	}
	return (stock);
}

char	*get_after_line(char *str)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	buf = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!buf)
		return (NULL);
	i++;
	while (str[i])
		buf[j++] = str[i++];
	buf[j] = '\0';
	free(str);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*stock[1024];
	char		*line;
	char		*reading_buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reading_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!reading_buff)
		return (NULL);
	stock[fd] = reading(fd, reading_buff, stock[fd]);
	if (stock[fd] == NULL)
	{
		free(stock[fd]);
		free(reading_buff);
		return (NULL);
	}
	line = get_line(stock[fd]);
	stock[fd] = get_after_line(stock[fd]);
	free (reading_buff);
	return (line);
}
// #include <stdio.h>
// #include <fcntl.h>

// int main (int argc, char *argv[])
// {
// 	(void )argc;
// 	//(void )argv;

// 	char *buf;
// 	int fd = open (argv[1], O_RDONLY);
// 	while ((buf = get_next_line(fd)))
// 	{
// 		printf("%s", buf);
// 		free(buf);	
// 	}
// }