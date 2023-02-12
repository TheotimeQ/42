/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:15:34 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/06 13:03:20 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void replace_in_file(std::ifstream& File_In, std::ofstream& File_Out, const std::string& s1, const std::string& s2)
{
	std::string         str;
	size_t              index;

	while (std::getline(File_In, str))
	{
		index = 0;
		while ((index = str.find(s1, index)) != std::string::npos)
		{
			str.erase(index, s1.size());
			str.insert(index, s2);
			index += s2.length();
		}
		File_Out << str << std::endl;
	}
}

int main(int argc, char **argv)
{
	std::string filename;
    std::string s1;
    std::string s2;

	if (argc < 4)
	{
		std::cout << "Error: wrong input, use : Ex04 filename s1 s2." << std::endl;
		return (1);
	}

	filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];

	std::ifstream File_In(filename);
	if (!File_In.is_open())
	{
		std::cout << "Error: Can't read " << filename << std::endl;
		return (1);
	}
	
	std::ofstream File_Out(filename + ".replace", std::ios::out | std::ios::trunc);
	if (!File_Out.is_open())
	{
		std::cout << "Error: Can't write " << filename + ".replace" << std::endl;
		return (1);
	}

	replace_in_file(File_In, File_Out, s1, s2);
	
	return (0);
}
