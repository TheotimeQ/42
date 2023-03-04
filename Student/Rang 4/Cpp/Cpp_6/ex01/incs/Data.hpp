#ifndef DATA_H
# define DATA_H

#include <string>
#include <stdint.h>
#include <iostream>

class Data
{

	private:

		std::string _str;
		int			_int;
		float 		_float;
		void* 		_void;
		char 		_char;

	public:

		Data(int int_, const std::string& str_, float float_, void *void_, char char_);

		static uintptr_t 	serialize(Data* ptr);
		static Data* 		deserialize(uintptr_t raw);

		int 				Get_int() const;
		std::string 		Get_str() const;
		float 				Get_float() const;
		void*				Get_void() const;
		char		 		Get_char() const;
};

std::ostream& operator<<(std::ostream& out, const Data& data);

#endif
