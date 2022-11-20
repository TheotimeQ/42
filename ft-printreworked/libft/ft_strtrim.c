/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:10:00 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 16:01:47 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_in_set(char c, char const *set)
{
	int		index;

	index = 0;
	while (set[index])
	{
		if (set[index++] == c)
			return (1);
	}
	return (0);
}

int	get_start(char const *s1, char const *set)
{
	int		index;

	index = 0;
	while (s1[index])
	{
		if (check_in_set(s1[index], set) == 0)
			break ;
		index++;
	}
	return (index);
}

int	get_end(char const *s1, char const *set)
{
	int		index;

	index = ft_strlen(s1);
	while (index--)
	{
		if (check_in_set(s1[index], set) == 0)
			break ;
	}
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
