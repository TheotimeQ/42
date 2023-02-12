/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:07:41 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/06 08:41:09 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *Zbs = new Zombie[N];
	for (int i = 0; i < N; i++)
		Zbs[i].Set_Name(name);
	return (Zbs);
}

