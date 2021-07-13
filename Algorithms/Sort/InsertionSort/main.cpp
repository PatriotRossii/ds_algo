#include <vector>
#include <algorithm>
#include <iostream>

template<typename T>
void insertionSort(std::vector<T>& vec) {
    for(typename std::vector<T>::iterator i = vec.begin() + 1; i != vec.end(); ++i) {
        T value = *i;
        typename std::vector<T>::iterator j = i - 1;

        while(j >= vec.begin() && *j > value) {
            *(j + 1) = *j;
            --j;
        }

        *(j + 1) = value;
    }
}

int main() {
    std::vector<int> sample = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    insertionSort(sample);

    for(int x: sample) {
        std::cout << x << ", ";
    }
}