/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:44:56 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/01 16:35:10 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// std::string truncate(std::string str)
// {
// 	if (str.size() >= 10)
// 		return (str.substr(0, 9) + ".");
// 	return (str);
// }

#include <iostream>

#include "../incs/contact.hpp"
#include "../incs/phonebook.hpp"

void Add_Contact(Phonebook *phonebook)
{
	Contact 		contact;
	std::string 	str;

	std::cout << "First name: ";
	std::getline(std::cin, str);
	contact.Set_First_Name(str);
	std::cout << "Last name: ";
	std::getline(std::cin, str);
	contact.Set_Last_Name(str);
	std::cout << "Nickname: ";
	std::getline(std::cin, str);
	contact.Set_Nick_Name(str);
	std::cout << "Phone number: ";
	std::getline(std::cin, str);
	contact.Set_Phone_Number(str);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, str);
	contact.Set_Secret(str);
	phonebook->Add_Contact(contact);
}

void Search_Contact(Phonebook *ph)
{
	int index;
	int count;

	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│" << std::setw(10) << std::right << "index";
	std::cout << "│" << std::setw(10) << std::right << "first name";
	std::cout << "│" << std::setw(10) << std::right << "last name";
	std::cout << "│" << std::setw(10) << std::right << "nickname" << "│" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	for (int i=0; i < ph->nb; i++)
	{
		Contact contact;
		contact = ph->Get_Contact(i);
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << truncate(contact.getFirstName());
		std::cout << "|" << std::setw(10) << truncate(contact.getLastName());
		std::cout << "|" << std::setw(10) << truncate(contact.getNickName()) << "|" << std::endl;
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
	if (ph->nb > 0)
	{
		// std::cout << "Please enter an index for relevant information: ";
		// while (!(std::cin >> index) || index > count || index < 1)
		// {
		// 	std::cin.clear();
		// 	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// 	std::cout << "Invalid input. Please enter an index between 1 and " << count << ": ";
		// }
		// index--;
		Contact 	tmp;
		tmp = ph->Get_Contact(0);
		std::cout << std::endl;
		std::cout << "First name - " << tmp.Get_First_Name() << std::endl;
		std::cout << "Last name - " << tmp.Get_Last_Name() << std::endl;
		std::cout << "Nickname - " << tmp.Get_Nick_Name() << std::endl;
		std::cout << "Phone number - " << tmp.getPhoneNumber() << std::endl;
		std::cout << "Darkest secret - " << tmp.Get_Secret() << std::endl;
	}
	else
	{
		std::cout << "Table is empty!" << std::endl;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main(void)
{
	Phonebook 		ph;
	std::string 	cmd;

	std::cout << "Command info: " << std::endl;
	std::cout << " -ADD: add a contact to the phonebook" << std::endl;
	std::cout << " -SEARCH: search for a contact in the phonebook" << std::endl;
	std::cout << " -EXIT: quit the program" << std::endl;
	
	while (1)
	{
		std::cout << std::endl << "Enter a command: ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			Add_Contact(&ph);
		}
		else if (cmd == "SEARCH")
		{
			Search_Contact(&ph);
		}
		else if (cmd == "EXIT" || cmd == "")
		{
			break;
		}
	}
}