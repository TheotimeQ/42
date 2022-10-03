/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:30:47 by tquere            #+#    #+#             */
/*   Updated: 2022/07/10 13:30:55 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_lenght(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				lenght;

	lenght = ft_str_lenght(src);
	i = 0;
	while (src[i] && size > 1)
	{
		dest[i] = src[i];
		i++;
		size--;
	}
	dest[i] = '\0';
	return (lenght);
}
