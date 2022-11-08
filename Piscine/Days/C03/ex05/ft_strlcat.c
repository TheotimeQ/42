/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:14:40 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 16:28:06 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				i;
	int				j;
	unsigned int	dest_size;
	unsigned int	src_size;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	i = 0;
	if (size < dest_size)
		return (size + src_size);
	while (dest[i] != '\0' && size > 0)
	{
		i++;
		size--;
	}
	j = 0;
	while (src[j] != '\0' && size > 1)
	{
		dest[i + j] = src[j];
		size--;
		j++;
	}
	if (size > 0)
		dest[i + j] = '\0';
	return (dest_size + src_size);
}
