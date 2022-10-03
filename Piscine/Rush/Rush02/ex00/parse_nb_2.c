/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nb_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:37:16 by tquere            #+#    #+#             */
/*   Updated: 2022/07/23 17:37:17 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	ft_putstr(char *str, int output);
int		ft_strlen(char *str);

int	check_dict(char *dict_value)
{
	if (dict_value[0] == '\0')
		return (1);
	return (0);
}

int	prt_err(int mode, char *str, t_parsing parsing)
{	
	if (mode == 0)
		return (check_dict(str));
	else
	{	
		ft_putstr(str, 1);
		if (parsing.index_left < parsing.len_nb - 1)
			ft_putstr(" ", 1);
	}
	return (0);
}

t_parsing	hundred(int mode, t_dict dict, t_input input, t_parsing parsing)
{	
	int		digit_value;

	if (parsing.index_right % 3 == 0 && parsing.index_left < parsing.len_nb)
	{	
		if (input.value[parsing.index_left] != '0')
		{
			digit_value = input.value[parsing.index_left] - '0';
			if (prt_err(mode, dict.zero_twenty[digit_value], parsing))
				parsing.error = 1;
			if (prt_err(mode, dict.ten_power[0], parsing))
				parsing.error = 1;
		}
		parsing.index_left++;
		parsing.index_right--;
	}
	return (parsing);
}

t_parsing	two_unit(int mode, t_dict dict, t_input input, t_parsing parsing)
{	
	int		digit_value;

	digit_value = input.value[parsing.index_left] - '0';
	if (prt_err(mode, dict.twenty_hundred[digit_value - 2], parsing))
		parsing.error = 1;
	parsing.index_left++;
	parsing.index_right--;
	if (input.value[parsing.index_left] >= '1')
	{
		digit_value = input.value[parsing.index_left] - '0';
		if (prt_err(mode, dict.zero_twenty[digit_value], parsing))
			parsing.error = 1;
		parsing.index_left++;
		parsing.index_right--;
	}
	return (parsing);
}

t_parsing	unit(int mode, t_dict dict, t_input input, t_parsing parsing)
{	
	int		digit_value;

	digit_value = input.value[parsing.index_left] - '0';
	parsing.index_left++;
	parsing.index_right--;
	digit_value = digit_value * 10 + input.value[parsing.index_left] - '0';
	if (prt_err(mode, dict.zero_twenty[digit_value], parsing))
		parsing.error = 1;
	parsing.index_left++;
	parsing.index_right--;
	return (parsing);
}
