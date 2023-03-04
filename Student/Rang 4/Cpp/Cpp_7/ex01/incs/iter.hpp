#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T* tab, size_t size, void (*func)(T&))
{
	for (size_t i = 0; i < size; i++)
		func(tab[i]);
}

template <typename T>
void print(T& value)
{
	std::cout << value << std::endl;
}

#endif
