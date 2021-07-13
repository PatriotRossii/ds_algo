#include <vector>
#include <algorithm>
#include <iostream>

template<typename T>
void selectionSort(std::vector<T>& values) {
    size_t size = values.size();
    for(int i = 0; i < size - 1; ++i) {
        T& cur_element = values[i];
        T& min_element = *std::min_element(
            values.begin() + i,
            values.end()
        );
        if(&cur_element != &min_element) {
            std::swap(cur_element, min_element);
        }
    }
}

int main() {
    std::vector<int> example = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    selectionSort(example);

    for(int x: example) {
        std::cout << x << ',';        
    }
}