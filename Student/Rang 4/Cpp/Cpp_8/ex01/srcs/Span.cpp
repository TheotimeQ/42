#include "../incs/Span.hpp"

Span::Span(unsigned int N) :
	_size(N),
	_index(0),
	_data(new int[N])
{
	for (size_t i = 0; i < _size; i++)
		_data[i] = 0;
}

Span::Span(const Span& other) :
	_size(other._size),
	_index(other._index),
	_data(new int[other._size])
{
	*this = other;
}

Span::~Span()
{
	delete[] _data;
}

Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return *this;

	delete[] _data;
	
	_size = other._size;
	_index = other._index;
	_data = new int[_size];

	for (size_t i = 0; i < _size; i++)
		_data[i] = other._data[i];

	return *this;
}

void Span::addNumber(int value)
{
	if (_index >= _size)
		throw Full();
		
	_data[_index] = value;
	_index++;
}

unsigned int Span::shortestSpan() const
{
	if (_index < 2)
		throw NotEnough();

	int* Cpy = new int[_index];

	std::copy(_data, _data + _index, Cpy);
	std::sort(Cpy, Cpy + _index);

	for (size_t i = 0; i < _index - 1; i++)
		Cpy[i] = Cpy[i + 1] - Cpy[i];

	int ret = *std::min_element(Cpy, Cpy + _index - 1);

	delete[] Cpy;
	return ret;
}

unsigned int Span::longestSpan() const
{
	if (_index < 2)
		throw NotEnough();

	int64_t min = *std::min_element(_data, _data + _index);
	int64_t max = *std::max_element(_data, _data + _index);
	return max - min;
}