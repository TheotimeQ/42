/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dict_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:56:46 by tquere            #+#    #+#             */
/*   Updated: 2022/07/24 21:56:48 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int		ft_strlen(char *str);
char	*create_str(int str_len);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		check_key(char *str);
int		convert_key_to_dec(char *key);
int		count_zero(char *number);

t_dict	sort_exepct(t_dict dict, char *value, char *key)
{	
	int		len_value;
	int		len_key;
	int		index;
	char	*value_char;

	index = 0;
	len_value = ft_strlen(value);
	len_key = ft_strlen(key);
	if ((len_key == 1) || (len_key == 2 && key[0] == '1'))
	{
		index = convert_key_to_dec(key);
		value_char = create_str(len_value + 1);
		value_char = ft_strncpy(value_char, value, len_value);
		dict.zero_twenty[index] = value_char;
	}
	return (dict);
}

t_dict	sort_ten(t_dict dict, char *value, char *key)
{
	int		len_value;
	int		len_key;
	int		index;
	char	*value_char;

	index = 0;
	len_value = ft_strlen(value);
	len_key = ft_strlen(key);
	if (len_key == 2 && key[1] == '0' && key[0] >= '1')
	{	
		index = convert_key_to_dec(key);
		value_char = create_str(len_value + 1);
		value_char = ft_strncpy(value_char, value, len_value);
		dict.twenty_hundred[index / 10 - 2] = value_char;
	}
	return (dict);
}

t_dict	sort_power(t_dict dict, char *value, char *key)
{	
	int		len_value;
	int		len_key;
	int		index;
	char	*value_char;

	index = 0;
	len_value = ft_strlen(value);
	len_key = ft_strlen(key);
	if (len_key > 2 && key[0] == '1')
	{	
		index = count_zero(key);
		value_char = create_str(len_value + 1);
		value_char = ft_strncpy(value_char, value, len_value);
		if (len_key >= 2 && index % 3 == 0 && index / 3 < 13)
		{
			if (index / 3 > dict.max_power)
				dict.max_power = index / 3;
			dict.ten_power[index / 3] = value_char;
		}
		if (len_key == 3 && index == 2)
		{	
			dict.ten_power[0] = value_char;
		}
	}
	return (dict);
}

t_dict	sort_in_dict(t_dict dict, char *value, char *key)
{
	int		len_value;
	int		len_key;
	int		index;

	index = 0;
	len_value = ft_strlen(value);
	len_key = ft_strlen(key);
	if (check_key(key))
	{
		dict.error = 1;
		return (dict);
	}
	dict = sort_exepct(dict, value, key);
	dict = sort_ten(dict, value, key);
	dict = sort_power(dict, value, key);
	return (dict);
}
