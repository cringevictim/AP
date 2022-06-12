#include <iostream>
#include <vector>
#include <ctime>
#include "SortingAlgorithms.h"
#include "SortTesting.h"

void printIntVec(std::vector<int>& array){
    for(int i = 0; i < array.size(); i++) std::cout << array.at(i) << " "; std::cout << std::endl;
}

int main()
{
    srand(time(nullptr));
    std::vector<int> array;
    int amount = 20;

    std::cout << "QuickSort demonstration:\nSource:" << std::endl;
    sa::fillVecRandomInt(array, amount);
    printIntVec(array);
    sa::quickSort(array);
    std::cout << "Result:" << std::endl;
    printIntVec(array);
    std::cout << std:: endl;

    std::cout << "MergeSort demonstration:\nSource:" << std::endl;
    sa::fillVecRandomInt(array, amount);
    printIntVec(array);
    sa::mergeSort(array);
    std::cout << "Result:" << std::endl;
    printIntVec(array);
    std::cout << std:: endl;

    std::cout << "HeapSort demonstration:\nSource:" << std::endl;
    sa::fillVecRandomInt(array, amount);
    printIntVec(array);
    sa::heapSort(array);
    std::cout << "Result:" << std::endl;
    printIntVec(array);
    std::cout << "----------------------" <<std:: endl;

    test::testSortingAlgorythms();
}