#include "../incs/span.hpp"

Span::Span(unsigned int N) :
	_size(N),
	_currIdx(0),
	_data(new int[N])
{
	for (size_t i = 0; i < _size; i++)
		_data[i] = 0;
}

Span::Span(const Span& other) :
	_size(other._size),
	_currIdx(other._currIdx),
	_data(new int[other._size])
{
	for (size_t i = 0; i < _size; i++)
		_data[i] = other._data[i];
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
	_data = new int[_size];
	_currIdx = other._currIdx;
	for (size_t i = 0; i < _size; i++)
		_data[i] = other._data[i];
	return *this;
}

void Span::addNumber(int value)
{
	if (_currIdx >= _size)
		throw OutOfRange();
	_data[_currIdx] = value;
	_currIdx++;
}

unsigned int Span::shortestSpan() const
{
	if (_currIdx < 2)
		throw TooSmall();

	int* _cpy = new int[_currIdx];
	for (size_t i = 0; i < _currIdx; i++)
		_cpy[i] = _data[i];

	std::sort(_cpy, _cpy + _currIdx);
	for (size_t i = 0; i < _currIdx - 1; i++)
		_cpy[i] = _cpy[i + 1] - _cpy[i];

	delete[] _cpy;
	return *std::min_element(_cpy, _cpy + _currIdx - 1);
}

unsigned int Span::longestSpan() const
{
	if (_currIdx < 2)
		throw TooSmall();

	int64_t min = *std::min_element(_data, _data + _currIdx);
	int64_t max = *std::max_element(_data, _data + _currIdx);
	return max - min;
}


