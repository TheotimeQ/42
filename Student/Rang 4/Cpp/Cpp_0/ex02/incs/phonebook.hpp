/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:40:52 by zelinsta          #+#    #+#             */
/*   Updated: 2023/01/30 15:47:45 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP




#endif


//Coplien
// https://cpp.developpez.com/cours/cppavance/


class Phonebook
{
public:

	// Constructors & Destructor
	Phonebook();
	~Phonebook();

	// Getters
	Contact getContact(int index) const;
	int		getCount() const;

	// Setters
	void set_contact(Contact contact);

private:

	static int		_count;

	Contact _contacts[8];
	int		_index;
};