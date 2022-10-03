/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:54:34 by tquere            #+#    #+#             */
/*   Updated: 2022/07/24 21:54:35 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>

int			ft_strlen(char *str);
char		*ft_strcpy(char *dest, char *src);

long long unsigned int	convert_key_to_dec_long(char *key)
{
	int							index;
	long long unsigned int		dec_index;

	dec_index = 0;
	index = 0;
	while (key[index])
	{	
		dec_index = dec_index * 10 + (key[index] - '0');
		index ++;
	}
	return (dec_index);
}

t_input	check_nb_long(t_input input)
{	
	long long unsigned int		nb_long;

	if (ft_strlen(input.value) > 10)
	{
		input.error = 1;
		return (input);
	}
	nb_long = convert_key_to_dec_long(input.value);
	if (nb_long > 4294967295)
	{
		input.error = 1;
		return (input);
	}
	return (input);
}

t_input	check_zero(t_input input, char *str)
{	
	int			index;
	int			start;
	int			end;

	index = 0;
	while ('0' == str[index])
	{	
		index++;
	}
	start = index;
	while (str[index])
	{	
		index++;
	}
	end = index;
	index = start;
	input.value = malloc(sizeof(char) * end - start + 1);
	while (index < end)
	{
		input.value[index - start] = str[index];
		index++;
	}
	input = check_nb_long(input);
	return (input);
}

t_input	check_nb(t_input input, char *str)
{
	int			index;

	index = 0;
	while (str[index])
	{	
		if (!('0' <= str[index] && str[index] <= '9'))
		{
			input.error = 1;
			return (input);
		}
		index++;
	}
	input = check_zero(input, str);
	return (input);
}

t_input	ft_validarg(t_input input, int argsize, int argc, char **argv)
{	
	if (argc == 2)
	{
		input.file = "numbers.dict.txt";
		argsize = ft_strlen(argv[1]);
		if (argv[1][0] == '0' && argsize == 1)
			input.value = "0";
		else
			input = check_nb(input, argv[1]);
	}
	else
	{
		input.file = argv[1];
		if (argv[2][0] == '0' && argsize == 1)
			input.value = "0";
		else
			input = check_nb(input, argv[2]);
	}
	return (input);
}
