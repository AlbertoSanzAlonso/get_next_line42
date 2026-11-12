/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:40:07 by asanz-al          #+#    #+#             */
/*   Updated: 2026/11/05 19:42:26 by asanz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
int	ft_strlen(char *str);
char	*ft_strdup(char·*s);
char	*ft_strchr(char *s, int c);
void	*ft_free_null(void·**ptr)$
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_stash_filler(char **stash, char *buff, int fd);
char	*ft_stash_handler(char **stash, char **buff, int fd);
char	*ft_get_rest(char **stash, int str_len, int line_len);
char	*ft_get_line(char **stash);






#endif
