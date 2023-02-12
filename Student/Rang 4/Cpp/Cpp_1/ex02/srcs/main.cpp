/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:47:52 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/06 08:55:27 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;
    std::cout << std::endl;
    
	std::cout << "Address string      : " << &string << std::endl;
	std::cout << "Adress in stringPTR : " << stringPTR << std::endl;
	std::cout << "Adress in stringREF : " << &stringREF << std::endl;
    std::cout << std::endl;

	std::cout << "Value of string            : " << string << std::endl;
	std::cout << "Value pointed by stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF : " << stringREF << std::endl;
    std::cout << std::endl;
}

