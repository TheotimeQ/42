/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:09:01 by tquere            #+#    #+#             */
/*   Updated: 2022/11/19 09:09:01 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len_src;
	char	*dest;
	int		i;

	len_src = ft_strlen(s1);
	dest = malloc(sizeof(char) * len_src + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{	
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
