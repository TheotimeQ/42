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


// Conteneur utilisés:

//Ex00 Bitcoin Exchange :
//			- Queu

//Ex01 Reverse Polish Notation :
//			- Stack

//Ex02 PmergeMe :
//			- Array / vector

// Array
// Vector
// Deque
// List
// Stack
// Queue
// Priority Queue
// Set
// Multiset
// Map
// Multimap