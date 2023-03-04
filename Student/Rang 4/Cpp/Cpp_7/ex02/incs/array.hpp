#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
public:
	Array() :
		_data(NULL),
		_size(0)
	{}

	Array(unsigned int size) :
		_data(new T[size]),
		_size(size)
	{
		for (size_t i = 0; i < _size; i++)
			_data[i] = T();
	}

	Array(const Array<T>& other) :
		_data(new T[other._size]),
		_size(other._size)
	{
		for (size_t i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}

	~Array()
	{
		delete[] _data;
	}

	size_t size() const
	{
		return _size;
	}

	class OutOfRange : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "Out of range";
		}
	};

	T& operator[](size_t idx)
	{
		if (idx >= _size)
			throw OutOfRange();
		return _data[idx];
	}

	Array<T>& operator=(const Array<T>& other)
	{
		delete[] _data;
		_data = new T[other._size];
		_size = other._size;
		for (size_t i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}

private:
	T* _data;
	size_t _size;
};

#endif // ARRAY_HPP
