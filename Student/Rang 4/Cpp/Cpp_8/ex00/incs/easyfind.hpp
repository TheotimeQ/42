#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <vector>

template <typename T>
bool easyfind(const T& container, int val)
{
	return std::find(container.begin(), container.end(), val) != container.end();
}

#endif
