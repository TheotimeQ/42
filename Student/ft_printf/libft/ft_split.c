/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:12 by tquere            #+#    #+#             */
/*   Updated: 2022/11/19 20:29:53 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

void	free_tab(char **tab)
{
	int	index;

	index = 0;
	while (tab[index] != NULL)
	{
		free(tab[index]);
		index++;
	}
	free(tab);
}

int	fill_tab(char const *s, char c, char **tab)
{
	int		index_tab;
	int		index_s;
	int		start;

	index_s = 0;
	index_tab = 0;
	while (s[index_s])
	{
		while (s[index_s] && s[index_s] == c)
			index_s++;
		start = index_s;
		while (s[index_s] && s[index_s] != c)
			index_s++;
		if (start < index_s)
		{
			tab[index_tab] = ft_substr(s, start, index_s - start);
			if (tab[index_tab++] == NULL)
			{
				free_tab(tab);
				return (-1);
			}
		}
	}
	return (index_tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		index_tab;

	tab = malloc(sizeof(char *) * (ft_strlen(s) + 1));
	if (tab == NULL || s == NULL)
		return (NULL);
	index_tab = fill_tab(s, c, tab);
	if (index_tab >= 0)
		tab[index_tab] = NULL;
	return (tab);
}
