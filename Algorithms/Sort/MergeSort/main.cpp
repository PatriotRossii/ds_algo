#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>

#include <iostream>

template<typename T>
void merge(T array[], size_t left_size, size_t right_size, size_t size) {
    size_t lidx = 0, ridx = left_size, idx = 0;
    T* tmp_array = new T[size];

    while(lidx < left_size || ridx < size) {
        tmp_array[idx++] = std::move(array[array[lidx] < array[ridx] ? lidx++ : ridx++]);
        if(lidx == left_size) {
            std::copy(
                std::make_move_iterator(&array[ridx]),
                std::make_move_iterator(&array[size]),
                &tmp_array[idx]
            );
            break;
        }
        if(ridx == size) {
            std::copy(
                std::make_move_iterator(&array[lidx]),
                std::make_move_iterator(&array[left_size]),
                &tmp_array[idx]
            );
            break;
        }
    }

    std::copy(
        std::make_move_iterator(tmp_array),
        std::make_move_iterator(&tmp_array[size]),
        array
    );
    delete[] tmp_array;
}

template<typename T>
void merge_sort(T array[], size_t size) {
    if(size > 1) {
        const size_t left_size = size / 2;
        const size_t right_size = size - left_size;

        merge_sort(&array[0], left_size);
        merge_sort(&array[left_size], right_size);
        merge(array, left_size, right_size, size);
    }
}

int main() {
    int sample[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(sample, 9);

    for(int x: sample) {
        std::cout << x << ", ";
    }
}