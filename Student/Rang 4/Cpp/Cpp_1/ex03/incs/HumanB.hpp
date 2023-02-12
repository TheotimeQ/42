/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:00:27 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/06 11:09:53 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include <iostream>
# include <string>

# include "Weapon.hpp"

class HumanB
{
    private:

        std::string     name;
        Weapon          *weapon;

    public:

		// Constructeur de recopie
        HumanB(const std::string &name);
		
		// Destructeur
        ~HumanB();

        void attack() const;
        void setWeapon(Weapon& weapon);

};

#endif
