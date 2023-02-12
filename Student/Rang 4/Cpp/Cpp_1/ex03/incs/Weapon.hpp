/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:00:33 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/06 09:06:56 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>
# include <iostream>

class Weapon
{
    private:
    
        std::string type;
        
    public:

		// Constructeur par défaut
        Weapon();

		// Constructeur de recopie
		Weapon(const std::string &name);
		
		// Destructeur
		~Weapon();

        const std::string& getType() const;
        void setType(const std::string &type);

};

#endif
