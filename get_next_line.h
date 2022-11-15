#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

char    *get_next_line(int fd);
char    *fill_remainder(int fd, char *remainder);
char	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
int	contains_new_line(char *buffer);
char    *separate_line(char *remainder);
char    *clean_remainder(char *remainder);
size_t	ft_strlen(char *str);
char    *get_line(char *remainder);

#endif
