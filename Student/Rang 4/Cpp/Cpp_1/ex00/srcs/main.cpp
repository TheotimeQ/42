/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:44:56 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/06 08:35:06 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "../incs/Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	Zombie *Zb_On_Heap = newZombie("Zombie on the heap");
	if (!Zb_On_Heap)
		return (1);
	Zb_On_Heap->announce();
	delete Zb_On_Heap;
	randomChump("Zombie on the stack");
	return (0);
}
