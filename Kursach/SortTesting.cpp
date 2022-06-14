#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>
#include "ArrayMethods.h"
#include "SortTesting.h"
#include "SortingAlgorithms.h"

bool inRange(float x, float low, float high)
{
    return (low <= x && x <= high);
}

float getTimeQuickSort(std::vector<int> &array, int amount, int times){
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

float getTimeMergeSort(std::vector<int> &array, int amount, int times){
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

float getTimeHeapSort(std::vector<int> &array, int amount, int times){
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

void test::testSortingAlgorithms() {
    std::vector<int> toSort, toCompareWith;
    bool isPassed = true;
    int times = 100, amount = 1000, reps = 10;
    float tmp[reps], time[reps];
    std::cout << "Algorithms complexity validation:" << std::endl;
    std::cout << "QuickSort testing..." << std::endl;
    for(int i = 0; i < reps; i++){
        amount *= 1.2;
        tmp[i] = amount*log(amount);
        time[i] = getTimeQuickSort(toSort, amount, times);
        if(i > 0 && !inRange(tmp[i]/time[i], tmp[i-1]/time[i-1]*0.95, tmp[i-1]/time[i-1]*1.05)){
            isPassed = false;
            break;
        }
        //std::cout << tmp[i]/time[i] << std::endl;
    }
    if(isPassed){
        std::cout << "Test passed: QuickSort average complexity is O(nlog(n))." << std::endl;
    } else std::cout << "QuickSort test failed." << std::endl;

    std::cout << "\nMergeSort testing..." << std::endl;
    amount = 1000;
    for(int i = 0; i < reps; i++){
        amount *= 1.2;
        tmp[i] = amount*log(amount);
        time[i] = getTimeMergeSort(toSort, amount, times);
        if(i > 0 && !inRange(tmp[i]/time[i], tmp[i-1]/time[i-1]*0.95, tmp[i-1]/time[i-1]*1.05)){
            isPassed = false;
            break;
        }
        //std::cout << tmp[i]/time[i] << std::endl;
    }
    if(isPassed){
        std::cout << "Test passed: MergeSort average complexity is O(nlog(n))." << std::endl;
    } else std::cout << "MergeSort test failed." << std::endl;

    std::cout << "\nHeapSort testing..." << std::endl;
    amount = 1000;
    for(int i = 0; i < reps; i++){
        amount *= 1.2;
        tmp[i] = amount*log(amount);
        time[i] = getTimeHeapSort(toSort, amount, times);
        if(i > 0 && !inRange(tmp[i]/time[i], tmp[i-1]/time[i-1]*0.95, tmp[i-1]/time[i-1]*1.05)){
            isPassed = false;
            break;
        }
        //std::cout << tmp[i]/time[i] << std::endl;
    }
    if(isPassed){
        std::cout << "Test passed: HeapSort average complexity is O(nlog(n))." << std::endl;
    } else std::cout << "HeapSort test failed." << std::endl;
}

void test::demSortingAlgorithms(int amount){
    std::vector<int> array;
    clock_t endTime, startTime;
    float fullTime;

    std::cout << "QuickSort demonstration:\nSource:" << std::endl;
    am::fillVecRandomInt(array, amount);
    am::printIntVec(array);
    startTime = clock();
    sa::quickSort(array);
    endTime = clock();
    fullTime += (float(endTime - startTime)) / CLOCKS_PER_SEC;
    std::cout << "Time: " << fullTime << std::endl;
    std::cout << "Result:" << std::endl;
    am::printIntVec(array);
    std::cout << std:: endl;

    std::cout << "MergeSort demonstration:\nSource:" << std::endl;
    am::fillVecRandomInt(array, amount);
    am::printIntVec(array);
    startTime = clock();
    sa::mergeSort(array);
    endTime = clock();
    fullTime += (float(endTime - startTime)) / CLOCKS_PER_SEC;
    std::cout << "Time: " << fullTime << std::endl;
    std::cout << "Result:" << std::endl;
    am::printIntVec(array);
    std::cout << std:: endl;

    std::cout << "HeapSort demonstration:\nSource:" << std::endl;
    am::fillVecRandomInt(array, amount);
    am::printIntVec(array);
    startTime = clock();
    sa::heapSort(array);
    endTime = clock();
    fullTime += (float(endTime - startTime)) / CLOCKS_PER_SEC;
    std::cout << "Time: " << fullTime << std::endl;
    std::cout << "Result:" << std::endl;
    am::printIntVec(array);
    std::cout << "----------------------" <<std:: endl;

}