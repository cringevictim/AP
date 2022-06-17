#include <iostream>
#include "SortingAlgorithms.h"

void quickSortCall(std::vector<int> &array, int pos1, int pos2) {
    {
        int i = pos1;
        int j = pos2;
        int base = array.at((i + j) / 2);
        int temp;

        while (i <= j) {
            while (array.at(i) < base)
                i++;
            while (array.at(j) > base)
                j--;
            if (i <= j) {
                temp = array.at(i);
                array.at(i) = array.at(j);
                array.at(j) = temp;
                i++;
                j--;
            }
        }
        if (j > pos1)
            quickSortCall(array, pos1, j);
        if (i < pos2)
            quickSortCall(array, i, pos2);
    }
}

void merge(std::vector<int> &array, int pos1, int pos2)
{
    int i = pos1,
            t = 0,
            mid = pos1 + (pos2 - pos1) / 2,
            j = mid + 1,
            d[array.size()];
    while(i <= mid && j <= pos2){
        if(array.at(i) <= array.at(j)) {
            d[t] = array.at(i); i++;
        }
        else{
            d[t] = array.at(j); j++;
        }
        t++;
    }
    while(i <= mid){
        d[t] = array.at(i); i++; t++;
    }
    while(j <= pos2){
        d[t] = array.at(j); j++; t++;
    }
    for(i = 0; i < t; i++) array.at(pos1 + i) = d[i];
}

void mergeSortCall(std::vector<int> &array, int pos1, int pos2)
{
    int temp;
    if (pos1 < pos2)
        if (pos2 - pos1 == 1) {
            if (array.at(pos2) < array.at(pos1)){
                temp = array.at(pos1);
                array.at(pos1) = array.at(pos2);
                array.at(pos2) = temp;
            }
        }
        else {
            mergeSortCall(array, pos1, pos1 + (pos2 - pos1) / 2);
            mergeSortCall(array, pos1 + (pos2 - pos1) / 2 + 1, pos2);
            merge(array, pos1, pos2);
        }

}

void sa::quickSort(std::vector<int> &array) {
    quickSortCall(array, 0, array.size()-1);
}

void sa::mergeSort(std::vector<int> &array) {
    mergeSortCall(array, 0, array.size()-1);
}

void heapify(std::vector<int> &array, int i, int size)
{
    int largest, l = (2*i) + 1, r = l + 1;
    if(l < size && array.at(l) > array.at(i))
        largest = l;
    else
        largest = i;
    if(r < size && array.at(r) > array.at(largest))
        largest = r;
    if(largest != i)
    {
        std::swap(array.at(i), array.at(largest));
        heapify(array, largest, size);
    }
}


void sa::heapSort(std::vector<int> &array) {
    for(int i = (array.size() / 2); i >= 0; i--)
        heapify(array, i, array.size());
    int sz = array.size();
    for(int i = array.size() - 1; i > 0; i--)
    {
        std::swap(array[0], array[i]);
        sz--;
        heapify(array, 0, sz);
    }
}


