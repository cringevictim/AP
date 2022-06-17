#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include "ArrayMethods.h"
#include "SortData.h"
#include "SortingAlgorithms.h"

float getTimeQuickSort(int amount, int times){
    std::vector<int> array;
    float fullTime = 0;
    for(int i = 0; i < times; i++){
        am::fillVecRandomInt(array, amount);
        clock_t startTime = clock();
        sa::quickSort(array);
        clock_t endTime = clock();
        fullTime += (float(endTime - startTime)) / CLOCKS_PER_SEC;
    }
    return fullTime;
}

float getTimeMergeSort(int amount, int times){
    std::vector<int> array;
    float fullTime = 0;
    for(int i = 0; i < times; i++){
        am::fillVecRandomInt(array, amount);
        clock_t startTime = clock();
        sa::mergeSort(array);
        clock_t endTime = clock();
        fullTime += (float(endTime - startTime)) / CLOCKS_PER_SEC;
    }
    return fullTime;
}

float getTimeHeapSort(int amount, int times){
    std::vector<int> array;
    float fullTime = 0;
    for(int i = 0; i < times; i++){
        am::fillVecRandomInt(array, amount);
        clock_t startTime = clock();
        sa::heapSort(array);
        clock_t endTime = clock();
        fullTime += (float(endTime - startTime)) / CLOCKS_PER_SEC;
    }
    return fullTime;
}

void test::getAlgorithmsData() {
    int reps = 10;
    int X = 100000;
    std::string fileName = "data.txt";
    std::fstream file;
    file.open(fileName, std::fstream::out);
    if(file.is_open()){
        file << "QuickSort: (format: [amount,time;])\n";
        for(int i = 0, amount = 100000; i < reps; i++, amount+=X){
            file << amount << "," << getTimeQuickSort( amount, 1) << "; ";
        }
        file << "\n\nMergeSort: (format: [amount,time;])\n";
        for(int i = 0, amount = 100000; i < reps; i++, amount+=X){
            file << amount << "," << getTimeMergeSort( amount, 1) << "; ";
        }
        file << "\n\nHeapSort: (format: [amount,time;])\n";
        for(int i = 0, amount = 100000; i < reps; i++, amount+=X){
            file << amount << "," << getTimeHeapSort( amount, 1) << "; ";
        }

    } else {
        std::cout << "Error occurred;" << std::endl;
        file.close();
        return;
    }
    std::cout << "Data file generated successfully;" << std::endl;
    file.close();
}