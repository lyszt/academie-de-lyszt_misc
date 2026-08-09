#include <vector>
#include <stdlib.h>
#include <iostream>

int binary_search(std::vector<int> array, int n) {

}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> main_array;
    main_array.resize(n);

    for(int i = 0; i < n; i++) {
        std:: cin >> main_array[i];
    }

    std::vector<std::vector<int>> subarrays;
    subarrays.resize(k);
    int elements = main_array.size() / k;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < elements; j++) {
            subarrays[i][j] = main_array[j];
        }
    }

    return 0;
}