/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:13:51 by tquere            #+#    #+#             */
/*   Updated: 2022/07/11 15:36:40 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	len_dest;
	int	len_src;

	len_dest = 0;
	while (dest[len_dest])
	{
		len_dest++;
	}
	len_src = 0;
	while (src[len_src])
	{
		dest[len_dest + len_src] = src[len_src];
		len_src++;
	}
	dest[len_dest + len_src] = '\0';
	return (dest);
}
