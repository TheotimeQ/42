#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	
	private:

		T* 		_data;
		size_t 	_size;
	
	public:

		Array() : _data(NULL), _size(0)
		{}

		Array(unsigned int size) : _data(new T[size]), _size(size)
		{
			for (size_t i = 0; i < _size; i++)
				_data[i] = T();
		}

		Array(const Array<T>& other) : _data(new T[other._size]), _size(other._size)
		{
			*this = other;
		}

		~Array()
		{
			delete[] _data;
		}

		//Operator
		Array<T>& operator=(const Array<T>& other)
		{
			delete[] _data;
			_data = new T[other._size];
			_size = other._size;
			for (size_t i = 0; i < _size; i++)
				_data[i] = other._data[i];
			return *this;
		}

		T& operator[](size_t idx)
		{
			if (idx >= _size)
				throw OutOfRange();
			if (idx < 0)
				throw OutOfRange();
			return _data[idx];
		}

		//Getter
		size_t size() const
		{
			return _size;
		}

		//Exception
		class OutOfRange : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Out of range";
				}
		};

};

template<typename T>
std::ostream& operator<<(std::ostream& out, Array<T>& a)
{
	for (size_t i = 0; i < a.size(); i++)
		out << a[i] << ' ' ;
	out << std::endl;
	return out;
}

#endif
