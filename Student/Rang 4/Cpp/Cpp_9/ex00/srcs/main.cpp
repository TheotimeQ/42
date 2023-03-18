#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>
#include <iomanip>

bool is_date_valid(const std::string &str)
{
	if (str.length() != 10){
		return 0;
	}
	if (str.find_first_not_of("0123456789") != 4){
		return 0;
	}
	if (str.find_last_not_of("0123456789") != 7){
		return 0;
	}
	return 1;
}

double get_value_from_data(std::map<std::string, double>& data, std::string &str)
{	
	int Year_Data;
	int	Month_Data;
	int	Day_Data;
	
	int Year_File = std::atof(str.substr(0).c_str());
	int	Month_File = std::atof(str.substr(5).c_str());
	int	Day_File = std::atof(str.substr(8).c_str());

	std::map<std::string, double>::const_iterator it;
    for (it = data.begin(); it != data.end(); ++it) {

		Year_Data = std::atof(it->first.substr(0).c_str());
		Month_Data = std::atof(it->first.substr(5).c_str());
		Day_Data = std::atof(it->first.substr(8).c_str());
		if (Year_Data >= Year_File && Month_Data >= Month_File && Day_Data >= Day_File){	
			break;
		}
    }
	return it->second;
}

void read_data(std::map<std::string, double>& data){
	
    std::ifstream input_file("data.csv");
    if (!input_file.is_open()) {
        std::cerr << "Unable to open data.csv file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(input_file, line);
    while (std::getline(input_file, line)) {
        std::string 	date_str;
        double 			exchange_rate;
        std::size_t 	comma_pos = line.find(",");

        if (comma_pos == std::string::npos) {
            continue;
        }

        date_str = line.substr(0, comma_pos);
		if (!is_date_valid(date_str)){
			continue;
		}

        exchange_rate = std::atof(line.substr(comma_pos + 1).c_str());
        data[date_str] = exchange_rate;
    }
    
    input_file.close();
}

void read_input(std::map<std::string, double>& data, char *file_name){

	std::ifstream input_file(file_name);
    if (!input_file.is_open()) {
        std::cerr << "Unable to open " << file_name << " file." << std::endl;
        return;
    }
    std::string line;
	std::getline(input_file, line);
    while (std::getline(input_file, line))
	{
        std::string 	date_str;
        double 			value;
        std::size_t 	comma_pos = line.find("|");
		double			exchange_rate;

        if (comma_pos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        date_str = line.substr(0, comma_pos - 1);
		if (!is_date_valid(date_str)){
			std::cout << "Error: wrong date input" << std::endl;
			continue;
		}
			
        value = std::atof(line.substr(comma_pos + 2).c_str());
		exchange_rate = get_value_from_data(data, date_str);

		if (value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (value > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
			std::cout << date_str << " => " << value << " => " << exchange_rate * value <<std::endl;
    }
    input_file.close();	
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_name>" <<  std::endl;
        return 1;
    }
    std::map<std::string, double> data;
    read_data(data);
	read_input(data, argv[1]);
    return 0;
}
