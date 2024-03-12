#include "get_next_line.h"

char	*ft_join_and_free(char *line, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(line, buffer);
	free(line);
	return (temp);
}

char	*get_first_line(int fd, char *line)
{
	char	*buffer;
	int		read;

	if (!line)
		line = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read = 1;
	while (read > 0)
	{
		read = read(fd, buffer, BUFFER_SIZE);
		if (read == -1)
		{
			free (line);
			free (buffer);
			return (NULL);
		}
		buffer[read] = 0;
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

char	*clean_first_line(char *text)
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
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_first_line(fd, line);
	if (!line)
		return (NULL);
	output_line = get_line(line);
	line = clear_first_line(line);
	return (output_line);
}

/* int main()
{
	int fd = open("a.txt", O_RDONLY);
	char *a;

	while ((a = get_next_line(fd)))
	{
		printf("%s", a);
	}

	// printf("%s", get_next_line(fd));

	return 0;
} */
