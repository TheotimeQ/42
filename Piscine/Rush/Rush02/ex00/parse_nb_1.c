/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nb_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:37:09 by tquere            #+#    #+#             */
/*   Updated: 2022/07/23 17:37:10 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void		ft_putstr(char *str, int output);
int			ft_strlen(char *str);
int			check_dict(char *dict_value);
int			prt_err(int mode, char *str, t_parsing parsing);
t_parsing	hundred(int mode, t_dict dict, t_input input, t_parsing parsing);
t_parsing	two_unit(int mode, t_dict dict, t_input input, t_parsing parsing);
t_parsing	unit(int mode, t_dict dict, t_input input, t_parsing parsing);

t_parsing	ten(int mode, t_dict dict, t_input input, t_parsing parsing)
{	
	if (parsing.index_right % 3 == 2)
	{
		if (input.value[parsing.index_left] != '0')
		{
			if (input.value[parsing.index_left] >= '2')
				parsing = two_unit(mode, dict, input, parsing);
			else
				parsing = unit(mode, dict, input, parsing);
			if (parsing.ten_power > 0)
			{	
				if (dict.max_power < parsing.ten_power)
					parsing.error = 1;
				if (prt_err(mode, dict.ten_power[parsing.ten_power], parsing))
					parsing.error = 1;
			}
			parsing.ten_power--;
		}
		else
		{
			parsing.index_left++;
			parsing.index_right--;
		}
	}
	return (parsing);
}

t_parsing	ten_power(int mode, t_dict dict, t_input input, t_parsing parsing)
{	
	int		digit_value;

	if (parsing.index_right % 3 == 1 && parsing.index_left < parsing.len_nb)
	{	
		if (parsing.ten_power > dict.max_power)
			parsing.error = 1;
		if (input.value[parsing.index_left] != '0')
		{	
			digit_value = input.value[parsing.index_left] - '0';
			if (prt_err(mode, dict.zero_twenty[digit_value], parsing))
				parsing.error = 1;
		}
		if (parsing.ten_power > 0 && input.value[parsing.index_left] != '0')
		{	
			if (prt_err(mode, dict.ten_power[parsing.ten_power], parsing))
				parsing.error = 1;
		}
		parsing.index_left++;
		parsing.index_right--;
		parsing.ten_power--;
	}
	mode = 1;
	return (parsing);
}

t_parsing	parse_nb(int mode, t_dict dict, t_input input)
{
	t_parsing	parsing;

	parsing.len_nb = ft_strlen(input.value);
	parsing.index_left = 0;
	parsing.index_right = parsing.len_nb;
	parsing.ten_power = (parsing.len_nb - 1) / 3 ;
	parsing.error = 0;
	if (input.value[0] == '0')
	{
		if (prt_err(mode, dict.zero_twenty[0], parsing))
			parsing.error = 1;
	}
	parsing.index_left = 0;
	while (parsing.index_right > 0)
	{	
		parsing = hundred(mode, dict, input, parsing);
		parsing = ten(mode, dict, input, parsing);
		parsing = ten_power(mode, dict, input, parsing);
	}
	return (parsing);
}
