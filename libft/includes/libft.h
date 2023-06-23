/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:11:30 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/23 09:11:40 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_dlist
{
	pid_t			pid;
	unsigned char	character;
	int				index;
	struct s_dlist	*next;
}	t_dlist;

/***************************************************************************/
/**************************** Mandatory Part *******************************/
/***************************************************************************/

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);

/**************************************************************************/
/***************************** Bonus Part *********************************/
/**************************************************************************/

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **olst, t_list *nlst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **olst, t_list *nlst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**************************************************************************/
/************************* Double Linked List *****************************/
/**************************************************************************/

t_dlist	*ft_dlstnew(pid_t pid);
void	ft_dlstadd_front(t_dlist **olst, t_dlist *nlst);
int		ft_dlstsize(t_dlist *lst);
t_dlist	*ft_dlstlast(t_dlist *lst);
void	ft_dlstadd_back(t_dlist **olst, t_dlist *nlst);
void	ft_dlstdelone(t_dlist **head, pid_t pid);
void	ft_dlstclear(t_dlist **lst);
int		ft_dlstfind(t_dlist *head, pid_t pid);

/**************************************************************************/
/********************************* Extras *********************************/
/**************************************************************************/

int		get_next_line(int fd, char **line);
int		ft_atoi_base(const char *s, int c);
int		ft_isspace(int c);

#endif
