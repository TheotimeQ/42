/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:23:54 by tquere            #+#    #+#             */
/*   Updated: 2022/07/28 19:40:28 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *word)
{
	int	size;

	size = 0;
	while (word[size])
		size++;
	return (size);
}

int	ft_strlen_total(char **word, int len_word)
{
	int	size;
	int	i;

	i = -1;
	size = 0;
	while (++i < len_word)
		size += ft_strlen(word[i]);
	return (size);
}

int	total_size_error(int total_size)
{
	if (total_size > -1)
		return (total_size);
	return (0);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*tab;
	int		j;
	int		total_size;
	int		k;

	total_size = ft_strlen_total(strs, size) + (ft_strlen(sep) * (size - 1));
	total_size = total_size_error(total_size);
	tab = malloc (sizeof(char) * total_size);
	i = -1;
	k = -1;
	while (++i <= (size * 2) - 1)
	{
		j = -1;
		if (i % 2 == 0)
			while (strs[i / 2][++j])
				tab[++k] = strs[i / 2][j];
		else if (size > 1 && i / 2 < size - 1)
			while (sep[++j])
				tab[++k] = sep[j];
	}
	tab[++k] = '\0';
	return (tab);
}
