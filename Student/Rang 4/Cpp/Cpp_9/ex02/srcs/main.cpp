#include <iostream>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>

#include <vector>
#include <list>

#include "../incs/PmergeMe.hpp"

int main(int argc, char** argv) 
{
    std::list<int>      list;
    std::vector<int>    vector;

    clock_t             start_time ;
    clock_t             end_time;

    if (create_container(list, argc, argv) || create_container(vector, argc, argv) == ERROR)
        return ERROR;

    std::cout << "Before:  ";
    print_container(vector);
    std::cout << std::endl;

    start_time = clock();
    merge_insert_sort(list);
    end_time = clock();
    double time_list = double(end_time - start_time) / CLOCKS_PER_SEC;

    start_time = clock();
    merge_insert_sort(vector);
    end_time = clock();
    double time_vector = double(end_time - start_time) / CLOCKS_PER_SEC;

    std::cout << "After:   ";
    print_container(vector);
    std::cout << std::endl;

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << std::setprecision(8) << time_vector << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list   : " << std::setprecision(8) << time_list   << " us" << std::endl;

    return GOOD;
}