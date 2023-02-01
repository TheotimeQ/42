/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:42:54 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/01 14:40:08 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{

	private :
		
		std::string First_Name;
		std::string Last_Name;
		std::string Nick_Name;
		std::string	Phone_Number;
		std::string	Secret;

    public:

		// Constructeur par défaut
        Contact(); 

		// Constructeur de recopie
        // Contact(const Contact&); 

		// Destructeur
        ~Contact(); 

		// Operator d'affectation
        // Contact &operator=(const Contact&);

		// Gets
		std::string Get_First_Name() 	const;
		std::string Get_Last_Name() 	const;
		std::string Get_Nick_Name() 	const;
		std::string	Get_Phone_Number() 	const;
		std::string Get_Secret() 		const;
		
		// Set 
		void Set_First_Name(std::string str);
		void Set_Last_Name(std::string str);
		void Set_Nick_Name(std::string str);
		void Set_Phone_Number(std::string str);
		void Set_Secret(std::string str);

};

#endif
