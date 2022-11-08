/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:34:28 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 17:15:13 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*str_1;
	char		*str_2;

	i = 0;
	str_1 = (char *)s1;
	str_2 = (char *)s2;
	while (str_1[i] && str_1[i] == str_2[i] && i < n)
	{
		if (str_1[i] - str_2[i] != 0)
			return (str_1[i] - str_2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (str_1[i] - str_2[i]);
}
