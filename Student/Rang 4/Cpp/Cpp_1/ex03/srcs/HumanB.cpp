/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:00:59 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/06 11:09:42 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/HumanB.hpp"

//Constructeur par recopie
HumanB::HumanB(const std::string &name) : name(name), weapon(nullptr)
{
	std::cout << this->name << ": Created" << std::endl;
}

// Destructeur
HumanB::~HumanB()
{
	std::cout << this->name << ": Destroyed" << std::endl;
}

void HumanB::attack() const
{
	if (!this->weapon)
	{
		std::cout << this->name << " has no weapon" << std::endl;
		return ;
	}
	std::cout << this->name << " attacks with " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
