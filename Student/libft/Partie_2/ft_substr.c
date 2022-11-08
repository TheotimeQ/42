
#include <stddef.h>
#include <stdlib.h>

#include "../Header/libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int 	index;
	char 			*str;
	
	str = malloc( sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	index = 0;
	while (s[index] && index < start)
	{
		index++;
	}
	while (s[index] && index - start < len)
	{
		str[index - start] = s[index];
		index++;
	}
	str[index - start] = '\0';
	return (str);
}
