/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:35:37 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/03/11 18:30:14 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define MAXSIZE 18446744013709551615UL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define HEXA_DECIM "0123456789abcdef0123456789ABCDEF"

/*
** Memory
*/
void				*ft_memset(void *dest, int c, size_t n);
void				ft_bzero(void *s, int n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, int n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
/*
** String
*/
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *str, int c);
int					ft_strncmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big,
						const char *little, size_t blen);
char				*ft_strdup(const char *s);
int					ft_atoi(const char *str);
/*
** Type
*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** Part 2 - Additional functions
*/

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Part 3 - Bonus
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
int					ft_lstsize(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));

/*
** printf
*/

int					ft_print_d_or_i(va_list list, int base,
						int up_do, int *counter);
int					ft_parse(const char c, va_list list);
int					ft_printf(const char *str, ...);
int					ft_putchar(char c);
int					ft_putnbr(unsigned long nb, unsigned long base,
						int up_do, int *counter);
int					ft_putstr(char *c);
int					ft_printf(const char *str, ...);
/*
** get next line 
*/

char				*get_line(char *str);
int					reached_eol(char *str);
char				*reading(int fd, char *reading_buf, char *stock);
char				*get_after_line(char *str);
char				*get_next_line(int fd);
size_t				ft_strlen(const char *s);
char				*ft_strjoin2(char *s1, char *s2);
void				*ft_memcpy(void *dest, const void *src, size_t n);

#endif
