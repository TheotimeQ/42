/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:27:59 by tquere            #+#    #+#             */
/*   Updated: 2022/07/23 18:28:01 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>

void	ft_putstr(char *str, int output)
{
	int	i;

	i = 0 ;
	while (str[i])
	{
		write(output, &str[i], 1);
		i++;
	}
}

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

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len_dest;
	unsigned int	len_src;

	len_dest = 0;
	while (dest[len_dest])
	{
		len_dest++;
	}
	len_src = 0;
	while (src[len_src] && len_src < nb)
	{
		dest[len_dest + len_src] = src[len_src];
		len_src++;
	}
	dest[len_dest + len_src] = '\0';
	return (dest);
}
