#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1234
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*read_first_line(int fd, char *line);
char	*get_line(char *line);
char	*clear_first_line(char *line);
int		ft_get_index_of(char *s1, char *s2);
char	*ft_itoa(int n);
void	*ft_calloc(unsigned int count, unsigned int size);
#endif
