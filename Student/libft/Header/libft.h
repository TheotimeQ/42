
#ifndef LIBFT_H
#define LIBFT_H

#include <stddef.h>

size_t ft_strlen(const char *s);

char *ft_substr(char const *s, unsigned int start,size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);

#endif 