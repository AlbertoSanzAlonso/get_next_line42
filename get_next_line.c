/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:37:43 by asanz-al          #+#    #+#             */
/*   Updated: 2026/11/12 09:25:06 by asanz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char **stash)
{
	int	line_len;
	char	*newline;
	int	i;
	
	i = 0;
	line_len = ft_line_len(*stash);
	newline = malloc(line_len + 1);
	if (!newline)
		return (NULL);
	while (i < line_len)
	{
		newline[i] = *stash[i];
		i++;
	}
	newline[line_len + 1] = '\0'; 
	return (newline);
} 
		
char	*ft_get_rest(char **stash, int str_len, int line_len)
{
	char	*rest;
	int	i;
	
	i = 0;
	rest = malloc(str_len - line_len + 1);
	if (*stash[str_len + 1])
		rest[i++] = *stash[++line_len];
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

	if (!stash)
	{
		stash = malloc

	while (!ft_strchr(stash, '\n'))
	{	
		bytes_read = read((fd, buff, BUFFER_SIZE) > 0);
		if (bytes_read < 0)
			return (NULL);
		else
			buff[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buff);
		stash = ft_free_null(&stash);
		stash = tmp;
		ft_free_null(tmp);
	}
	line = ft_get_line(&stash);
	ft_get_rest(stash);
	printf("%s\n", line);

	return (line);
}
