/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:50:20 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 13:12:29 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_malloc_str(const char *s1, t_gbc *gbc)
{
	int		len_src;
	char	*dest;
	int		i;

	len_src = ft_strlen(s1);
	dest = malloc(sizeof(char) * len_src + 1);
	if (dest == NULL)
	{
		gbc->malloc_error = 1;
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{	
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
