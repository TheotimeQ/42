/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 12:10:05 by tquere            #+#    #+#             */
/*   Updated: 2022/07/24 15:05:02 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int			ft_strlen(char *str);
char		*create_str(int str_len);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
t_dict		split(t_dict dict, char *str);
t_dict		sort_in_dict(t_dict dict, char *value, char *key);

char	*init_str(char *str, int len)
{
	int		index;

	index = 0;
	while (index < len)
	{
		str[index++] = '\0';
	}
	return (str);
}

int	check_key(char *str)
{
	int	index;

	index = 0;
	if (str[index] == 0)
		return (1);
	while (str[index])
	{
		if (!('0' <= str[index] && str[index] <= '9'))
			return (1);
		index++;
	}
	return (0);
}

int	convert_key_to_dec(char *key)
{
	int		index;
	int		dec_index;

	dec_index = 0;
	index = 0;
	while (key[index])
	{	
		dec_index = dec_index * 10 + (key[index] - '0');
		index ++;
	}
	return (dec_index);
}

int	count_zero(char *number)
{
	int	index;

	index = 1;
	while (number[index] == '0')
	{
		index++;
	}
	return (--index);
}

t_dict	split_and_sort(char *str, t_dict dict)
{	
	if (str[0] != '\n')
	{
		dict = split(dict, str);
		if (dict.error == 0)
			dict = sort_in_dict(dict, dict.value, dict.key);
	}
	return (dict);
}
