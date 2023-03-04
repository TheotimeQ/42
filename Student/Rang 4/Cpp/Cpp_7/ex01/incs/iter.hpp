#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T* array, size_t len, void (*callback)(T&))
{
	for (size_t i = 0; i < len; i++)
		callback(array[i]);
}

#endif // ITER_HPP
