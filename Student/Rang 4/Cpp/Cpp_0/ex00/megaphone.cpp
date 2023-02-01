/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:19:27 by zelinsta          #+#    #+#             */
/*   Updated: 2023/01/30 14:19:36 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int		main(int argc, char **argv)
{
	size_t i;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (--argc)
	{
		argv++;
		i = 0;
		while ((*argv)[i])
		{
			(*argv)[i] = std::toupper((*argv)[i]);
			i++;
		}
		std::cout << *argv;
	}
	std::cout << std::endl;
	return (0);
}