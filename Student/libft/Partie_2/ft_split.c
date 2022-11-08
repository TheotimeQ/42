/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:12 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 11:16:36 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../Header/libft.h"

char	*cut_char(char const *s, int start, int end)
{
	int		index;
	char	*str;

	str = malloc(sizeof(char) * (end - start + 1));
	index = 0;
	while (s[index])
	{
		if (start <= index && index <= end)
			str[index - start] = s[index];
		index++;
	}	
	str[end - start] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		index_tab;
	int		index_s;
	int		start;
	int		end;

	tab = malloc(sizeof(char *) * ft_strlen(s));
	if (tab == NULL)
		return (NULL);
	index_s = 0;
	index_tab = 0;
	while (s[index_s])
	{
		while (s[index_s] == c && s[index_s])
			index_s++;
		start = index_s;
		while (s[index_s] != c && s[index_s])
			index_s++;
		end = index_s;
		if (start < end)
			tab[index_tab++] = cut_char(s, start, end);
	}
	tab[index_tab] = NULL;
	return (tab);
}
