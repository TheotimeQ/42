#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& var_1, T& var_2)
{
	T tmp = var_1;
	var_1 = var_2;
	var_2 = tmp;
}

template <typename T>
T& min(T& var_1, T& var_2)
{
	return (var_1 < var_2) ? var_1 : var_2;
}

template <typename T>
T& max(T& var_1, T& var_2)
{
	return (var_1 > var_2) ? var_1 : var_2;
}

#endif
