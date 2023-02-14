#include <iomanip>
#include <iostream>
#include <string>
#include <limits>
#include <cctype>

#include "../incs/Contact.hpp"
#include "../incs/Phonebook.hpp"

static std::string cut(std::string str)
{
	if (str.size() >= 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

static std::string Get_Str()
{
    std::string str;
	int			good;
	int			i;

	good = 0;
    
    while (good == 0) 
	{	
		good = 1;
		std::getline(std::cin, str);
		if (str.empty())
		{	
			good = 0;
        	std::cout << "Error, empty field: ";
		}
		else if (std::isspace(str[0]))
		{	
			good = 0;
        	std::cout << "Error, can't start with space: ";
		}
		i = 0;
		while (str[i]) 
		{
			if (std::isdigit(str[i])) 
			{
				good = 0;
				std::cout << "Error, can't contain number: ";
				break;
			}
			i++;
    	}
    }
    return str;
}

static bool Is_Number(std::string &str) {
	int i;

	if (std::isspace(str[0]))
	{	
        std::cout << "Error, can't start with space: ";
		return false;
	}

	i = 0;
    while (str[i]) {
        if (!std::isdigit(str[i])) {
            return false;
        }
		i++;
    }
    return true;
}

static std::string Get_Numbers()
{
    std::string str;
	
    std::getline(std::cin, str);
    while (str.empty() || !Is_Number(str)) 
	{
        std::cout << "Error, not a number: ";
        std::getline(std::cin, str);
    }
    return str;
}

static void Add_Contact(Phonebook *phonebook)
{
	Contact 		contact;
	
	std::cout << "First name: ";
	contact.Set_First_Name(Get_Str());
	std::cout << "Last name: ";
	contact.Set_Last_Name(Get_Str());
	std::cout << "Nickname: ";
	contact.Set_Nick_Name(Get_Str());
	std::cout << "Phone number: ";
	contact.Set_Phone_Number(Get_Numbers());
	std::cout << "Darkest secret: ";
	contact.Set_Secret(Get_Str());
	phonebook->Add_Contact(contact);
}

static void Show_All(Phonebook *ph)
{
	Contact 	contact;
	int			i;

	std::cout << "|----------|----------|----------|----------|";
	std::cout << std::endl;
	std::cout << "│" << std::setw(10) << std::right << "index";
	std::cout << "│" << std::setw(10) << std::right << "first name";
	std::cout << "│" << std::setw(10) << std::right << "last name";
	std::cout << "│" << std::setw(10) << std::right << "nickname";
	std::cout << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|";
	std::cout << std::endl;
	for (i=0; i < ph->Get_Nb(); i++)
	{
		contact = ph->Get_Contact(i);
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << cut(contact.Get_First_Name());
		std::cout << "|" << std::setw(10) << cut(contact.Get_Last_Name());
		std::cout << "|" << std::setw(10) << cut(contact.Get_Nick_Name());
		std::cout << "|" << std::endl;
	}
	std::cout << "|----------|----------|----------|----------|";
	std::cout << std::endl;
}

static void Show_Contact(Contact contact)
{
	std::cout << std::endl;
	std::cout << "First name     : " << contact.Get_First_Name() << std::endl;
	std::cout << "Last name      : " << contact.Get_Last_Name() << std::endl;
	std::cout << "Nickname       : " << contact.Get_Nick_Name() << std::endl;
	std::cout << "Phone number   : " << contact.Get_Phone_Number() << std::endl;
	std::cout << "Darkest secret : " << contact.Get_Secret() << std::endl;
}

static void Search_Contact(Phonebook *ph)
{
	Contact 	contact;
	int 		i;

	Show_All(ph);
	if (ph->Get_Nb() > 0)
	{
		std::cout << "Index: ";
		while (!(std::cin >> i) || i > ph->Get_Nb() || i < 1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error, 1 <= index <=" << ph->Get_Nb() << std::endl;
			std::cout << "Index: ";
		}
		contact = ph->Get_Contact(i - 1);
		Show_Contact(contact);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
		std::cout << "No contact" << std::endl;
}

int main(void)
{
	Phonebook 		ph;
	std::string 	cmd;

	std::cout << " -ADD" << std::endl;
	std::cout << " -SEARCH" << std::endl;
	std::cout << " -EXIT" << std::endl;
	
	while (1)
	{
		std::cout << std::endl << "Enter a command: ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			Add_Contact(&ph);
		else if (cmd == "SEARCH")
			Search_Contact(&ph);
		else if (cmd == "EXIT")
			break;
	}
}