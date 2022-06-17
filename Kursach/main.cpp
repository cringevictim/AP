//Program:"SortingAlgorithms"
//Developer:Nikolaiev Roman Yurievich
//Date: 10/06/22
//Purpose:Data sorting and complexity proving
//Limits:Not recommended to use arrays longer than 10^8 elements


#include <iostream>
#include <vector>
#include <ctime>
#include "SortingAlgorithms.h"
#include "SortData.h"
#include "ArrayMethods.h"

int main()
{
    srand(time(nullptr));
    int limit = 10^7;
    std::vector<int> array;
    std::string fileName;
    clock_t startTime, endTime;
    float fullTime;
    int amount = 20;
    int choice = 99;
    while(choice){
        std::cout << "0.Exit;"
                     "\n1.Fill array with random numbers;"
                     "\n2.Fill array from file;"
                     "\n3.Fill array manually;"
                     "\n4.Sort array using QuickSort;"
                     "\n5.Sort array using MergeSort;"
                     "\n6.Sort array using HeapSort;"
                     "\n7.Print array;"
                     "\n8.Generate data file;"
                     "\n9.Save array in file;" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cin >> choice;
        switch(choice){
            case 1:
                std::cout << "Enter amount: ";
                std::cin >> amount;
                am::fillVecRandomInt(array, amount);
                std::cout << "Array filled successfully;" << std::endl;
                break;
            case 2:
                std::cout << "Enter name of file: ";
                std::cin >> fileName;
                am::fillFromFile(array, fileName);
                break;
            case 3:
                std::cout << "Enter amount: ";
                std::cin >> amount;
                am::fillManually(array, amount);
                std::cout << "Array filled successfully;" << std::endl;
                break;
            case 4:
                startTime = clock();
                sa::quickSort(array);
                endTime = clock();
                fullTime += (float(endTime - startTime)) / CLOCKS_PER_SEC;
                std::cout << "Time: " << fullTime << std::endl;
                std::cout << "Array sorted successfully;" << std::endl;
                break;
            case 5:
                startTime = clock();
                sa::mergeSort(array);
                endTime = clock();
                fullTime += (float(endTime - startTime)) / CLOCKS_PER_SEC;
                std::cout << "Time: " << fullTime << std::endl;
                std::cout << "Array sorted successfully;" << std::endl;
                break;
            case 6:
                startTime = clock();
                sa::heapSort(array);
                endTime = clock();
                fullTime += (float(endTime - startTime)) / CLOCKS_PER_SEC;
                std::cout << "Time: " << fullTime << std::endl;
                std::cout << "Array sorted successfully;" << std::endl;
                break;
            case 7:
                am::printIntVec(array);
                break;
            case 8:
                test::getAlgorithmsData();
                break;
            case 9:
                am::saveArray(array);
                break;
            default:
                break;
        }
    }


}