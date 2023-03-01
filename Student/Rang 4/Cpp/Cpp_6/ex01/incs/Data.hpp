#ifndef DATA_H
# define DATA_H

// #include <cstdint>
#include <string>
#include <stdint.h>
#include <iostream>

class Data
{

	private:

		int			_Integer;
		std::string _String;
		float 		_Floating;

	public:

		Data(int integer, const std::string& string, float floating);

		static uintptr_t 	serialize(Data* ptr);
		static Data* 		deserialize(uintptr_t raw);

		int 				integer() const;
		std::string 		string() const;
		float 				floating() const;

		void 				setInteger(int newInteger);
		void 				setString(const std::string& newString);
		void 				setFloating(float newFloating);

};

std::ostream& operator<<(std::ostream& out, const Data& data);

#endif
