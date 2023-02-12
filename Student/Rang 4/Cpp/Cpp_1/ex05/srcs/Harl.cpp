/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:04:04 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/06 13:24:08 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.hpp"

typedef void (Harl::*Function)(void) const;

Harl::Harl()
{
	std::cout << "Created" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Destroyed" << std::endl;
}

void Harl::complain(const std::string &level) const
{
	std::string     All_Level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Function     All_Function[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
	for (int i = 0; i < 4; i++)
    {
		if (All_Level[i] == level)
        {
            (this->*(All_Function[i]))();
        }
    }
}

void Harl::debug() const
{
	std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() const
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() const
{
	std::cout << "think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() const
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
