
#include <stdlib.h>

#include "../Header/libft.h"

static int check_in_set(char c,char const *set)
{
	int		index;

	index = 0;
	while (set[index] != c && set[index])
		index++;
	if (set[index])
		return (1);
	return (0); 
}

char *ft_strtrim(char const *s1, char const *set)
{
	int		index;
	int 	start;
	int		end;
	char 	*str;

	str = malloc(sizeof(char) * ft_strlen(s1));
	index = 0;
	while (s1[index])
	{
		if (check_in_set(s1[index],set) == 0)
			break;
		else
			index++;
	}
	start = index;
	while (s1[index])
	{
		if (check_in_set(s1[index],set) == 0)
			end = index;
		index++;
	}
	str = ft_substr(s1, start, end - start);
	return (str);
}