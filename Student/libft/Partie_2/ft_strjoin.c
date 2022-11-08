
#include <stddef.h>
#include <stdlib.h>

#include "../Header/libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    unsigned int 	index;
    size_t          len_s1;
    size_t          len_s2;
	char 			*str;
    
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
	str = malloc( sizeof(char) * (len_s1 + len_s2));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (index < len_s1)
	{   
        str[index] = s1[index];
		index++;
	}
	while (index - len_s1 < len_s2)
	{   
        str[index] = s2[index - len_s1];
		index++;
	}
	str[index] = '\0';
	return (str);
}