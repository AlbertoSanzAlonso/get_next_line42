/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:37:43 by asanz-al          #+#    #+#             */
/*   Updated: 2026/11/18 20:29:10 by asanz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char **stash)
{
	int	line_len;
	char	*newline;
	int	i;
	
	if (!stash || !*stash)
		return (0);
	i = 0;
	line_len = 0;
	printf("entra en la segunda");
	while (*stash[i] != '\n')
		line_len++;
	newline = malloc(line_len + 1);
	if (!newline)
		return (NULL);
	printf("Crea malloc");
	while (i < line_len)
	{
		newline[i] = **stash++;
		i++;
	}
	newline[line_len + 1] = '\0';
	printf("Nueva linea: %s\n", newline);
	return (newline);
} 
		
char	*ft_get_rest(char **stash)
{
	char	*rest;
	int	i;
	
	i = 0;
	rest = malloc(ft_strlen(*stash) + 1);
	while (*stash[i])
	{
		rest[i] = *stash[i];
		i++;
	}
	rest[i + 1 ] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*line;
	static char	*stash;
	char	*tmp;
	int bytes_read;
	int	i;

	i = 0;
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	printf("Entra en funcion principal\n");
	while (!ft_strchr(stash, '\n'))
	{	
		printf("%p\n", ft_strchr(stash, '\n'));
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		else
			buff[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buff);
		printf("iteracion %d tmp: %s\n", i,  tmp);
		ft_free_null((void *)stash);
		stash = tmp;
		i++;
	}
	printf("Sale");
	line = ft_get_line(&stash);
	stash = ft_get_rest(&stash);
	printf("%s\n", line);
	ft_free_null((void *)tmp);
	return (line);
}
