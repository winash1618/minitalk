/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 07:27:42 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/05/24 06:28:14 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char *str, char *s)
{
	free (s);
	free (str);
	return (NULL);
}

char	*ft_reader(int fd, char *s, size_t bf)
{
	char	*str;
	int		i;

	i = 1;
	str = (char *)malloc(bf + 1);
	if (!str)
		return (NULL);
	while (i != 0 && !ft_strchr(s, '\n'))
	{
		i = read(fd, str, bf);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		s = ft_strjoin(s, str);
	}
	if (s && s[0] == '\0')
	{
		ft_free(str, s);
		return (NULL);
	}
	free (str);
	return (s);
}

char	*ft_cline(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	s = (char *)malloc(i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_nline(char *str)
{
	int		i;
	char	*s;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free (str);
		return (NULL);
	}
	s = (char *)malloc(ft_strlen(str) - i + 1);
	if (!s)
		return (NULL);
	i++;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	free (str);
	return (s);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		*s;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	str = ft_reader(fd, str, BUFFER_SIZE);
	
	if (!str)
		return (0);
	s = ft_cline(str);
	if (!str)
	{
		*line = s;
		return(ft_strlen(s));
	}
	str = ft_nline(str);
	if (str && *str == '\0')
	{
		free(str);
		str = NULL;
	}
	*line = s;
	return (ft_strlen(s));
}