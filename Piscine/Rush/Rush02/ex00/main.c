/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:37:38 by tquere            #+#    #+#             */
/*   Updated: 2022/07/24 21:54:28 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void			ft_putstr(char *str, int output);
t_parsing		parse_nb(int mode, t_dict dict, t_input input);
t_input			check_args(int argc, char **argv);
t_dict			read_dict(t_input input);

t_parsing	print_nb(t_dict dict, t_input input)
{
	t_parsing		parsing;

	parsing = parse_nb(0, dict, input);
	if (parsing.error)
	{
		ft_putstr("Dict Error\n", 1);
		return (parsing);
	}
	parsing = parse_nb(1, dict, input);
	ft_putstr("\n", 1);
	return (parsing);
}

int	main(int argc, char **argv)
{	
	t_input			input;
	t_dict			dict;

	input = check_args(argc, argv);
	if (input.error == 1)
	{
		ft_putstr("Error\n", 1);
		return (0);
	}
	dict = read_dict(input);
	if (dict.error == 1)
	{
		ft_putstr("Dict Error\n", 1);
		return (0);
	}
	if (input.error == 2)
	{
		return (0);
	}
	print_nb(dict, input);
	return (0);
}
