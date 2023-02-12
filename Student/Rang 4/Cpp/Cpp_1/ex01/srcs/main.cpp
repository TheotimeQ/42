/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:44:56 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/06 08:37:48 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "../incs/Zombie.hpp"

#define Horde_Size 5

Zombie* zombieHorde(int N, std::string name);

int main()
{
	Zombie* Zbs = zombieHorde(Horde_Size, "For the Hordeeeee");
	for (int i = 0; i < Horde_Size; i++)
		Zbs[i].announce();
	delete[] Zbs;
	return (0);
}
