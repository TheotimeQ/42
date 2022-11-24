/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:52:06 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 13:13:06 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	free_tab(char **tab, int tab_size)
{
	int	index;

	index = 0;
	while (index < tab_size)
	{
		free(tab[index]);
		index++;
	}
	free(tab);
}

static int	fill_tab(char *s, char c, char **tab, t_gbc *gbc)
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
			tab[index_tab] = ft_malloc_substr(s, start, index_s - start, gbc);
			if (tab[index_tab++] == NULL)
			{	
				gbc->malloc_error = 1;
				free_tab(tab, index_tab);
				return (-1);
			}
		}
	}
	return (index_tab);
}

char	**ft_malloc_split(char *s, char c, t_gbc *gbc)
{
	char	**tab;
	int		index_tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_strlen(s) + 1));
	if (tab == NULL)
	{
		gbc->malloc_error = 1;
		return (NULL);
	}
	index_tab = fill_tab(s, c, tab, gbc);
	free_tab(tab, index_tab);
	tab = malloc(sizeof(char *) * (index_tab + 1));
	if (tab == NULL)
	{
		gbc->malloc_error = 1;
		return (NULL);
	}
	index_tab = fill_tab(s, c, tab, gbc);
	if (index_tab >= 0)
		tab[index_tab] = NULL;
	return (tab);
}
