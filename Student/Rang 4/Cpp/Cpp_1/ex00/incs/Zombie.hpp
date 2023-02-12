/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:42:54 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/06 08:24:33 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string name;
		
	public:

		// Constructeur par défaut
        Zombie();

		// Constructeur de recopie
		Zombie(const std::string& name);
		
		// Destructeur
		~Zombie();

		void announce(void) const;
};

#endif
