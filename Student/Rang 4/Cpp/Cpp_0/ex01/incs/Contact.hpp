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

        Contact();
        Contact(const Contact&);
        Contact &operator=(const Contact&);
        ~Contact(); 

		std::string Get_First_Name() 	const;
		std::string Get_Last_Name() 	const;
		std::string Get_Nick_Name() 	const;
		std::string	Get_Phone_Number() 	const;
		std::string Get_Secret() 		const;
		
		void Set_First_Name(std::string str);
		void Set_Last_Name(std::string str);
		void Set_Nick_Name(std::string str);
		void Set_Phone_Number(std::string str);
		void Set_Secret(std::string str);

};

#endif
