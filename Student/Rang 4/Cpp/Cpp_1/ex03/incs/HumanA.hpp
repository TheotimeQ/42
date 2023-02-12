/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:00:30 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/06 11:09:49 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include <string>

# include "Weapon.hpp"

class HumanA
{
    private:
    
        std::string     name;
        Weapon&         weapon;

    public:

		// Constructeur de recopie
        HumanA(const std::string& name, Weapon& weapon);
		
		// Destructeur
        ~HumanA();

        void attack() const;

};

#endif