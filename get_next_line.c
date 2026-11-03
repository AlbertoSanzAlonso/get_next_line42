/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:37:43 by asanz-al          #+#    #+#             */
/*   Updated: 2026/11/03 10:10:32 by asanz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buff;
	char	*newbuff;
	size_t	i;
	static char	*stash;
	size_t bytes_read;
	
	i = 0;
	stash = malloc(BUFFER_SIZE + 1);
	if (!stash)
		return (NULL);	
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read <= 0)
    		return (NULL);

	newbuff = malloc(bytes_read + 1);
	if (!newbuff)
    		return (NULL);

	i = 0;
	while (i < bytes_read && buff[i] != '\n')
	{
    		newbuff[i] = buff[i];
    		i++;
	}
	newbuff[i] = '\0';
	ft_memcpy(stash, (const char *)newbuff, i); 
	return (stash);
}
/*
int	main(void)
{
	int	fd;
	char	*line;
	
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}*/

