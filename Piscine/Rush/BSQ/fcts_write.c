/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:16:33 by tquere            #+#    #+#             */
/*   Updated: 2022/07/27 13:59:46 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

t_map_var	check_map_args(t_map_var map)
{	
	if (map.empty == map.obstacle || map.empty == map.full)
		map.error = 1;
	if (map.obstacle == map.full)
		map.error = 1;
	if (!(' ' <= map.empty && map.empty <= '~'))
		map.error = 1;
	if (!(' ' <= map.obstacle && map.obstacle <= '~'))
		map.error = 1;
	if (!(' ' <= map.full && map.full <= '~'))
		map.error = 1;
	return (map);
}

void	ft_putstr(char *str, int output, int visual)
{
	int	i;

	i = 0 ;
	while (str[i])
	{
		write(output, &str[i], 1);
		if (visual == 1)
			write(output, " ", 1);
		i++;
	}
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
	return (dest);
}

void	init_str(char *str, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		str[i] = 0;
		i++;
	}
	str[0] = '\0';
}

int	convert_str_int(char *str)
{	
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}
