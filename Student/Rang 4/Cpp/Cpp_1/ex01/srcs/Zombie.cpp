/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:07:58 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/06 08:44:42 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

//Constructeur par default 
Zombie::Zombie()
{

}

//Constructeur par recopie
Zombie::Zombie(const std::string &name) : name(name)
{
	std::cout << this->name << ": Created" << std::endl;
}

//Destructeur par default
Zombie::~Zombie()
{
	std::cout << this->name << ": Destroyed" << std::endl;
}

void Zombie::announce() const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::Set_Name(const std::string &name)
{
	this->name = name;
}
