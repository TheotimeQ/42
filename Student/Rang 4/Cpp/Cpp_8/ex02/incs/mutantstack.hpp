#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
		MutantStack() {}

		MutantStack(const MutantStack<T> &src)
		{
			*this = src;
		}

		MutantStack<T> &operator=(const MutantStack<T> &other)
		{
			if (this == &other)
				return *this;

			this->c = other.c;

			return *this;
		}

		~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}
};

#endif
