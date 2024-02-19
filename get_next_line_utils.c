/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:07:56 by beyildiz          #+#    #+#             */
/*   Updated: 2024/02/18 15:07:56 by beyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nbr, size_t size)
{
	size_t	newsize;
	void	*result;

	if (nbr == 0 || size == 0)
	{
		nbr = 1;
		size = 1;
	}
	newsize = nbr * size;
	result = malloc(newsize);
	if (result == NULL)
		return (0);
	else
		ft_bzero(result, newsize);
	return (result);
}

char	*ft_strchr(char *str, char c)
{
	while (*str != (unsigned char)c)
	{
		if (!*str++)
			return (0);
	}
	return (str);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	r = malloc((ft_strlen(str1) + ft_strlen(str2)) * sizeof(char) + 1);
	if (!r || !str1 || !str2)
		return (0);
	while (str1[i])
	{
		r[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		r[i] = str2[j];
		i++;
		j++;
	}
	r[i] = '\0';
	return (r);
}
