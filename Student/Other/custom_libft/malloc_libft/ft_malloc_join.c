/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:41:44 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 13:16:55 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_malloc_join(char *s1, char *s2, t_gbc *gbc)
{
	size_t			index;
	size_t			len_s1;
	size_t			len_s2;
	char			*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 && !s2)
		return (s1);
	if (!s1 && s2)
		return (s2);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * ((len_s1 + len_s2) + 1));
	if (str == NULL)
		return (gbc->malloc_error = 1, NULL);
	index = -1;
	while (++index < len_s1)
		str[index] = s1[index];
	while (++index - len_s1 < len_s2)
		str[index] = s2[index - len_s1];
	str[index] = '\0';
	return (str);
}
