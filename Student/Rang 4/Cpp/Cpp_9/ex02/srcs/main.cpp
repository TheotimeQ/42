#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

int main(int argc, char** argv) {

    (void)argc;
    (void)argv;
    
    int arr[] = {3, 5, 9, 7, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    //Create conteneur 1

    //Create conteneur 2

    //Ligne 1
    cout << "Before: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //Ligne 2
    std::sort(arr, arr + size);
    cout << "After: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // //Ligne 3
    // float stop = chrono::high_resolution_clock::now();
    // //sort using vector 1
    // float start = chrono::high_resolution_clock::now();
    // float duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    // cout << "Time to process a range of " << size << " elements with std::array : " << duration.count() << " us" << endl;

    //Ligne 4
    chrono::microseconds stop = chrono::high_resolution_clock::now();
    //sort using vector 2
    chrono::microseconds start = chrono::high_resolution_clock::now();
    chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time to process a range of " << size << " elements with std::vector : " << duration.count() << " us" << endl;

    return 0;
}


// ./PmergeMe 3 5 9 7 4
// Before: 3 5 9 7 4
// After: 3 4 5 7 9
// Time to process a range of 5 elements with std::[..] : 0.00031 us
// Time to process a range of 5 elements with std::[..] : 0.00014 us




// $> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
// Before: 141 79 526 321 [...]
// After: 79 141 321 526 [...]
// Time to process a range of 3000 elements with std::[..] : 62.14389 us
// Time to process a range of 3000 elements with std::[..] : 69.27212 us
// $> ./PmergeMe "-1" "2"
// Erro