/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:08:07 by beyildiz          #+#    #+#             */
/*   Updated: 2024/02/18 15:08:07 by beyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_before_new_line(int fd, char *result);
char	*ft_join_free(char *result, char *buffer);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, char c);
void	*ft_calloc(size_t nbr, size_t size);
char	*ft_the_line(char *buffer);
char	*ft_after_new_line(char *buffer);
char	*ft_strjoin(const char *str1, const char *str2);
void	ft_bzero(void *s, size_t n);

#endif
