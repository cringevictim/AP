#pragma once
#include <vector>

namespace sa{
    void quickSort(std::vector<int>& array);

    void mergeSort(std::vector<int>& array);

    void heapSort(std::vector<int>& array);

    void fillVecRandomInt(std::vector<int>& array, int amount);
}