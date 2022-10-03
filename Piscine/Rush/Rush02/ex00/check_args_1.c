/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:24:42 by aphilibe          #+#    #+#             */
/*   Updated: 2022/07/23 18:24:56 by aphilibe         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_input		ft_validarg(t_input input, int argsize, int argc, char **argv);

t_input	check_args(int argc, char **argv)
{
	t_input	input;
	int		argsize;

	argsize = 0;
	input.error = 0;
	input.value = "0";
	if (argc == 1 || argc >= 4)
	{
		input.value = "0";
		input.file = "numbers.dict.txt";
		if (argc == 1)
			input.error = 2;
		else
			input.error = 1;
		return (input);
	}
	else
		input = ft_validarg(input, argsize, argc, argv);
	return (input);
}
