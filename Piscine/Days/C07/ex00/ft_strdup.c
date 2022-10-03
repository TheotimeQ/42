/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:58:51 by tquere            #+#    #+#             */
/*   Updated: 2022/07/28 04:24:29 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_cpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{	
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strdup(char *src)
{
	int		len_src;
	char	*dest;

	len_src = ft_strlen(src);
	dest = malloc(len_src * sizeof(src));
	ft_cpy(dest, src);
	return (dest);
}
