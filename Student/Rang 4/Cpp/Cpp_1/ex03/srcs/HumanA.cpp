/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:01:02 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/06 11:09:38 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/HumanA.hpp"

//Constructeur par recopie
HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << this->name << ": Created" << std::endl;
}

//Destructeur
HumanA::~HumanA()
{
	std::cout << this->name << ": Destroyed" << std::endl;
}

void HumanA::attack() const
{
	std::cout << this->name << " attacks with " << this->weapon.getType() << std::endl;
}
