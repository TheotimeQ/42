#ifndef SPAN_H
# define SPAN_H

# include <algorithm>

class Span
{

	private:

		size_t 	_size;
		size_t 	_index;
		int* 	_data;

	public:

		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void 			addNumber(int value);
		unsigned int 	shortestSpan() const;
		unsigned int 	longestSpan() const;


		template <typename It>
		void addNumbers(It first, It last)
		{
			while (first != last)
			{
				addNumber(*first);
				first++;
			}
		}

		class Full : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Container Full";
				}
		};

		class NotEnough : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Not enough number";
				}
		};
};

#endif
