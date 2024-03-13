/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:27:15 by beyildiz          #+#    #+#             */
/*   Updated: 2024/03/13 15:54:41 by beyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join_and_free(char *line, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(line, buffer);
	free(line);
	return (temp);
}

char	*read_first_line(int fd, char *line)
{
	char	*buffer;
	int		bytes_read;

	if (!line)
		line = ft_calloc(1, 1);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (line);
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		line = ft_join_and_free(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free (buffer);
	return (line);
}

char	*get_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] && line[i] == '\n')
		str[i++] = '\n';
	return (str);
}

char	*clean_first_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free (line);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(line) - i + 1), sizeof(*line));
	if (!str)
		return (NULL);
	while (line[++i])
		str[j++] = line[i];
	str[j] = '\0';
	free (line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*output_line;
	static char	*line[FOPEN_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	line[fd] = read_first_line(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	output_line = get_line(line[fd]);
	line[fd] = clean_first_line(line[fd]);
	return (output_line);
}
