#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#define ERROR 1
#define GOOD  0

template <typename T>
bool check_double(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		return ERROR;
    return GOOD;
}

bool check_valid_number(int value)
{
    if (value < 0)
		return ERROR;
    return GOOD;
}

bool check_nan(int value, char *str)
{
    if (value == 0 && str[0] != '0')
		return ERROR;
    return GOOD  ;
}

template <typename T>
bool create_container(T &container, int argc, char** argv)
{
    for (int index = 1; index < argc; ++index)
	{
        int value = atoi(argv[index]);

        if (check_double(container, value)){
			std::cout << "Error: " << value << " -> double" << std::endl;
            return ERROR;
        }

        if (check_valid_number(value)){
			std::cout << "Error: " << value << " -> not valid ( < 0 )" << std::endl;
            return ERROR;
        }

        if (check_nan(value, argv[index])){
			std::cout << "Error: " << argv[index] << " -> not valid ( nan )" << std::endl;
            return ERROR;
        }
        container.push_back(value); 
	}
    return GOOD;
}

template <typename T>
void print_container(T &container)
{
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); ++it)
		std::cout << *it << ' ' ;
}

template <typename T>
T advance(T it , size_t distance)
{
    for (size_t i = 0; i < distance; ++i) 
        ++it;
    return it;
}

template <typename T>
void insertion_sort(T& container)
{
    typename T::iterator iter_i, iter_j, it_j_1;

    for (iter_i = container.begin()++; iter_i != container.end(); ++iter_i) {
        int key = *iter_i;
        iter_j = iter_i;
        it_j_1 = iter_j;
        it_j_1--;

        while (iter_j != container.begin() && *(it_j_1) > key) {
            *iter_j = *(it_j_1);
            --iter_j;
            it_j_1 = iter_j;
            it_j_1--;
        }
        if (key < *iter_j) {
            *iter_j = key;
        }
    }
}

template <typename T>
void merge_insert_sort(T& container)
{
    size_t container_size = container.size();
    size_t limit_size = (int)((int)container.size() / 70) + 1;

    if (container_size <= limit_size)
    {
        insertion_sort(container);
        return;
    }

    size_t mid = container_size / 2;
    T left(container.begin(), advance(container.begin(), mid));
    T right(advance(container.begin(), mid), container.end());

    merge_insert_sort(left);
    merge_insert_sort(right);

    typename T::iterator left_it = left.begin();
    typename T::iterator right_it = right.begin();
    typename T::iterator container_it = container.begin();

    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it < *right_it) {
            *container_it = *left_it;
            ++left_it;
        } else {
            *container_it = *right_it;
            ++right_it;
        }
        ++container_it;
    }

    container_it = std::copy(left_it, left.end(), container_it);
    std::copy(right_it, right.end(), container_it);
}

#endif
