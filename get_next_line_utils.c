/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanz-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:39:25 by asanz-al          #+#    #+#             */
/*   Updated: 2026/11/02 20:13:26 by asanz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
        char    *newstr;
        char    *ptr;
        char    *orig_s1; // Guardamos el puntero original para poder hacer free de s1 si es necesario

        if (!s2)
                return (NULL);
        // Si s1 es NULL, lo tratamos temporalmente como un string vacío
        orig_s1 = s1;
        if (!s1)
                s1 = "";
        newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
        if (!newstr)
                return (NULL);
        ptr = newstr;
        while (*s1)
                *ptr++ = *s1++;
        while (*s2)
                *ptr++ = *s2++;
        *ptr = '\0';
        if (orig_s1)
                free(orig_s1);
        return (newstr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
