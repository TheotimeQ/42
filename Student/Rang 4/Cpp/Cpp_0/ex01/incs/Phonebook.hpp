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

        Phonebook(); 
        Phonebook(const Phonebook&);
        Phonebook &operator=(const Phonebook&);
        ~Phonebook(); 

		Contact Get_Contact(int index) const;

		int	Get_Nb(void) const;
		void	Del_Contact(int index);
		void	Add_Contact(Contact Ct);

};

#endif
