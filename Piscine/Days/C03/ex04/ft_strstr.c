/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:14:20 by tquere            #+#    #+#             */
/*   Updated: 2022/07/27 08:53:40 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_length(char *dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{	
	int	length_find;
	int	index_str;
	int	index_find;

	length_find = ft_length(to_find);
	index_str = 0;
	index_find = 0;
	while (str[index_str] && index_find < length_find)
	{
		index_find = 0;
		while (str[index_str + index_find] == to_find[index_find]
			&& to_find[index_find])
			index_find++;
		index_str++;
	}
	if (!(to_find[0]))
		return (str);
	if (index_find == length_find)
		return (&str[index_str - 1]);
	return (0);
}
