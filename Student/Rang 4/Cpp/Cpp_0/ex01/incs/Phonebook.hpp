/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:40:52 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/02 08:19:14 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "../incs/Contact.hpp"

class Phonebook
{

	private :
	
		Contact 	cts[8];
		int			index;
		int			nb;

    public:

		// Constructeur par défaut
        Phonebook(); 

		// Constructeur de recopie
        // Phonebook(const Contact&); 

		// Destructeur
        ~Phonebook(); 

		// Operator d'affectation
        // Phonebook &operator=(const Phonebook&);

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
