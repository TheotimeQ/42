/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:40:52 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/03 09:56:31 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "../incs/Contact.hpp"

#define MAX_CTS 8

class Phonebook
{

	private :
	
		Contact 	cts[MAX_CTS];
		int			index;
		int			nb;

    public:

		// Constructeur par défaut
        Phonebook(); 

		// Constructeur de recopie
        Phonebook(const Phonebook&);

		// Operator d'affectation
        Phonebook &operator=(const Phonebook&);
		
		// Destructeur
        ~Phonebook(); 

		// Get contact
		Contact Get_Contact(int index) const; // Const car la fonction ne doit pas modifier le Phonebook

		// Get Nb contact
		int	Get_Nb(void) const;

		// Delete contact
		void	Del_Contact(int index);

		// Add contact
		void	Add_Contact(Contact Ct);

};

#endif
