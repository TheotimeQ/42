/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:09:09 by tquere            #+#    #+#             */
/*   Updated: 2022/11/19 09:09:10 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			index;
	size_t			len_s1;
	size_t			len_s2;
	char			*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * ((len_s1 + len_s2) + 1));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (index < len_s1 && s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	while (index - len_s1 < len_s2 && s2[index - len_s1])
	{
		str[index] = s2[index - len_s1];
		index++;
	}
	str[index] = '\0';
	return (str);
}
